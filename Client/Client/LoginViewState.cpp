#pragma once
#include "LoginViewStates.h"
#include "LoginView.h"

LoginViewState::LoginViewState(CEdit& valueEdit, CStatic& enterValueStatic, int& maxChars) :
	valueEdit(valueEdit), enterValueStatic(enterValueStatic), maxChars(maxChars)
{
	SetValues();
	valueEdit.SetFocus();
}

void LoginViewState::SetValues()
{
	valueEdit.SetWindowTextW(L"");
}

IdState::IdState(CEdit& valueEdit, CStatic& enterValueStatic, int& maxChars) :
	LoginViewState(valueEdit, enterValueStatic, maxChars)
{
	SetValues();
}

void IdState::SetValues()
{
	valueEdit.SetPasswordChar(0);
	enterValueStatic.SetWindowTextW(L"Enter Id: ");
	maxChars = 8;
}

PinState::PinState(CEdit& valueEdit, CStatic& enterValueStatic, int& maxChars) :
	LoginViewState(valueEdit, enterValueStatic, maxChars)
{
	SetValues();
}

void PinState::SetValues()
{
	valueEdit.SetPasswordChar('*');
	enterValueStatic.SetWindowTextW(L"Enter Pin: ");
	maxChars = 4;
}