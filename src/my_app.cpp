#include "my_app.h"

#include <include/cef_browser.h>
#include <include/views/cef_browser_view.h>
#include <include/views/cef_window.h>
#include <include/wrapper/cef_helpers.h>

#include "my_window_delegate.h"
#include "my_browser_view_delegate.h"


void MyApp::OnContextInitialized()
{
	CEF_REQUIRE_UI_THREAD();

	CefBrowserSettings settings;
	CefRefPtr<MyBrowserViewDelegate> view_delegate(new MyBrowserViewDelegate);
	CefRefPtr<CefBrowserView> browser_view = CefBrowserView::CreateBrowserView(nullptr, url, settings, nullptr, nullptr, view_delegate);
	CefWindow::CreateTopLevelWindow(new MyWindowDelegate(browser_view));
}
