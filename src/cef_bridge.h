#ifndef CEF_BRIDGE_H
#define CEF_BRIDGE_H

#include "my_app.h"
#include "my_window_delegate.h"


// #if defined(_WINDOWS)
#define DLLEXPORT __declspec(dllexport)
// #elif defined(GCC)
// #define DLLEXPORT __attribute__ ((visibility(“default”)))
// #endif


class DLLEXPORT CefBridge
{
public:
	
	CefBridge(
		HINSTANCE hInstance,
		HWND hWnd = NULL,
		const char* default_url = "http://www.google.com",// "http://www.baidu.com"
		int x = 0, int y = 0,
		int width = 800, int height = 600,
		bool is_frameless = false,
		bool can_resize = true
	);
	~CefBridge();
	
	int test();
	
private:
	
	const char* subprocess_name = "cef_subprocess";
	const char* path_separator = "\\";
	
};

#endif // CEF_BRIDGE_H
