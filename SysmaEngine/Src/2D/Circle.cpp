#include "../../Include/2D/Circle.h"

using namespace SYSMA::E2D;

Circle::Circle(Shader* shader) : Object{ shader } {
	init();
	glm::mat4 projection{ glm::ortho(0.0f, Engine::FWidth, Engine::FHeight, 0.0f) };
	shader->setMat4("projection", projection, true);
}

void Circle::init() {
	std::vector<glm::vec3> vertices;

	//float radio{ 1.0f };
	//int count{ 8 };
	//float angle{ 360.0f / static_cast<float>(count) };
	//int triangleCount{ count - 2 };
	//
	//std::vector<glm::vec3> temp;
	//for (int i{ 0 }; i < count; i++) {
	//	float angleCurrent{ angle * static_cast<float>(i) };
	//	float x{ radio * cos(glm::radians(angleCurrent)) };
	//	float y{ radio * sin(glm::radians(angleCurrent)) };
	//	float z{ 0.0f };
	//
	//	temp.push_back(glm::vec3{ x, y, z });
	//}
	//
	//for (int i{ 0 }; i < triangleCount; i++) {
	//	vertices.push_back(temp[i]);
	//	vertices.push_back(temp[i + 1]);
	//	vertices.push_back(temp[i + 2]);
	//}

	int sides{ 100 };
	float radio{ 1.0f };
	float PI2{ glm::pi<float>() * 2 };
	float increment{ PI2 / static_cast<float>(sides) };

	for (float angle{ 0.0f }; angle <= PI2; angle += increment) {
		glm::vec3 vertice{
			radio * cos(angle),
			radio * sin(angle),
			0.0f
		};
		vertices.push_back(vertice);
	}

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
	glEnableVertexAttribArray(0);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
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
	glDrawArrays(GL_TRIANGLES, 0, 6);
}