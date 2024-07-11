#pragma once

#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Include/File.h"

namespace SYSMA {
	class Shader {
	public:
		GLuint id;

		Shader();

		void load(std::string vertexPath, std::string fragmentPath);
		void link(std::string vertex, std::string fragment);
		
		void use();

		void setBool(const std::string& name, GLboolean value, bool useShader = false);
		void setInt(const std::string& name, GLint value, bool useShader = false);
		void setFloat(const std::string& name, GLfloat value, bool useShader = false);

		void setVec2(const std::string& name, glm::vec2 value, bool useShader = false);
		void setVec3(const std::string& name, glm::vec3 value, bool useShader = false);
		void setVec4(const std::string& name, glm::vec4 value, bool useShader = false);
		void setMat4(const std::string& name, glm::mat4 value, bool useShader = false);
	};
}