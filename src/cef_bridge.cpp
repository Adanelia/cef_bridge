#include "cef_bridge.h"

//#include <direct.h>// <unistd.h> on Linux
//#include <cstring>
#include <string>


DLLEXPORT CefBridge::CefBridge(HINSTANCE hInstance, HWND hWnd, const char* default_url, int x, int y, int width, int height, bool is_frameless, bool can_resize)
{
	CefEnableHighDPISupport();
	CefMainArgs main_args(hInstance);
	CefSettings settings;
	settings.multi_threaded_message_loop = 1;
	
	// Get directory
	//char cwdbuf[512]{};
	//if (!getcwd(cwdbuf, sizeof(cwdbuf)))
	//{
		//MessageBox(NULL, L"File path too long!", L"Error", MB_OK | MB_ICONERROR);
		//return;
	//}
	//strcat(cwdbuf, path_separator);
	//strcat(cwdbuf, subprocess_name);
	// cwd may change, not reliable
	
	// Get exe path instead
	//wchar_t filenamebuf[512]{};
	//GetModuleFileName(NULL, filenamebuf, sizeof(filenamebuf));
	char filenamebuf[512]{};
	GetModuleFileNameA(NULL, filenamebuf, sizeof(filenamebuf));
	// readlink("/proc/self/exe", filenamebuf, sizeof(filenamebuf))	on Linux
	std::string filename = filenamebuf;
	std::string filedir = filename.substr(0, filename.rfind(path_separator) + 1);
	
	CefString(&settings.browser_subprocess_path).FromString(filedir + subprocess_name);
	
	// CefExecuteProcess
	int exit_code = CefExecuteProcess(main_args, nullptr, nullptr);
	if (exit_code >= 0)
	{
		//print("ERROR: exit_code >= 0");
		MessageBox(NULL, L"exit_code >= 0!", L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	
	// Setup WindowDelegate
	MyWindowDelegate::is_frameless = is_frameless;
	MyWindowDelegate::can_resize = can_resize;
	MyWindowDelegate::parent_hwnd = hWnd;
	MyWindowDelegate::window_default_x = x;
	MyWindowDelegate::window_default_y = y;
	MyWindowDelegate::window_default_width = width;
	MyWindowDelegate::window_default_height = height;
	
	CefRefPtr<MyApp> app(new MyApp);
	app->url = default_url;
	CefInitialize(main_args, settings, app.get(), nullptr);
}


DLLEXPORT CefBridge::~CefBridge()
{
	CefShutdown();
}


DLLEXPORT int CefBridge::test()
{
	return 0;
}
