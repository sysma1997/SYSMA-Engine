#include "../../Include/2D/Sprite.h"

using namespace SYSMA::E2D;

const std::string Sprite::VERT =
	"#version 450 core\n"
	"layout(location = 0) in vec4 vertex;\n"
	"out vec2 texCoords;\n"
	"uniform mat4 projection;\n"
	"uniform mat4 model;\n"
	"void main() {\n"
	"	gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);\n"
	"	texCoords = vertex.zw;\n"
	"}";
const std::string Sprite::FRAG =
	"#version 450 core\n"
	"in vec2 texCoords;\n"
	"out vec4 color;\n"
	"uniform sampler2D image;\n"
	"uniform vec3 spriteColor;\n"
	"void main() {\n"
	"	color = vec4(spriteColor, 1.0) * texture(image, texCoords);\n"
	"}";

Sprite::Sprite(Shader* shader, Texture* texture) : Object{ shader }, texture{ texture } {
	init();
	glm::mat4 projection{ glm::ortho(0.0f, Engine::FWidth, Engine::FHeight, 0.0f) };
	shader->setMat4("projection", projection, true);
}

void Sprite::init() {
	float vertices[]{
		// pos      // tex
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Sprite::draw() {
	glm::mat4 model{ 1.0f };
	model = glm::translate(model, glm::vec3{ position, 0.0f });
	model = glm::rotate(model, glm::radians(rotate), glm::vec3{ 0.0f, 0.0f, 1.0f });
	model = glm::translate(model, glm::vec3{ size * -0.5f, 0.0f });
	model = glm::scale(model, glm::vec3{ size, 1.0f });

	shader->setMat4("model", model, true);
	shader->setVec3("spriteColor", color);
	texture->bind();

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}