#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glm/glm.hpp>

#include <Engine.h>
#include <Scene.h>
#include <Observer.h>

#include <2D/Circle.h>

#include "../Shared/SubjectGame.h"

namespace Pong::Game {
	class Ball : public SYSMA::E2D::Circle, public SYSMA::Observer<Shared::SubjectGame> {
		Shared::SubjectGame& subject;
		bool unapplyCollision;
		float seconds;
		float speed;
		glm::vec2 direction;

		void process() override;
		void isCollision(SYSMA::Object& object) override;

		void assignDirection(float leftRight = 0.0f);
		void reset(float direction);

		void update(Shared::SubjectGame* subject);
	public:
		Ball(SYSMA::Scene& scene, 
			Shared::SubjectGame& subject);
	};
}