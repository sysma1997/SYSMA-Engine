#pragma once

#include <glm/glm.hpp>

#include <Engine.h>
#include <Signal.h>
#include <Emit.h>

#include <2D/Rectangle.h>

namespace Pong {
	class Opponent : public SYSMA::E2D::Rectangle, SYSMA::Signal<const glm::vec2&> {
		float velocity;

		void received(const glm::vec2& position);
	public:
		Opponent(SYSMA::Scene& scene, SYSMA::Emit<const glm::vec2&> emit);
	};
}