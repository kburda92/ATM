#pragma once
#include "afxext.h"
#include "Messages.h"
#include "LoginViewStates.h"
#include <memory>

enum class ViewType
{
	Id,
	Pin
};

class LoginView : public CFormView
{
	DECLARE_DYNCREATE(LoginView)
	DECLARE_MESSAGE_MAP()
private:
	void SetState(const ViewType& type);
	afx_msg void OnLoginButtonClicked();
	std::unique_ptr<LoginViewState> state;
	CButton loginButton;
	CEdit valueEdit;
	CStatic enterValueStatic;
	int maxChars = 8;
	CString value;
protected:
	LoginView();
	virtual ~LoginView();
	virtual void DoDataExchange(CDataExchange* pDX);
public:
	void OnInitialUpdate();
	afx_msg void OnEnChangeValueedit();
};

