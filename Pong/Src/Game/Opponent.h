#pragma once

#include <glm/glm.hpp>

#include <Engine.h>
#include <Observer.h>

#include <2D/Rectangle.h>

#include "../Shared/SubjectBallPosition.h"

namespace Pong::Game {
	class Opponent : public SYSMA::E2D::Rectangle, public SYSMA::Observer<Shared::SubjectBallPosition> {
		float velocity;

		void update(Shared::SubjectBallPosition* subject);
	public:
		Opponent(SYSMA::Scene& scene, Shared::SubjectBallPosition& subject);
		~Opponent() {}
	};
}