#include "SubjectGame.h"

using namespace Pong::Shared;

SubjectGame::Method SubjectGame::getMethod() const {
	return method;
}
void SubjectGame::setAssign(SubjectGame::Assign assign) {
	this->assign = assign;
	method = SubjectGame::Method::ASSIGN_POINT;
	notify();
}
SubjectGame::Assign SubjectGame::getAssign() const {
	return assign;
}
void SubjectGame::setPosition(glm::vec2 position) {
	this->position = position;
	method = SubjectGame::Method::BALL_POSITION;
	notify();
}
glm::vec2 SubjectGame::getPosition() const {
	return position;
}
void SubjectGame::reset() {
	method = SubjectGame::Method::RESET_GAME;
	notify();
}