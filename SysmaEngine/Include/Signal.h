#pragma once

#include <vector>

namespace SYSMA {
	template<class T>
	struct Signal {
		void received(const T& value) {}
	};
}