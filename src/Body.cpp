#include "Body.h"
#include "Integrator.h"
#include "raymath.h"
#include "World.h"

void Body::Step(float dt)
{
	if (type != Type::Dynamic) return;
	force += (World::gravity * gravityScale ) * mass;
	acceleration = force * inverseMass;

	SemiImplicitIntegrator(*this, dt);
}

void Body::Draw(const Scene& scene)
{
	scene.DrawCircle(position, size, color);
	//scene.DrawLine(position - velocity, position, 2, color);

}

void Body::ApplyForce(const Vector2& force, ForceMode forceMode)
{
	switch (forceMode)
	{
	case Body::ForceMode::Force:
		this->force += force;
		break;
	case Body::ForceMode::Impulse:
		this->velocity += force * inverseMass;
		break;
	case Body::ForceMode::Velocity:
		this->velocity += force;
		break;
	default:
		break;

	}
	
}
