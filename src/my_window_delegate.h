#pragma once
#ifndef MY_WINDOW_DELEGATE_H
#define MY_WINDOW_DELEGATE_H

#include <Windows.h>

#include <include/views/cef_window.h>
#include <include/views/cef_browser_view.h>


class MyWindowDelegate : public CefWindowDelegate
{
public:
	
	static bool is_frameless;
	static bool can_resize;
	static HWND parent_hwnd;
	static int window_default_x;
	static int window_default_y;
	static int window_default_width;
	static int window_default_height;
	
	explicit MyWindowDelegate(CefRefPtr<CefBrowserView> browser_view) : browser_view_(browser_view) {};
	bool IsFrameless(CefRefPtr<CefWindow> window) override;
	bool CanResize(CefRefPtr<CefWindow> window) override;
	void OnWindowCreated(CefRefPtr<CefWindow> window) override;
	void OnWindowDestroyed(CefRefPtr<CefWindow> window) override;
	CefRect GetInitialBounds(CefRefPtr<CefWindow> window) override;
	MyWindowDelegate(const MyWindowDelegate&) = delete;
	MyWindowDelegate& operator=(const MyWindowDelegate&) = delete;

private:
	CefRefPtr<CefBrowserView> browser_view_;
	IMPLEMENT_REFCOUNTING(MyWindowDelegate);

};

#endif // MY_WINDOW_DELEGATE_H
