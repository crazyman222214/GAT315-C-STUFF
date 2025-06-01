#include "Collision.h"
#include "raymath.h"
#include "MathUtils.h"


bool Intersects(Body* bodyA, Body* bodyB)
{
	float distance = Vector2Distance(bodyA->position, bodyB->position);
	float radius = bodyA->size + bodyB->size;

	return (distance <= radius);
}

void CreateContacts(const bodies_t& bodies, contacts_t& contacts)
{
	for (int i = 0; i < bodies.size(); i++)
	{
		Body* bodyA = bodies[i];
		for (int j = i + 1; j < bodies.size(); j++)
		{
			Body* bodyB = bodies[j];
			if (bodyA->type != Body::Type::Dynamic && bodyB->type != Body::Type::Dynamic) continue; //<both bodies are not dynamic>) continue;

			if (Intersects(bodyA, bodyB))
			{
				Contact contact;
				contact.bodyA = bodyA;
				contact.bodyB = bodyB;

				Vector2 direction = bodyB->position - bodyA->position;// <direction vector from bodyB to bodyA>;
				float distanceSqr = Vector2LengthSqr(direction);
				if (distanceSqr <= EPSILON)
				{
					direction = Vector2{ randomf(-0.05f, 0.05f), randomf(-0.05f, 0.05f) };
					distanceSqr = Vector2LengthSqr(direction);
				}

				float distance = sqrtf(distanceSqr);
				float radius = bodyA->size + bodyB->size;
				contact.depth = (radius) - distance;
				contact.normal = Vector2Normalize(direction);
				contact.restitution = (bodyA->restitution + bodyB->restitution) / 2;

				contacts.push_back(contact);
			}
		}
	}
}

void SeparateContacts(contacts_t& contacts)
{
	for (auto& contact : contacts)
	{

		float totalInverseMass = contact.bodyA->inverseMass + contact.bodyB->inverseMass; //<add inverse mass of both contact bodies>;
		Vector2 separation = contact.normal * (contact.depth / totalInverseMass);
		contact.bodyA->position = contact.bodyA->position + (separation * contact.bodyA->inverseMass);  //<contact bodyA position + (separation * contact bodyA inverse mass)>;
		contact.bodyB->position = contact.bodyB->position - (separation * contact.bodyB->inverseMass); //<contact bodyB position - (separation * contact bodyB inverse mass)>;
	}
}