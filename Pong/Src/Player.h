#pragma once

#include <glm/glm.hpp>

#include <Engine.h>
#include <Scene.h>
#include <Input.h>

#include <2D/Rectangle.h>

namespace Pong {
	class Player : public SYSMA::E2D::Rectangle, public SYSMA::Input {
		float velocity;

		void isInputPress(int key, bool press) override;
	public:
		Player(SYSMA::Scene& scene);
	};
}