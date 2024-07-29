#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../Engine.h"
#include "../Shader.h"
#include "Object.h"

namespace SYSMA {
	namespace E2D {
		class Rectangle : public Object {
		public:
			static const std::string VERT;
			static const std::string FRAG;

			Rectangle(Shader* shader);

			void draw() override;
		};
	}
}