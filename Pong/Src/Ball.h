#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glm/glm.hpp>

#include <Engine.h>
#include <Scene.h>
#include <Emit.h>

#include <2D/Circle.h>

namespace Pong {
	class Ball : public SYSMA::E2D::Circle {
		SYSMA::Emit<const glm::vec2&> emit;
		bool isCollition;
		float seconds;
		float velocity;
		glm::vec2 direction;

		void process() override;
		void isCollision(SYSMA::Object& object) override;
	public:
		Ball(SYSMA::Scene& scene, SYSMA::Emit<const glm::vec2&> emit);
	};
}