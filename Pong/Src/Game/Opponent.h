#pragma once

#include <glm/glm.hpp>

#include <Engine.h>
#include <Observer.h>

#include <2D/Rectangle.h>

#include "../Shared/SubjectGame.h"

namespace Pong::Game {
	class Opponent : public SYSMA::E2D::Rectangle, 
		public SYSMA::Observer<Shared::SubjectGame> {

		void update(Shared::SubjectGame* subject);
	public:
		Opponent(SYSMA::Scene& scene, Shared::SubjectGame& subject);
		~Opponent() {}
	};
}