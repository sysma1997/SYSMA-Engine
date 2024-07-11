#include "../../Include/2D/Object.h"

using namespace SYSMA;
using namespace E2D;

Object::Object(std::string name, Shader* shader) : 
	name{ name }, 
	VAO{ 0 },
	shader{ shader },
	position{ 1.0f }, size{ 1.0f },
	rotate{ 0.0f },
	color{ 1.0f } {
	float vertices[]{
		// pos
		0.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};

	GLuint VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
Object::~Object() {
	glDeleteVertexArrays(1, &VAO);
}