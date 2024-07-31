#include "../../Include/2D/Triangle.h"

using namespace SYSMA::E2D;

Triangle::Triangle(Shader* shader) : Object{ shader } {
	init();
	glm::mat4 projection{ glm::ortho(0.0f, Engine::FWidth, Engine::FHeight, 0.0f) };
	shader->setMat4("projection", projection, true);
}

void Triangle::init() {
	float vertices[]{
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.5f, 0.0f
	};

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

void Triangle::draw() {
	glm::mat4 model{ 1.0f };
	model = glm::translate(model, glm::vec3{ position, 0.0f });
	model = glm::rotate(model, glm::radians(rotate), glm::vec3{ 0.0f, 0.0f, 1.0f });
	model = glm::translate(model, glm::vec3{ size * -0.5f, 0.0f });
	model = glm::scale(model, glm::vec3{ size, 1.0f });

	shader->setMat4("model", model, true);
	shader->setVec3("color", color);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}