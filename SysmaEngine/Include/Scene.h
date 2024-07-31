#pragma once

#include <string>
#include <vector>
#include <map>

#include "Shader.h"
#include "Texture.h"
#include "Object.h"
#include "Input.h"

namespace SYSMA {
	class Scene {
		std::map<std::string, Shader*> shaders;
		std::map<std::string, Texture*> textures;

		std::vector<Object*> objects2D;
		std::vector<Object*> UIs;
		std::vector<Input*> inputs;

	public:
		~Scene();

		void addShader(std::string name, Shader* shader);
		void getShader(std::string name);
	};
}