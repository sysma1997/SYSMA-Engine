#include "Ball.h"

using namespace SYSMA;

Pong::Ball::Ball(Scene& scene) : E2D::Circle{ Engine::GetShader("default"), 14 } {
	size = glm::vec2{ Engine::GetSizeMiddle().x * 0.07f };
	position = Engine::GetSizeMiddle() - size;

	scene.addObject2D(this);
}

void Pong::Ball::process() {
	//
}