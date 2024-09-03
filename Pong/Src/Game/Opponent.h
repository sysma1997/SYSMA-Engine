#pragma once

#include <glm/glm.hpp>

#include <Engine.h>
#include <Observer.h>

#include <2D/Rectangle.h>

#include "../Shared/SubjectBallPosition.h"
#include "../Shared/SubjectResetGame.h"

namespace Pong::Game {
	class Opponent : public SYSMA::E2D::Rectangle, 
		public SYSMA::Observer<Shared::SubjectBallPosition>, 
		public SYSMA::Observer<Shared::SubjectResetGame> {

		void update(Shared::SubjectBallPosition* subject);
		void update(Shared::SubjectResetGame* subject);
	public:
		Opponent(SYSMA::Scene& scene, Shared::SubjectBallPosition& subject);
		~Opponent() {}
	};
}