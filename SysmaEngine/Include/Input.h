#pragma once

namespace SYSMA {
	class Input {
	public:
		virtual void isInputPress(int key) = 0;
		virtual void isInputJustPress(int key) = 0;
	};
}