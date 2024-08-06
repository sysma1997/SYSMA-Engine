#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../Engine.h"
#include "../Shader.h"
#include "../Object.h"

namespace SYSMA::E2D {
	class Circle : public Object {
		void init();
	public:
		Circle(Shader* shader);

		void draw() override;
	};
}