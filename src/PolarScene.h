#pragma once
#pragma once
#include "scene.h"


class PolarScene : public Scene
{
public:
	PolarScene(const std::string& title, int width, int height, const Color& background = BLACK) : Scene(title, width, height, background)
	{
	}

	void Initialize() override;

	void Update() override;

	void Draw() override;

	void DrawGUI() override;

	void ArchimedianSpiral(float a, float b);
	void Cardioid(float a);
	void Limacon(float a, float b);
	void RoseCurve(float a, float b);
	void Logarithmic(float a, float b);

private:

};