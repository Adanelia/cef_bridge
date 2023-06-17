#include "my_window_delegate.h"


bool MyWindowDelegate::is_frameless = false;
bool MyWindowDelegate::can_resize = true;
HWND MyWindowDelegate::parent_hwnd = NULL;
int MyWindowDelegate::window_default_x = 0;
int MyWindowDelegate::window_default_y = 0;
int MyWindowDelegate::window_default_width = 800;
int MyWindowDelegate::window_default_height = 600;


bool MyWindowDelegate::IsFrameless(CefRefPtr<CefWindow> window)
{
	return is_frameless;
}


bool MyWindowDelegate::CanResize(CefRefPtr<CefWindow> window)
{
	return can_resize;
}


void MyWindowDelegate::OnWindowCreated(CefRefPtr<CefWindow> window)
{
	window->AddChildView(browser_view_);
	
	if (parent_hwnd != NULL)
	{
		HWND hwnd = window->GetWindowHandle();
		SetParent(hwnd, parent_hwnd);
	}
	
	window->Show();
	browser_view_->RequestFocus();
}


void MyWindowDelegate::OnWindowDestroyed(CefRefPtr<CefWindow> window)
{
	browser_view_ = nullptr;
}


CefRect MyWindowDelegate::GetInitialBounds(CefRefPtr<CefWindow> window)
{
	CefRect rect;
	rect.x = window_default_x;
	rect.y = window_default_y;
	rect.width = window_default_width;
	rect.height = window_default_height;
	return rect;
}
