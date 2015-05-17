// rundll32_thing.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <string>
#define DLLEXP __declspec(dllexport)

extern "C" {
	DLLEXP void CALLBACK PrintHi(HWND hWnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow) {
		MessageBox(hWnd, L"hi world", L"magic dll", 0);
	}
    DLLEXP void CALLBACK Echo(HWND hWnd, HINSTANCE hinst, LPSTR lpszCmdLine, int nCmdShow) {
		int cmdLineLen = strlen(lpszCmdLine);

		LPWSTR ucs = new WCHAR[cmdLineLen];
		MultiByteToWideChar(CP_UTF8, 0, lpszCmdLine, cmdLineLen, ucs, cmdLineLen);

		MessageBox(hWnd, ucs, L"magic dll", 0);
	}
}