#include "App.h"
#include "Frame.h"
#include "LoginView.h"
#include "Doc.h"
#include "resource.h"


BOOL App::InitInstance()
{
	CWinApp::InitInstance();

	auto docTemplate = new CSingleDocTemplate(
		IDR_FRAME,
		RUNTIME_CLASS(Doc),
		RUNTIME_CLASS(Frame),
		RUNTIME_CLASS(LoginView));

	if (!docTemplate)
		return FALSE;

	AddDocTemplate(docTemplate);
	//auto doc = ((CFrameWnd*)AfxGetMainWnd())->GetActiveView()->GetDocument();
	//doc->OnNewDocument();
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

App app;