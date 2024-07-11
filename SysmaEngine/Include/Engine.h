#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace SYSMA {
	class Engine {
	private:
		static bool Keys[1024];
		static bool KeyProcessed[1024];

		float lastFrame;
		int lastWidth, lastHeight;

	public:
		static int Width, Height;
		static float FWidth, FHeight;
		static float DeltaTime;

		GLFWwindow* window;

		Engine(const char* title, int width = 800, int height = 600);

		static bool KeyPressed(int key);
		static bool KeyJustPressed(int key);
		static glm::vec2 GetSize();
		static glm::vec2 GetSizeMiddle();

		bool isLoop();
		void closeLoop();
		void newFrame();
		void renderFrame();
		void terminate();
	};
}