#include "Ball.h"

using namespace SYSMA;

Pong::Ball::Ball(Scene& scene) : E2D::Circle{ Engine::GetShader("default3V") } {
	size = glm::vec2{ 100.0f };
	position = glm::vec2{ 300.0f };

	scene.addObject2D(this);
}