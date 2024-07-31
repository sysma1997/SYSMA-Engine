#include "../../Include/2D/Rectangle.h"

using namespace SYSMA::E2D;

Rectangle::Rectangle(Shader* shader) : Object{ shader } {
	init();
	glm::mat4 projection = glm::ortho(0.0f, Engine::FWidth, Engine::FHeight, 0.0f);
	shader->setMat4("projection", projection, true);
}

void Rectangle::draw() {
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