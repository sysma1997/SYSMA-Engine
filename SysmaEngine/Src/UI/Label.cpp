#include "../../Include/UI/Label.h"

#include <ft2build.h>
#include FT_FREETYPE_H

using namespace SYSMA;
using namespace UI;

const std::string Label::VERT =
	"#version 450 core\n"
	"layout (location = 0) in vec4 vertex;\n"
	"out vec2 TexCoords;\n"
	"uniform mat4 projection;\n"
	"void main() {\n"
	"	gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);\n"
	"	TexCoords = vertex.zw;\n"
	"}";
const std::string Label::FRAG =
	"#version 450 core\n"
	"in vec2 TexCoords;\n"
	"out vec4 color;\n"
	"uniform sampler2D text;\n"
	"uniform vec3 textColor;\n"
	"void main() {\n"
	"	vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);\n"
	"	color = vec4(textColor, 1.0) * sampled;\n"
	"}";

Label::Label(Shader* shader) : Object{ shader }, scale{ 1.0f }, align{ LEFT } {
	init();
}
Label::Label(Shader* shader, std::string path, int fontSize) : Object{ shader }, scale{ 1.0f }, align{ LEFT } {
	init();
	loadFond(path, fontSize);
}

void Label::init() {
	//glEnable(GL_CULL_FACE);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	shader->setMat4("projection", glm::ortho(0.0f, Engine::FWidth, Engine::FHeight, 0.0f), true);
	shader->setInt("text", 0);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
glm::vec2 Label::getSizeText(std::string text, float scale) {
	glm::vec2 size{ 0.0f };

	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++) {
		Character ch{ characters[*c] };

		float width{ (ch.advance >> 6) * scale };
		float height{ (ch.size.y * scale) + ((characters['H'].bearing.y - ch.bearing.y) * scale) };

		size.x += width;
		if (height > size.y)
			size.y = height;
	}

	return size;
}

void Label::loadFond(std::string path, int fontSize) {
	characters.clear();

	FT_Library ft;
	if (FT_Init_FreeType(&ft))
		std::cout << "Could not init FreeType Library" << std::endl;
	FT_Face face;
	if (FT_New_Face(ft, path.c_str(), 0, &face))
		std::cout << "Failed to load font: " << path << '\n';
	FT_Set_Pixel_Sizes(face, 0, fontSize);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	for (GLubyte c = 0; c < 128; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			std::cout << "Failed to load Glyph: " << c << '\n';
			continue;
		}

		GLuint id;
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0, GL_RED, GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Character character = {
			id,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			static_cast<unsigned int>(face->glyph->advance.x)
		};
		characters.insert(std::pair<char, Character>(c, character));
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
}
void Label::setText(std::string text) {
	this->text = text;
	size = getSizeText(text, scale);
}
void Label::draw() {
	glm::vec2 pos{ position - (size / 2.0f) };
	if (align == LEFT)
		pos.x += size.x / 2.0f;
	if (align == RIGHT) {
		pos.x -= size.x / 2.0f;
	}

	shader->setVec3("textColor", color, true);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAO);

	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch{ characters[*c] };

		float xpos{ pos.x + ch.bearing.x * scale };
		float ypos{ pos.y + (characters['H'].bearing.y - ch.bearing.y) * scale };

		float w{ ch.size.x * scale };
		float h{ ch.size.y * scale };
		float vertices[6][4]{
			{ xpos,     ypos + h,   0.0f, 1.0f },
			{ xpos + w, ypos,       1.0f, 0.0f },
			{ xpos,     ypos,       0.0f, 0.0f },

			{ xpos,     ypos + h,   0.0f, 1.0f },
			{ xpos + w, ypos + h,   1.0f, 1.0f },
			{ xpos + w, ypos,       1.0f, 0.0f }
		};

		glBindTexture(GL_TEXTURE_2D, ch.id);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		pos.x += (ch.advance >> 6) * scale;
	}

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}