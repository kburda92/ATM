#pragma once
#include "afxext.h"
#include "Messages.h"

class LoginView : public CFormView
{
	DECLARE_DYNCREATE(LoginView)
public:
	LoginView();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedLoginButton();
};

