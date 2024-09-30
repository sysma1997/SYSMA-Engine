#include "Player.h"

using namespace SYSMA;

Pong::Game::Player::Player(Scene& scene) : E2D::Rectangle{ Engine::GetShader("default") }, scene{ scene } {
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
		velocity.y = -1.0f;
	if (key == GLFW_KEY_DOWN)
		velocity.y = 1.0f;
}
void Pong::Game::Player::isInputJustPress(int key) {
	if (key == GLFW_KEY_ESCAPE) {
		scene.isPause(!scene.isPause());
		pauseInput = false;
	}
}
void Pong::Game::Player::process() {
	position.y += velocity.y * 350.0f * Engine::DeltaTime;
	position.y = glm::clamp(position.y, size.y / 2.0f, Engine::FHeight - (size.y / 2.0f));

	velocity.y = 0.0f;
}

void Pong::Game::Player::update(Pong::Shared::SubjectGame* subject) {
	auto method = subject->getMethod();
	if (method != Pong::Shared::SubjectGame::Method::RESET_GAME) return;

	position = glm::vec2{ 10.0f + (size.x / 2.0f), Engine::GetSizeMiddle().y };
}