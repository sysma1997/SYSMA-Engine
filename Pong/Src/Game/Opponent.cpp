#include "Opponent.h"

using namespace SYSMA;

Pong::Game::Opponent::Opponent(Scene& scene, Pong::Shared::SubjectBallPosition& subject) : Rectangle{ Engine::GetShader("default") }, velocity{ 200.0f } {
	name = "Opponent";
	isCheckCollision = true;
	size = Engine::GetSize() * glm::vec2{ 0.05f, 0.3f };
	position = glm::vec2{ Engine::GetSize().x - ((size.x / 2.0f) + 10.0f), Engine::GetSizeMiddle().y };

	scene.addObject2D(this);
	subject.attach(this);
}

void Pong::Game::Opponent::update(Pong::Shared::SubjectBallPosition* subject) {
	glm::vec2 pos{ subject->get() };
	float diff{ pos.y - position.y };
	diff = (diff > 0.0f) ? 1.0f : -1.0f;

	position.y += diff * velocity * Engine::DeltaTime;
	position.y = glm::clamp(position.y,
		size.y / 2.0f,
		Engine::Height - (size.y / 2.0f));
}