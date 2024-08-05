#pragma once

#include <string>
#include <vector>
#include <map>

#include "Object.h"
#include "Input.h"

namespace SYSMA {
	class Scene {
		std::vector<Object*> objects2D;
		std::vector<Object*> UIs;
		std::vector<Input*> inputs;
	public:
		~Scene();

		void addObject2D(Object* object2D);
		void addUI(Object* UI);
		void addInput(Input* input);
		void start();

		virtual void load() = 0;
	};
}