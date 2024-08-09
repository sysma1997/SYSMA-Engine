#pragma once

#include <glm/glm.hpp>

#include <Engine.h>
#include <Scene.h>

#include <2D/Circle.h>

namespace Pong {
	class Ball : public SYSMA::E2D::Circle {

		void process() override;
	public:
		Ball(SYSMA::Scene& scene);
	};
}