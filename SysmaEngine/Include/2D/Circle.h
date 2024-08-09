#pragma once

#include <cmath>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../Engine.h"
#include "../Shader.h"
#include "../Object.h"

namespace SYSMA::E2D {
	class Circle : public Object {
		int sides;
		std::vector<glm::vec2> vertices;

		void init();
	public:
		Circle(Shader* shader, int sides);

		void draw() override;
	};
}