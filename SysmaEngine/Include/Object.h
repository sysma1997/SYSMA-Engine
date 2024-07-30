#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Shader.h"

namespace SYSMA {
	class Object {
	protected:
		GLuint VAO;
		Shader* shader;
	public:
		std::string name;
		glm::vec2 position, size;
		float rotate;
		glm::vec3 color;

		Object(Shader* shader);
		~Object();

		virtual void process() {}
		virtual void draw() = 0;
	};
}