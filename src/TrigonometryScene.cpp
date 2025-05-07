#include "TrigonometryScene.h"
#include "raymath.h"

void TrigonometryScene::Initialize()
{
	m_camera = new SceneCamera({m_width / 2.0f, m_height / 2.0f});

}

void TrigonometryScene::Update()
{
}

float DegToRad(float degrees)
{
	return degrees * (PI / 180.0f);
}

float RadToDeg(float radians)
{
	return radians * (180.0f / PI);
}

Vector2 Normalize(Vector2& v)
{
	float length = Vector2Length(v);
	if (length == 0) return { 0, 0 };
	return { v.x / length, v.y / length };
}

void TrigonometryScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, WHITE);

	//DrawCircle(Vector2{ 0,0 }, 1, BLUE);


	//Circle
	int steps = 50;
	float radius = 3;

	float rate = 0.5f;
	float time = (float)GetTime() * rate;



	for (int i = 0; i < steps; i++)
	{
		float theta = time + (2 * PI * (i / (float)steps));

		float x = cosf(theta) * radius;
		float y = sinf(theta) * radius;

		DrawCircle(Vector2{ x, y }, 0.25f, RED);
	}



	//SIN / COS
	for (float x = -9.0f; x < 9.0f; x += 0.2f)
	{
		float theta = time + ( 2 * PI * (x / 18.0f) );
		float c = cosf(theta) * radius;
		float s = sinf(theta) * radius;
		//float y = sin(theta) * radius;

		DrawCircle(Vector2{ x, c }, 0.25f, GREEN);
		DrawCircle(Vector2{ x, s }, 0.25f, BLUE);
	}


	float theta = time;

	float x = cos(theta) * radius;
	float y = sin(theta) * radius;

	DrawCircle(Vector2{ x, y }, 0.25f, YELLOW);




	m_camera->EndMode();
}

void TrigonometryScene::DrawGUI()
{
}
