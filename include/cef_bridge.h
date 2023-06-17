#pragma once
#ifndef CEF_BRIDGE_H
#define CEF_BRIDGE_H

#include <windows.h>


// #if defined(_WINDOWS)
#define DLLIMPORT __declspec(dllimport)
// #elif defined(GCC)
// #define DLLIMPORT __attribute__ ((visibility(“default”)))
// #endif


class DLLIMPORT CefBridge
{
public:
	
	CefBridge(
		HINSTANCE hInstance,
		HWND hWnd = NULL,
		const char* default_url = "http://www.google.com",
		int x = 0, int y = 0,
		int width = 800, int height = 600,
		bool is_frameless = false,
		bool can_resize = true
	);
	~CefBridge();
	
	int test();
	
};

#endif // CEF_BRIDGE_H
