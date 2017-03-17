#include "Frame.h"
#include "LoginView.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(Frame, CFrameWnd)

Frame::Frame()
{

}

void Frame::SwitchToView(int nView)
{
	//CView* pOldActiveView = GetActiveView();
	//CView* pNewActiveView = (CView*)GetDlgItem(nView);
	//if (pNewActiveView == NULL) {
	//	switch (nView) {
	//	case STRING:
	//		pNewActiveView = (CView*) new CStringView;
	//		break;
	//	case HEX:
	//		pNewActiveView = (CView*) new CHexView;
	//		break;
	//	}
	//	CCreateContext context;
	//	context.m_pCurrentDoc = pOldActiveView->GetDocument();
	//	pNewActiveView->Create(NULL, NULL, WS_BORDER, CFrameWnd::rectDefault, this, nView, &context);
	//	pNewActiveView->OnInitialUpdate();
	//}
	//SetActiveView(pNewActiveView);
	//pNewActiveView->ShowWindow(SW_SHOW);
	//pOldActiveView->ShowWindow(SW_HIDE);
	//pOldActiveView->SetDlgCtrlID(
	//	pOldActiveView->GetRuntimeClass() == RUNTIME_CLASS(CStringView) ? STRING : HEX);
	//pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	//RecalcLayout();
}
