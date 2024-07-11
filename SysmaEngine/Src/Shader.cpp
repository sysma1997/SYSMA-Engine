#include "../Include/Shader.h"

using namespace SYSMA;

Shader::Shader() : id{ 0 } {}

void Shader::load(std::string vertexPath, std::string fragmentPath) {
	std::string vertex{ File::GetText(vertexPath) };
	std::string fragment{ File::GetText(fragmentPath) };

	link(vertex, fragment);
}
void Shader::link(std::string vertex, std::string fragment) {
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	GLint success;
	char infoLog[512];

	char const* vertexPointer{ vertex.c_str() };
	glShaderSource(vertexShaderId, 1, &vertexPointer, NULL);
	glCompileShader(vertexShaderId);

	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
		std::cout << "Error to compile shader vertex: " << infoLog << '\n';
	}

	char const* fragmentPointer{ fragment.c_str() };
	glShaderSource(fragmentShaderId, 1, &fragmentPointer, NULL);
	glCompileShader(fragmentShaderId);

	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShaderId, 512, NULL, infoLog);
		std::cout << "Error to compile shader fragment: " << infoLog << '\n';
	}

	id = glCreateProgram();
	glAttachShader(id, vertexShaderId);
	glAttachShader(id, fragmentShaderId);
	glLinkProgram(id);

	glGetProgramiv(id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(id, 512, NULL, infoLog);
		std::cout << "Error to compile shader with program: " << infoLog << '\n';
	}

	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
}

void Shader::use() {
	glUseProgram(id);
}

void Shader::setBool(const std::string& name, GLboolean value, bool useShader) {
	if (useShader) use();
	glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}
void Shader::setInt(const std::string& name, GLint value, bool useShader) {
	if (useShader) use();
	glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}
void Shader::setFloat(const std::string& name, GLfloat value, bool useShader) {
	if (useShader) use();
	glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setVec2(const std::string& name, glm::vec2 value, bool useShader) {
	if (useShader) use();
	glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, value_ptr(value));
}
void Shader::setVec3(const std::string& name, glm::vec3 value, bool useShader) {
	if (useShader) use();
	glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, value_ptr(value));
}
void Shader::setVec4(const std::string& name, glm::vec4 value, bool useShader) {
	if (useShader) use();
	glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, value_ptr(value));
}
void Shader::setMat4(const std::string& name, glm::mat4 value, bool useShader) {
	if (useShader) use();
	glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, value_ptr(value));
}