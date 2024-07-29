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
	"uniform sampler2D text;\n"
	"void main() {\n"
	"	vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);\n"
	"	color = vec4(textColor, 1.0) * sampled;\n"
	"}";

Label::Label(Shader* shader) : shader{ shader } {}
Label::Label(Shader* shader, std::string path, int fontSize) : shader{ shader } {

}