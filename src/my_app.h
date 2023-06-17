#pragma once

#include <include/cef_app.h>

#include <string>


class MyApp : public CefApp, public CefBrowserProcessHandler
{
public:
	
	std::string url = "http://www.google.com";
	
	MyApp() = default;
	CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override { return this; }
	void OnContextInitialized() override;

private:
	IMPLEMENT_REFCOUNTING(MyApp);
};
