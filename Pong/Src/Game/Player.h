#pragma once

#include <glm/glm.hpp>

#include <Engine.h>
#include <Scene.h>
#include <Input.h>
#include <Observer.h>

#include <2D/Rectangle.h>

#include "../Shared/SubjectGame.h"

namespace Pong::Game {
	class Player : public SYSMA::E2D::Rectangle, public SYSMA::Input, public SYSMA::Observer<Shared::SubjectGame> {
		SYSMA::Scene& scene;

		void isInputPress(int key, bool press) override;
		void isInputJustPress(int key) override;

		void process();

		void update(Shared::SubjectGame* subject);
	public:
		Player(SYSMA::Scene& scene);
	};
}