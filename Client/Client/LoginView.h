#pragma once
#include "afxext.h"
#include "Messages.h"
#include "LoginViewStates.h"
#include "resource.h"
#include <memory>

class LoginView : public CFormView
{
	DECLARE_DYNCREATE(LoginView)
	DECLARE_MESSAGE_MAP()
private:
	afx_msg void OnLoginButtonClicked();
	std::unique_ptr<LoginViewState> state = std::make_unique<IdState>(this);
	CButton loginButton;
	CEdit valueEdit;
	CStatic enterValueStatic;
	CString idValue, pinValue;
protected:
	LoginView() : CFormView(IDD_LOGINVIEW) {};
	virtual ~LoginView() {};
	virtual void DoDataExchange(CDataExchange* pDX);
public:
	CEdit& GetValueEdit() { return valueEdit; }
	CStatic& GetEnterValueStatic() { return enterValueStatic; }
	CString& GetId() { return idValue; }
	CString& GetPin() { return pinValue; }
	void OnInitialUpdate();
	afx_msg void OnEnChangeValueEdit();
};

