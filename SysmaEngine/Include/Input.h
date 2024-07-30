#pragma once

namespace SYSMA {
	class Input {
	public:
		virtual void isInputPress(int key) {}
		virtual void isInputJustPress(int key) {}
	};
}