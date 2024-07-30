#pragma once

#include <string>
#include <map>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Engine.h"
#include "../Shader.h"
#include "../Object.h"

namespace SYSMA {
	namespace UI {
		class Label : public Object {
		private:
			struct Character {
				GLuint id;
				glm::ivec2 size;
				glm::ivec2 bearing;
				unsigned int advance;
			};

			GLuint VBO;
			std::map<char, Character> characters;
			std::string text;

			void init();
			glm::vec2 getSizeText(std::string text, float scale);
		public:
			enum Aling { LEFT, CENTER, RIGHT };

			static const std::string VERT;
			static const std::string FRAG;

			float scale;
			Aling align;

			Label(Shader* shader);
			Label(Shader* shader, std::string path, int fontSize);

			void loadFond(std::string path, int fontSize);
			void setText(std::string text);
			void draw() override;
		};
	}
}