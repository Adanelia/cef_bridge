#include "my_browser_view_delegate.h"

#include "my_window_delegate.h"


bool MyBrowserViewDelegate::OnPopupBrowserViewCreated(CefRefPtr<CefBrowserView> browser_view, CefRefPtr<CefBrowserView> popup_browser_view, bool is_devtools)
{
	CefWindow::CreateTopLevelWindow(new MyWindowDelegate(popup_browser_view));
	return true;
}
