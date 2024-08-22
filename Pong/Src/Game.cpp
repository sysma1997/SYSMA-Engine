#include "Game.h"

using namespace SYSMA;

Pong::_Game::_Game(Engine& engine) : engine{ engine },
subjectBallPosition{}, subjectAssignPoint{},
pointsPlayer{ 0 }, pointsEnemy{ 0 } {}

void Pong::_Game::load() {
	E2D::Rectangle* rectangle{ new E2D::Rectangle{ Engine::GetShader("default") } };
	rectangle->size = glm::vec2{ 5.0f, Engine::FHeight };
	rectangle->position = Engine::GetSizeMiddle();

	addObject2D(rectangle);

	new Pong::Game::Player{ *this };
	new Pong::Game::Opponent{ *this, subjectBallPosition };
	new Pong::Game::Ball{ *this, subjectBallPosition, subjectAssignPoint };
}
void Pong::_Game::update(Pong::Shared::SubjectAssignPoint* subject) {
	if (subject->get() == Pong::Shared::SubjectAssignPoint::PLAYER)
		pointsPlayer++;
	else pointsEnemy++;
}