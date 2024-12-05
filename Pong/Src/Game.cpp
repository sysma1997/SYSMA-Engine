#include "Game.h"

using namespace SYSMA;

Pong::_Game::_Game(Engine& engine) : engine{ engine },
subjectGame{},
pointsPlayer{ 0 }, pointsOpponent{ 0 }, 
player{ new Pong::Game::Player{ *this } },
opponent{ new Pong::Game::Opponent{ *this, subjectGame } },
ball{ new Pong::Game::Ball{ *this, subjectGame } },
lPPlayer{ new UI::Label{Engine::GetShader("label")} },
lPOpponent{ new UI::Label{Engine::GetShader("label")} } {}

void Pong::_Game::load() {
	E2D::Rectangle* rectangle{ new E2D::Rectangle{ Engine::GetShader("default") } };
	rectangle->size = glm::vec2{ 5.0f, Engine::FHeight };
	rectangle->position = Engine::GetSizeMiddle();

	addObject2D(rectangle);


	subjectGame.attach(this);
	subjectGame.attach(player);
	subjectGame.attach(opponent);
	subjectGame.attach(ball);

	std::string font{ "Assets/Fonts/Robot_Font.otf" };
	
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
}
void Pong::_Game::reload() {
	subjectGame.reset();
}
void Pong::_Game::update(Pong::Shared::SubjectGame* subject) {
	auto method = subject->getMethod();

	switch (method) {
	case Pong::Shared::SubjectGame::Method::ASSIGN_POINT: {
		if (subject->getAssign() == Pong::Shared::SubjectGame::Assign::PLAYER)
			pointsPlayer++;
		else pointsOpponent++;

		lPPlayer->setText(std::to_string(pointsPlayer));
		lPOpponent->setText(std::to_string(pointsOpponent));

		const int maxPoints{ 0 };
		if (pointsPlayer > maxPoints || pointsOpponent > maxPoints)
			new Pong::Game::ShowWinner{ engine, *this, pointsPlayer > maxPoints, subjectGame };
	} break;
	case Pong::Shared::SubjectGame::Method::RESET_GAME:
		pointsPlayer = 0;
		pointsOpponent = 0;
		lPPlayer->setText("0");
		lPOpponent->setText("0");
		break;
	}
}