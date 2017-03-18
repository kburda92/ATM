#include "Frame.h"
#include "LoginView.h"
#include "SelectionView.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(Frame, CFrameWnd)

Frame::Frame()
{
}

void Frame::SwitchToView(int nView)
{
	CView* pOldActiveView = GetActiveView();
	CView* pNewActiveView = (CView*)GetDlgItem(nView);
	if (pNewActiveView == NULL) {
		//switch (nView) {
			pNewActiveView = (CView*) new SelectionView();
		//case STRING:
		//	pNewActiveView = (CView*) new CStringView;
		//	break;
		//case HEX:
		//	pNewActiveView = (CView*) new CHexView;
		//	break;
		//}
		CCreateContext context;
		context.m_pCurrentDoc = pOldActiveView->GetDocument();
		pNewActiveView->Create(NULL, NULL, WS_BORDER, CFrameWnd::rectDefault, this, nView, &context);
		pNewActiveView->OnInitialUpdate();
	}
	SetActiveView(pNewActiveView);
	pNewActiveView->ShowWindow(SW_SHOW);
	pOldActiveView->ShowWindow(SW_HIDE);
	//pOldActiveView->SetDlgCtrlID(
	//	pOldActiveView->GetRuntimeClass() == RUNTIME_CLASS(CStringView) ? STRING : HEX);
	//pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout();
}


BOOL Frame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	cs.style = WS_OVERLAPPED | WS_SYSMENU | WS_BORDER;
	cs.hMenu = NULL;

	cs.cy = ::GetSystemMetrics(SM_CYSCREEN) / 2;
	cs.cx = ::GetSystemMetrics(SM_CXSCREEN) / 2;
	cs.y = ((cs.cy * 2) - cs.cy) / 2;
	cs.x = ((cs.cx * 2) - cs.cx) / 2;

	return TRUE;
}