#pragma once

#include <glm/glm.hpp>

#include <Engine.h>
#include <Scene.h>
#include <Input.h>

#include <2D/Rectangle.h>

namespace Pong::Game {
	class Player : public SYSMA::E2D::Rectangle, public SYSMA::Input {
		SYSMA::Scene& scene;
		float velocity;

		void isInputPress(int key, bool press) override;
		void isInputJustPress(int key) override;
	public:
		Player(SYSMA::Scene& scene);
	};
}