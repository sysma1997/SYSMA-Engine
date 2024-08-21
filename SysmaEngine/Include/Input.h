#pragma once

namespace SYSMA {
	struct Input {
		virtual void isInputPress(int key, bool isPress) {}
		virtual void isInputJustPress(int key) {}
	};
}