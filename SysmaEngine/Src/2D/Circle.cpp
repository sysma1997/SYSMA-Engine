#include "../../Include/2D/Circle.h"

using namespace SYSMA::E2D;

Circle::Circle(Shader* shader, int sides) : Object{ shader }, sides{ sides } {
	init();
	glm::mat4 projection{ glm::ortho(0.0f, Engine::FWidth, Engine::FHeight, 0.0f) };
	shader->setMat4("projection", projection, true);
}

void Circle::init() {
	float angle{ 360.0f / static_cast<float>(sides) };
	
	std::vector<glm::vec2> temp;
	for (int i{ 0 }; i < sides; i++) {
		float currentAngle{ angle * static_cast<float>(i) };
		float radian{ glm::radians(currentAngle) };
		float x{ glm::cos(radian) };
		float y{ glm::sin(radian) };
		
		temp.push_back(glm::vec2{ x, y });
	}

	for (int i{ 0 }; i < (sides - 2); i++) {
		vertices.push_back(temp[0]);
		vertices.push_back(temp[i + 1]);
		vertices.push_back(temp[i + 2]);
	}

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Circle::draw() {
	glm::mat4 model{ 1.0f };
	model = glm::translate(model, glm::vec3{ position, 0.0f });
	model = glm::rotate(model, glm::radians(rotate), glm::vec3{ 0.0f, 0.0f, 1.0f });
	model = glm::translate(model, glm::vec3{ size * -0.5f, 0.0f });
	model = glm::scale(model, glm::vec3{ size, 1.0f });

	shader->setMat4("model", model, true);
	shader->setVec3("color", color);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}