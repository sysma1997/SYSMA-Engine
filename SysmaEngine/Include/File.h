#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

namespace SYSMA {
	class File {
	public:
		static std::string GetText(std::string path);
	};
}