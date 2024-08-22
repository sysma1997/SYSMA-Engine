#include "MainMenu.h"

using namespace SYSMA;

Pong::MainMenu::MainMenu(Engine& engine) : engine{ engine } {}

void Pong::MainMenu::load() {
	addInput(this);

	Shader* shader{ Engine::GetShader("label") };
	std::string path{ "Assets/Fonts/Robot_Font.otf" };
	int fontSize{ 30 };

	UI::Label* title{ new UI::Label{shader, path, 60} };
	title->setText("PONG");
	title->align = UI::Label::Align::CENTER;
	title->position = Engine::GetSizeMiddle() - glm::vec2{ 0.0f, title->size.y };
	UI::Label* start{ new UI::Label{shader, path, fontSize} };
	start->setText("Start");
	start->align = UI::Label::Align::CENTER;
	start->position = title->position + glm::vec2{ 0.0f, title->size.y + (start->size.y / 2.0f) };
	start->color = glm::vec3{0.5f};
	UI::Label* exit{ new UI::Label{shader, path, fontSize} };
	exit->setText("Exit");
	exit->align = UI::Label::Align::CENTER;
	exit->position = start->position + glm::vec2{ 0.0f, start->size.y + (exit->size.y / 2.0f) };
	
	addUI(title);
	addUI(start);
	addUI(exit);
	options.push_back(start);
	options.push_back(exit);
}
void Pong::MainMenu::isInputJustPress(int key) {
	if (key == GLFW_KEY_UP) {
		option--;
		if (option < 0) option = options.size() - 1;
	}
	if (key == GLFW_KEY_DOWN) {
		option++;
		if (option > (options.size() - 1)) option = 0;
	}
	if (key == GLFW_KEY_SPACE) {
		if (option == 0) engine.loadScene(new Pong::_Game{ engine });
		else if (option == 1) engine.closeLoop();
	}

	for (int i{ 0 }; i < options.size(); i++)
		options[i]->color = glm::vec3{ 1.0f };
	options[option]->color = glm::vec3{ 0.5f };
}
