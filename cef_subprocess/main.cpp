//
#include <windows.h>
#include <include/cef_app.h>


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
					 _In_opt_ HINSTANCE hPrevInstance,
					 _In_ LPWSTR    lpCmdLine,
					 _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
	CefMainArgs main_args(hInstance);
	int exit_code = CefExecuteProcess(main_args, nullptr, nullptr);
	if (exit_code >= 0)
	{
		return exit_code;
	}
	
	MessageBox(NULL, L"exit_code < 0!", L"Error", MB_OK | MB_ICONERROR);
	
	return 0;
}
