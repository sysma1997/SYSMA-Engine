#include "Ball.h"

using namespace SYSMA;

Pong::Ball::Ball(Scene& scene, Emit<const glm::vec2&> emit) : E2D::Circle{ Engine::GetShader("default"), 14 }, emit{emit}, isCollition{false}, seconds{0.0f}, velocity{300.0f} {
	srand(time(NULL));
	name = "ball";
	isCheckCollision = true;
	size = glm::vec2{ Engine::GetSizeMiddle().x * 0.07f };
	position = Engine::GetSizeMiddle();

	direction = glm::vec2{
		((rand() % 2) == 0) ? -1.0f : 1.0f,
		((rand() % 2) == 0) ? -1.0f : 1.0f
	};

	scene.addObject2D(this);
}

void Pong::Ball::process() {
	if (isCollition) {
		seconds += Engine::DeltaTime;
		if (seconds > 0.2f) {
			isCollition = false;
			seconds = 0.0f;
		}
	}

	position += direction * velocity * Engine::DeltaTime;
	
	if (!isCollition && 
		position.x > Engine::GetSize().x - (size.x / 2.0f)) {
		isCollition = true;
		direction.x *= -1.0f;
	}
	if (!isCollition && 
		(position.y < size.y || 
		position.y > Engine::GetSize().y - (size.y / 2.0f))) {
		isCollition = true;
		direction.y *= -1.0f;
	}

	emit.emit("ballPosition", position);
}
void Pong::Ball::isCollision(Object& object) {
	isCollition = true;
	direction.x *= -1.0f;
}