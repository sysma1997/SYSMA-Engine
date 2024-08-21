#include "Opponent.h"

using namespace SYSMA;

Pong::Opponent::Opponent(Scene& scene, Emit<const glm::vec2&> emit) : Rectangle{ Engine::GetShader("default") }, velocity{ 0.0f } {
	name = "Opponent";
	isCheckCollision = true;
	size = Engine::GetSize() * glm::vec2{ 0.05f, 0.3f };
	position = glm::vec2{ Engine::GetSize().x - ((size.x / 2.0f) + 10.0f), Engine::GetSizeMiddle().y };

	scene.addObject2D(this);

	emit.subscribe("ballPosition", this);
}

void Pong::Opponent::received(const glm::vec2& position) {
	std::cout << "Ball position: x = " << position.x << ", y = " << position.y << '\n';
}