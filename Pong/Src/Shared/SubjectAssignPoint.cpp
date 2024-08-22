#include "SubjectAssignPoint.h"

using namespace Pong::Shared;

void SubjectAssignPoint::addPoint(Assign assign) {
	this->assign = assign;
	notify();
}
SubjectAssignPoint::Assign SubjectAssignPoint::get() {
	return assign;
}