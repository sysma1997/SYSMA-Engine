#pragma once

#include <string>
#include <vector>
#include <map>
#include <exception>

#include "Object.h"
#include "Input.h"
#include "Signal.h"

namespace SYSMA {
	class Scene {
	protected:
		std::vector<Object*> objects2D;
		std::vector<Object*> UIs;
		std::vector<Input*> inputs;

		int removePosObject2D;
		int removePosUI;
		int removePosInput;
		bool removeAll;

		bool pause;
	public:
		bool isLoad;

		Scene();
		~Scene();

		void addObject2D(Object* object2D);
		void removeObject2D(Object* object2D);
		void addUI(Object* UI);
		void removeUI(Object* UI);
		void addInput(Input* input);
		void removeInput(Input* input);
		void start();
		void isPause(bool pause);
		bool isPause();

		virtual void load() = 0;
		virtual void reload() = 0;
	};
}