#include "../../Include/2D/Rectangle.h"

using namespace SYSMA;
using namespace E2D;

const std::string Rectangle::VERT = 
	"#version 450 core\n"
	"layout(location = 0) in vec2 vertex;\n"
	"uniform mat4 projection;\n"
	"uniform mat4 model;\n"
	"void main() {\n"
	"    gl_Position = projection * model * vec4(vertex, 0.0, 1.0);\n"
	"}";
const std::string Rectangle::FRAG = 
	"#version 450 core\n"
	"out vec4 fragColor;\n"
	"uniform vec3 color;\n"
	"void main() {\n"
	"    fragColor = vec4(color, 1.0);\n"
	"}";

Rectangle::Rectangle(Shader* shader) : Object{ shader } {}

void Rectangle::draw() {
	glm::mat4 projection = glm::ortho(0.0f, Engine::FWidth, Engine::FHeight, 0.0f);

	glm::mat4 model{ 1.0f };
	model = glm::translate(model, glm::vec3{ position, 0.0f });
	model = glm::rotate(model, glm::radians(rotate), glm::vec3{ 0.0f, 0.0f, 1.0f });
	model = glm::translate(model, glm::vec3{ size * -0.5f, 0.0f });
	model = glm::scale(model, glm::vec3{ size, 1.0f });

	shader->setMat4("projection", projection, true);
	shader->setMat4("model", model);
	shader->setVec3("color", color);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}