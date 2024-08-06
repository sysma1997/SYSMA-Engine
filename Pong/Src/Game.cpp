#include "Game.h"

using namespace SYSMA;

Pong::Game::Game() : pointsPlayer{ 0 }, pointsEnemy{ 0 } {}

void Pong::Game::load() {
	E2D::Rectangle* rectangle{ new E2D::Rectangle{ Engine::GetShader("default") } };
	rectangle->size = glm::vec2{ 5.0f, Engine::FHeight };
	rectangle->position = Engine::GetSizeMiddle();

	addObject2D(rectangle);
}