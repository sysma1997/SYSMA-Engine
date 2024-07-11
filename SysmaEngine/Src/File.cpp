#include "../Include/File.h"

using namespace SYSMA;

std::string File::GetText(std::string path) {
	std::ifstream stream{ path, std::ios::in };
	if (!stream.is_open()) {
		std::cout << "Impossible to open " << path << ". Are you in the right directory?\n";
		return "";
	}

	std::stringstream ss;
	ss << stream.rdbuf();
	stream.close();

	return ss.str();
}