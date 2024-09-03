#include "../Include/Input.h"

using namespace SYSMA;

Input::Input() : pauseInput{ false } {}

void Input::isPauseInput(bool pauseInput) {
	this->pauseInput = pauseInput;
}
bool Input::isPauseInput() {
	return pauseInput;
}