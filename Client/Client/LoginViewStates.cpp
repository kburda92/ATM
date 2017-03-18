#include "LoginView.h"
#include "LoginViewStates.h"

void LoginViewState::Init()
{
	view->GetValueEdit().SetWindowTextW(L"");
	view->GetValueEdit().SetFocus();
}

void IdState::Init()
{
	view->GetValueEdit().SetPasswordChar(0);
	view->GetEnterValueStatic().SetWindowTextW(L"Enter Id: ");
	view->GetId() = "";
	view->GetPin() = "";
	LoginViewState::Init();
}

CString& IdState::GetValue()
{
	return view->GetId();
}

void PinState::Init()
{
	view->GetValueEdit().SetPasswordChar('*');
	view->GetEnterValueStatic().SetWindowTextW(L"Enter Pin: ");
	LoginViewState::Init();
}

CString& PinState::GetValue()
{
	return view->GetPin();
}