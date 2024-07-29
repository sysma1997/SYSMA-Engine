#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>

namespace SYSMA {
	class Texture {
	public:
		GLuint id;
		unsigned int width;
		unsigned int height;

		Texture();
		Texture(std::string path, bool rgba = false);
		~Texture();

		void generate(unsigned int width, unsigned int height, unsigned char* data, bool rgba = false);
		void bind() const;

		static void Init();
	};
}