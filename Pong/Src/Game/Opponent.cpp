#include "Opponent.h"

using namespace SYSMA;

Pong::Game::Opponent::Opponent(Scene& scene, Pong::Shared::SubjectGame& subject) : Rectangle{ Engine::GetShader("default") } {
	name = "Opponent";
	isCheckCollision = true;
	size = Engine::GetSize() * glm::vec2{ 0.05f, 0.3f };
	position = glm::vec2{ Engine::GetSize().x - ((size.x / 2.0f) + 10.0f), Engine::GetSizeMiddle().y };

	scene.addObject2D(this);
	subject.attach(this);
}

void Pong::Game::Opponent::update(Pong::Shared::SubjectGame* subject) {
	auto method = subject->getMethod();

	switch (method) {
	case Pong::Shared::SubjectGame::Method::BALL_POSITION: {
		glm::vec2 pos{ subject->getPosition() };
		float diff{ pos.y - position.y };
		diff = (diff > 0.0f) ? 1.0f : -1.0f;

		position.y += diff * 200.0f * Engine::DeltaTime;
		position.y = glm::clamp(position.y,
			size.y / 2.0f,
			Engine::Height - (size.y / 2.0f));
	} break;
	case Pong::Shared::SubjectGame::Method::RESET_GAME:
		position = glm::vec2{ Engine::GetSize().x - ((size.x / 2.0f) + 10.0f), Engine::GetSizeMiddle().y };
		break;
	}
}