#pragma once

#include <Engine.h>
#include <Scene.h>
#include <Observer.h>

#include <2D/Rectangle.h>
#include <UI/Label.h>

#include "Game/Player.h"
#include "Game/Ball.h"
#include "Game/Opponent.h"
#include "Shared/SubjectBallPosition.h"
#include "Shared/SubjectAssignPoint.h"

namespace Pong {
	class _Game : public SYSMA::Scene, public SYSMA::Observer<Shared::SubjectAssignPoint> {
		Shared::SubjectBallPosition subjectBallPosition;
		Shared::SubjectAssignPoint subjectAssignPoint;
		SYSMA::Engine& engine;
		int pointsPlayer, pointsOpponent;

		SYSMA::UI::Label* lPPlayer;
		SYSMA::UI::Label* lPOpponent;

		void load() override;

		void update(Shared::SubjectAssignPoint* subject);
	public:
		_Game(SYSMA::Engine& engine);
	};
}