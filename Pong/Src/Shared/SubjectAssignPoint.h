#pragma once

#include <Subject.h>

namespace Pong::Shared {
	class SubjectAssignPoint : public SYSMA::Subject<SubjectAssignPoint> {
	public:
		enum Assign {
			PLAYER, 
			OPPONENT
		};

		void addPoint(Assign assign);
		Assign get();

	private:
		Assign assign;
	};
}