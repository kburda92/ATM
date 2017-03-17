#include "LoginView.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(LoginView, CFormView)

LoginView::LoginView() : CFormView(IDD_LOGIN_VIEW)
{
}


LoginView::~LoginView()
{
}

void LoginView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}