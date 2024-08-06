#pragma once

#include <Engine.h>
#include <Scene.h>

#include <2D/Rectangle.h>

namespace Pong {
	class Game : public SYSMA::Scene {
		int pointsPlayer, pointsEnemy;

		void load() override;

	public:
		Game();
	};
}