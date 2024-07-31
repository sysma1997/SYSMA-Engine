#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../Engine.h"
#include "../Shader.h"
#include "../Object.h"

namespace SYSMA::E2D {
	class Rectangle : public Object {
	public:
		Rectangle(Shader* shader);

		void draw() override;
	};
}