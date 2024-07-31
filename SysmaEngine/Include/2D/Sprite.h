#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../Engine.h"
#include "../Shader.h"
#include "../Texture.h"
#include "../Object.h"

namespace SYSMA::E2D {
	class Sprite : public Object {
		Texture* texture;

		void init();
	public:
		static const std::string VERT;
		static const std::string FRAG;

		Sprite(Shader* shader, Texture* texture);

		void draw() override;
	};
}