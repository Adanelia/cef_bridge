#pragma once

#include <include/views/cef_browser_view.h>
#include <include/views/cef_window.h>


class MyBrowserViewDelegate : public CefBrowserViewDelegate
{
public:
	MyBrowserViewDelegate() = default;
	MyBrowserViewDelegate(const MyBrowserViewDelegate&) = delete;
	MyBrowserViewDelegate& operator=(const MyBrowserViewDelegate&) = delete;
	bool OnPopupBrowserViewCreated(CefRefPtr<CefBrowserView> browser_view, CefRefPtr<CefBrowserView> popup_browser_view, bool is_devtools) override;

private:
	IMPLEMENT_REFCOUNTING(MyBrowserViewDelegate);

};
