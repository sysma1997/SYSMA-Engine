#pragma once

#include <Engine.h>
#include <Scene.h>
#include <Emit.h>

#include <2D/Rectangle.h>

#include "Player.h"
#include "Ball.h"
#include "Opponent.h"

namespace Pong {
	class Game : public SYSMA::Scene {
		SYSMA::Engine& engine;
		int pointsPlayer, pointsEnemy;
		SYSMA::Emit<const glm::vec2&> emitBallPosition;

		void load() override;

	public:
		Game(SYSMA::Engine& engine);
	};
}