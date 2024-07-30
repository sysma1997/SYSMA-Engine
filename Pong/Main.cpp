#include <iostream>

#include <Engine.h>
#include <Shader.h>
#include <Input.h>

#include <Input.h>
#include <2D/Triangle.h>
#include <2D/Rectangle.h>
#include <UI/Label.h>

using namespace SYSMA;

class Test : public E2D::Rectangle, public Input {
	const float GRAVITY = 300.0f;
	const float MOVE = 60.0f;

	float velocity{ 0.0f };

	void isInputPress(int key) override {
		if (key == GLFW_KEY_LEFT)
			position.x -= MOVE * Engine::DeltaTime;
		if (key == GLFW_KEY_RIGHT)
			position.x += MOVE * Engine::DeltaTime;
		if (key == GLFW_KEY_UP)
			position.y -= MOVE * Engine::DeltaTime;
		if (key == GLFW_KEY_DOWN)
			position.y += MOVE * Engine::DeltaTime;
		if (key == GLFW_KEY_R)
			rotate += 30.0f * Engine::DeltaTime;
	}
	void isInputJustPress(int key) override {
		if (key == GLFW_KEY_SPACE)
			velocity = -150.0f;
	}
public:
	Test(Engine& engine, Shader* shader) : Rectangle{shader} {
		engine.addInput(this);
	}

	//void process() override {
	//	velocity += GRAVITY * Engine::DeltaTime;
	//	position.y += velocity * Engine::DeltaTime;
	//}
};

int main() {
	Engine* engine{ new Engine{"Pong"} };
	
	Shader* shaderRect{ new Shader{} };
	shaderRect->link(E2D::Rectangle::VERT, E2D::Rectangle::FRAG);
	Shader* shaderLabel{ new Shader{} };
	shaderLabel->link(UI::Label::VERT, UI::Label::FRAG);

	Test* cube{ new Test{*engine, shaderRect} };
	cube->size = glm::vec3{ 60.0f };
	cube->position = Engine::GetSizeMiddle();
	UI::Label* label{ new UI::Label{shaderLabel, "Assets/Fonts/Robot_font.otf", 30} };
	label->setText("test");
	label->position = glm::vec2{ 5.0f, (label->size.y / 2.0f) + 5.0f };
	UI::Label* label2{ new UI::Label{shaderLabel, "Assets/Fonts/Robot_font.otf", 30} };
	label2->setText("CENTER UP");
	label2->align = UI::Label::Aling::CENTER;
	label2->position = glm::vec2{ Engine::GetSizeMiddle().x, (label2->size.y / 2.0f) + 5.0f };
	label2->color = glm::vec3{ 0.0f, 1.0f, 0.0f };
	UI::Label* label3{ new UI::Label{shaderLabel, "Assets/Fonts/Robot_font.otf", 30} };
	label3->setText("Finish");
	label3->align = UI::Label::Aling::RIGHT;
	label3->position = glm::vec2{ Engine::GetSize().x - 5.0f, (label2->size.y / 2.0f) + 5.0f };
	label3->color = glm::vec3{ 0.0f, 0.0f, 1.0f };

	E2D::Triangle* triangle{ new E2D::Triangle{shaderRect} };
	triangle->size = glm::vec2{ 60.0f };
	triangle->position = glm::vec2{ 100.0f };

	while (engine->isLoop()) {
		engine->newFrame();

		//cube->process();
		//
		//cube->draw();
		triangle->draw();
		label->draw();
		label2->draw();
		label3->draw();

		engine->renderFrame();
	}

	engine->terminate();
	return 0;
}