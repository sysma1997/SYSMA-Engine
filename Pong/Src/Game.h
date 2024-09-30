#pragma once

#include <Engine.h>
#include <Scene.h>
#include <Observer.h>

#include <2D/Rectangle.h>
#include <UI/Label.h>

#include "Game/Player.h"
#include "Game/Ball.h"
#include "Game/Opponent.h"
#include "Game/ShowWinner.h"
#include "Shared/SubjectGame.h"

namespace Pong {
	class _Game : public SYSMA::Scene, 
		public SYSMA::Observer<Shared::SubjectGame> {
		Shared::SubjectGame subjectGame;
		SYSMA::Engine& engine;
		int pointsPlayer, pointsOpponent;

		SYSMA::UI::Label* lPPlayer;
		SYSMA::UI::Label* lPOpponent;

		void load() override;

		void update(Shared::SubjectGame* subject);
	public:
		_Game(SYSMA::Engine& engine);
	};
}