#include "Game.h"

using namespace SYSMA;

Pong::_Game::_Game(Engine& engine) : engine{ engine },
subjectBallPosition{}, subjectAssignPoint{},
pointsPlayer{ 0 }, pointsOpponent{ 0 }, 
lPPlayer{new UI::Label{Engine::GetShader("label")}},
lPOpponent{ new UI::Label{Engine::GetShader("label")} } {}

void Pong::_Game::load() {
	E2D::Rectangle* rectangle{ new E2D::Rectangle{ Engine::GetShader("default") } };
	rectangle->size = glm::vec2{ 5.0f, Engine::FHeight };
	rectangle->position = Engine::GetSizeMiddle();

	addObject2D(rectangle);

	new Pong::Game::Player{ *this };
	new Pong::Game::Opponent{ *this, subjectBallPosition };
	new Pong::Game::Ball{ *this, subjectBallPosition, subjectAssignPoint };

	std::string font{"Assets/Fonts/Robot_Font.otf"};
	
	lPPlayer->loadFond(font, 40);
	lPPlayer->name = "scorePlayer";
	lPPlayer->align = UI::Label::Align::RIGHT;
	lPPlayer->setText("0");
	glm::vec2 posLabels{ Engine::GetSizeMiddle().x, lPPlayer->size.y + 5.0f };
	lPPlayer->position = posLabels - glm::vec2{ 10.0f, 0.0f };
	addUI(lPPlayer);

	lPOpponent->loadFond(font, 40);
	lPOpponent->name = "scoreOpponent";
	lPOpponent->align = UI::Label::Align::LEFT;
	lPOpponent->setText("0");
	lPOpponent->position = posLabels + glm::vec2{ 10.0f, 0.0f };
	addUI(lPOpponent);

	subjectAssignPoint.attach(this);
}
void Pong::_Game::update(Pong::Shared::SubjectAssignPoint* subject) {
	if (subject->get() == Pong::Shared::SubjectAssignPoint::PLAYER)
		pointsPlayer++;
	else pointsOpponent++;

	lPPlayer->setText(std::to_string(pointsPlayer));
	lPOpponent->setText(std::to_string(pointsOpponent));

	if (pointsPlayer > 9 || pointsOpponent > 9) {
		//
	}
}