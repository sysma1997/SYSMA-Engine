#include "Player.h"

using namespace SYSMA;

Pong::Player::Player(Scene& scene) : E2D::Rectangle{ Engine::GetShader("default") }, MOVE{ 350.0f } {
	scene.addInput(this);

	size = Engine::GetSize() * glm::vec2{ 0.05f, 0.3f };
	position = glm::vec2{ 10.0f + (size.x / 2.0f), Engine::GetSizeMiddle().y };

	scene.addObject2D(this);
}

void Pong::Player::isInputPress(int key, bool isPress) {
	if (!isPress) return;

	if (key == GLFW_KEY_UP)
		position.y -= MOVE * Engine::DeltaTime;
	if (key == GLFW_KEY_DOWN)
		position.y += MOVE * Engine::DeltaTime;

	position.y = glm::clamp(position, glm::vec2{ position.x, (size.y / 2.0f) }, glm::vec2{ position.x, Engine::FHeight - (size.y / 2.0f) }).y;
}