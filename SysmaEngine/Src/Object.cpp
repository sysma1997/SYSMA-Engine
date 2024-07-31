#include "../Include/Object.h"

using namespace SYSMA;

const std::string Object::VERT =
"#version 450 core\n"
"layout(location = 0) in vec2 vertex;\n"
"uniform mat4 projection;\n"
"uniform mat4 model;\n"
"void main() {\n"
"    gl_Position = projection * model * vec4(vertex, 0.0, 1.0);\n"
"}";
const std::string Object::FRAG =
"#version 450 core\n"
"out vec4 fragColor;\n"
"uniform vec3 color;\n"
"void main() {\n"
"    fragColor = vec4(color, 1.0);\n"
"}";

Object::Object(Shader* shader) :  
	VAO{ 0 }, VBO{ 0 }, 
	shader{ shader },
	position{ 1.0f }, size{ 1.0f },
	rotate{ 0.0f },
	color{ 1.0f } { }
Object::~Object() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Object::init() {
	float vertices[]{
		// pos
		0.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
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