#pragma once

#include <string>
#include <map>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Shader.h"

namespace SYSMA {
	namespace UI {
		class Label {
		private:
			struct Character {
				GLuint id;
				glm::ivec2 size;
				glm::ivec2 bearing;
				unsigned int advance;
			};

			GLuint VAO, VBO;

			glm::vec2 getSizeText(std::string text, float scale);
		public:
			static const std::string VERT;
			static const std::string FRAG;

			std::map<char, Character> characters;
			Shader* shader;

			Label(Shader* shader);
			Label(Shader* shader, std::string path, int fontSize);

			void loadFond(std::string path, int fontSize);
			void render(std::string text, glm::vec2 position,
				float scale = 1.0f, glm::vec2 color = glm::vec3{ 1.0f });
		};
	}
}