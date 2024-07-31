#pragma once

#include <Gl/glew.h>
#include <glm/glm.hpp>

#include "../Engine.h"
#include "../Object.h"

namespace SYSMA::E2D {
	class Triangle : public Object {
		void init();
	public:
		Triangle(Shader* shader);

		void draw() override;
	};
}