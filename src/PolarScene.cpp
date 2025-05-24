#include "PolarScene.h"
#include "raymath.h"

#include <cmath>
#include <corecrt_math_defines.h>

void PolarScene::Initialize()
{
	m_camera = new SceneCamera({ m_width / 2.0f, m_height / 2.0f });

}



void PolarScene::Update()
{
}


void PolarScene::Draw()
{
	m_camera->BeginMode();

	//DrawGrid(10, 5, WHITE);

	//ArchimedianSpiral(0.25f, 0.4f);
	//Cardioid(2);
	//Limacon(2, 3);
	//RoseCurve(4, 5);

	Logarithmic(1, 0.1f);
	m_camera->EndMode();
}



void PolarScene::DrawGUI()
{
}

void PolarScene::ArchimedianSpiral(float a, float b)
{
	int steps = 500;

	float rate = 0.5f;
	float time = (float)GetTime() * rate;

	Vector2 prev = { 0, 0 };

	for (int i = 0; i < steps; i++)
	{
		float theta = 4 * PI * (i / (float)steps);
		float r = a + b * theta;

		float x = cosf(theta) * r;
		float y = sinf(theta) * r;

		if (i == 0) prev = { x, y };

		Color color = Color{ (unsigned char)(x * 5), (unsigned char)((x + 10) * 10), (unsigned char)((x + 10) * 20), 255 };


		DrawLine(prev, { x, y }, 5, color);
		prev = { x, y };
	}
}


void PolarScene::Cardioid(float a)
{
	int steps = 500;

	float rate = 0.5f;
	float time = (float)GetTime() * rate;

	Vector2 prev = { 0, 0 };

	for (int i = 0; i < steps; i++)
	{
		float theta = 4 * PI * (i / (float)steps);

		float r = a * (1 + cos(theta));

		float x = cosf(theta) * r;
		float y = sinf(theta) * r;
			
		if (i == 0) prev = { x, y };

		Color color = Color{ (unsigned char)(x  * 5), (unsigned char)((x + 10) * 10), (unsigned char)((x + 10) * 20), 255 };



		DrawLine(prev, { x, y }, 5, color);
		prev = { x, y };
	}
}

void PolarScene::Limacon(float a, float b)
{
	int steps = 500;

	float rate = 0.5f;
	float time = (float)GetTime() * rate;

	Vector2 prev = { 0, 0 };

	for (int i = 0; i < steps; i++)
	{
		float theta = 4 * PI * (i / (float)steps);

		float r = a + b * cos(theta);

		float x = cosf(theta) * r;
		float y = sinf(theta) * r;

		if (i == 0) prev = { x, y };

		Color color = Color{ (unsigned char)(x * 5), (unsigned char)((x + 10) * 10), (unsigned char)((x + 10) * 20), 255 };


		DrawLine(prev, { x, y }, 5, color);
		prev = { x, y };
	}

}

void PolarScene::RoseCurve(float a, float k)
{
	int steps = 500;

	float rate = 0.5f;
	float time = (float)GetTime() * rate;

	Vector2 prev = { 0, 0 };

	for (int i = 0; i < steps; i++)
	{
		float theta = 4 * PI * (i / (float)steps);
		float r = a * cos(k * theta);

		float x = cosf(theta) * r;
		float y = sinf(theta) * r;

		if (i == 0) prev = { x, y };

		Color color = Color{ (unsigned char)(x * 5), (unsigned char)((x + 10) * 10), (unsigned char)((x + 10) * 20), 255 };

		DrawLine(prev, { x, y }, 5, color);
		prev = { x, y };
	}

}


// r = a * e^(b * theta)
void PolarScene::Logarithmic(float a, float k)
{
	int steps = 500;

	float rate = 0.5f;
	float time = (float)GetTime() * rate;

	Vector2 prev = { 0, 0 };

	for (int i = 0; i < steps; i++)
	{
		float theta = 4 * PI * (i / (float)steps);
		float r = a * powf(M_E, k * theta);

		float x = cosf(theta) * r;
		float y = sinf(theta) * r;

		if (i == 0) prev = { x, y };

		Color color = Color{ (unsigned char)(x * 5), (unsigned char)((x + 10) * 10), (unsigned char)((x + 10) * 20), 255 };

		DrawLine(prev, { x, y }, 5, color);
		prev = { x, y };
	}

}

void PolarScene::FixedUpdate()
{
}
