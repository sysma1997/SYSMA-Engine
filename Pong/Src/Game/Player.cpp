#include "Player.h"

using namespace SYSMA;

Pong::Game::Player::Player(Scene& scene) : E2D::Rectangle{ Engine::GetShader("default") }, scene{ scene }, velocity{ 350.0f }, pause{ false } {
	scene.addInput(this);

	name = "player";
	isCheckCollision = true;
	size = Engine::GetSize() * glm::vec2{ 0.05f, 0.3f };
	position = glm::vec2{ 10.0f + (size.x / 2.0f), Engine::GetSizeMiddle().y };

	scene.addObject2D(this);
}

void Pong::Game::Player::isInputPress(int key, bool isPress) {
	if (!isPress) return;

	if (key == GLFW_KEY_UP)
		position.y -= velocity * Engine::DeltaTime;
	if (key == GLFW_KEY_DOWN)
		position.y += velocity * Engine::DeltaTime;

	position.y = glm::clamp(position.y, size.y / 2.0f, Engine::FHeight - (size.y / 2.0f));
}
void Pong::Game::Player::isInputJustPress(int key) {
	if (key == GLFW_KEY_ESCAPE) {
		pause = !pause;
		scene.isPause(pause);
	}
}