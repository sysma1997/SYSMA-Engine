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
	public:
		std::map<std::string, Shader*> shaders;
		std::map<std::string, Texture*> textures;

		std::vector<Object*> objects2D;
		std::vector<Object*> UIs;
		std::vector<Input*> inputs;

		~Scene();

		void addShader(std::string name, Shader* shader);
		Shader* getShader(std::string name);
		void addTexture(std::string name, Texture* texture);
		Texture* getTexture(std::string name);

		void addObject2D(Object* object2D);
		void addUI(Object* UI);
		void addInput(Input* input);

		virtual void load() = 0;
	};
}