#pragma once
#include <iostream>
#include <Windows.h>

HHOOK keyboardHook;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode >= 0 && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
		KBDLLHOOKSTRUCT* pKeyStruct = (KBDLLHOOKSTRUCT*)lParam;
		if (pKeyStruct->vkCode == 'A') {
			std::cout << "'A' key is pressed." << std::endl;
		}
	}
	return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}
