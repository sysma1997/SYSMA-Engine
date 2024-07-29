#include "../Include/Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../Libs/stb_image.h"

using namespace SYSMA;

Texture::Texture() : width{ 0 }, height{ 0 } {
	glGenTextures(1, &id);
}
Texture::Texture(std::string path, bool rgba) : width{ 0 }, height{ 0 } {
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	if (!data) {
		std::cout << "Failed to load texture: " << path << '\n';
		return;
	}
	this->width = width;
	this->height = height;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int typeRGB{ (rgba) ? GL_RGBA : GL_RGB };
	glTexImage2D(GL_TEXTURE_2D, 0, typeRGB, width, height, 0, typeRGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}
Texture::~Texture() {}

void Texture::Init() {
	stbi_set_flip_vertically_on_load(true);
}

void Texture::generate(unsigned int width, unsigned int height, unsigned char* data, bool rgba) {
	glBindTexture(GL_TEXTURE_2D, id);

	this->width = width;
	this->height = height;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int typeRGB{ (rgba) ? GL_RGBA : GL_RGB };
	glTexImage2D(GL_TEXTURE_2D, 0, typeRGB, width, height, 0, typeRGB, GL_UNSIGNED_BYTE, data);
	
	glBindTexture(GL_TEXTURE_2D, 0);
}
void Texture::bind() const {
	glBindTexture(GL_TEXTURE_2D, id);
}