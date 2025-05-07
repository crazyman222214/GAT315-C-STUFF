#include "VectorScene.h"
#include "Body.h"
#include "raymath.h"

float randomf()
{
	
	return (float)rand() / RAND_MAX;
}

void VectorScene::Initialize()
{
	m_camera = new SceneCamera({ m_width / 2.0f, m_height / 2.0f });
	Body* head = new Body({ 3, 0 }, { 0, 0 }, 0.25f, WHITE);

	m_head = head;
	m_player = head;
	
	for (int i = 0; i < 10; i++)
	{
		head->next = new Body({randomf() * 5 , randomf() * 5}, {0, 0}, 0.25f, ((i % 2 == 0) ? RED : BLUE));
		head->next->prev = head;
		head = head->next;
	}
	
}

void VectorScene::Update()
{
	Body* body = m_head;

	//Update the player movement
	Vector2 input{ 0, 0 };
	if (IsKeyDown(KEY_W)) input.y += 1;
	if (IsKeyDown(KEY_S)) input.y -= 1;
	if (IsKeyDown(KEY_A)) input.x -= 1;
	if (IsKeyDown(KEY_D)) input.x += 1;

	input = Vector2Normalize(input);

	m_player->velocity = input * 3;


	while (body)
	{

		if (body == m_player)
		{
			body->Step(GetFrameTime());
			body = body->next;
			continue;
		}

		Vector2 direction = m_player->position - body->position;
		direction = Vector2Normalize(direction) * 2;
		body->velocity = direction;

		body->Step(GetFrameTime());
		body = body->next;
	}
}

void VectorScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, WHITE);

	Body* body = m_head;

	while (body)
	{
		body->Draw(*this);
		body = body->next;
	}

	m_camera->EndMode();
}

void VectorScene::DrawGUI()
{
}
