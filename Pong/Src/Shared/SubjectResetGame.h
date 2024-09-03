#pragma once

#include <Engine.h>
#include <Subject.h>

namespace Pong::Shared {
	struct SubjectResetGame : public SYSMA::Subject<SubjectResetGame> {
		void reset();
	};
}