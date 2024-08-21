#pragma once

#include <string>
#include <map>
#include <vector>

#include "Signal.h"

namespace SYSMA {
	template<class T>
	class Emit {
		std::map<std::string, std::vector<Signal<T>*>> signals;

	public:
		void subscribe(std::string name, Signal<T>* signal);
		void emit(std::string name, const T& value);
	};
}