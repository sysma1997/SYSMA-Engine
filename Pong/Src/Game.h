#pragma once

#include <Engine.h>
#include <Scene.h>

#include <2D/Rectangle.h>

#include "Player.h"
#include "Ball.h"

namespace Pong {
	class Game : public SYSMA::Scene {
		SYSMA::Engine& engine;
		int pointsPlayer, pointsEnemy;

		void load() override;

	public:
		Game(SYSMA::Engine& engine);
	};
}