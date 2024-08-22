#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glm/glm.hpp>

#include <Engine.h>
#include <Scene.h>

#include <2D/Circle.h>

#include "../Shared/SubjectBallPosition.h"
#include "../Shared/SubjectAssignPoint.h"

namespace Pong::Game {
	class Ball : public SYSMA::E2D::Circle {
		Shared::SubjectBallPosition& subjectBallPosition;
		Shared::SubjectAssignPoint& subjectAssignPoint;
		bool isCollition;
		float seconds;
		float velocity;
		glm::vec2 direction;

		void process() override;
		void isCollision(SYSMA::Object& object) override;

		void assignDirection(float leftRight = 0.0f);
		void reset(float direction);
	public:
		Ball(SYSMA::Scene& scene, 
			Shared::SubjectBallPosition& subjectBallPosition, 
			Shared::SubjectAssignPoint& subjectAssignPoint);
	};
}