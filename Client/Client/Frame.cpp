#include "Frame.h"
#include "LoginView.h"
#include "SelectionView.h"
#include "resource.h"
#include "Messages.h"

using namespace std;

IMPLEMENT_DYNCREATE(Frame, CFrameWnd)

BEGIN_MESSAGE_MAP(Frame, CFrameWnd)
	ON_MESSAGE(WM_LOGIN, &Frame::OnLogin)
END_MESSAGE_MAP()

void Frame::SwitchToSelectionView(const string& id, const string& pin)
{
	CView* pOldActiveView = GetActiveView();
	CView* pNewActiveView = (CView*) new SelectionView(id, pin);
	CCreateContext context;
	context.m_pCurrentDoc = pOldActiveView->GetDocument();
	pNewActiveView->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, this, 0, &context);
	pNewActiveView->OnInitialUpdate();
	SetActiveView(pNewActiveView);
	pNewActiveView->ShowWindow(SW_SHOW);
	pOldActiveView->ShowWindow(SW_HIDE);
	pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout();
	delete pOldActiveView;
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

LRESULT Frame::OnLogin(WPARAM id, LPARAM pin)
{
	if (!IsIdPinCorrect())
		return false;

	SwitchToSelectionView(to_string(id), to_string(pin));
	return true;
}

bool Frame::IsIdPinCorrect()
{
	return true;
}