#include "LoginView.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(LoginView, CFormView)

LoginView::LoginView() : CFormView(IDD_LOGINVIEW)
{
}

BEGIN_MESSAGE_MAP(LoginView, CFormView)
ON_BN_CLICKED(IDC_LOGINBUTTON, &LoginView::OnBnClickedLoginButton)
END_MESSAGE_MAP()


void LoginView::OnBnClickedLoginButton()
{
	AfxGetMainWnd()->PostMessageW(WM_LOGIN);
}
