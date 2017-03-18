#include "LoginView.h"
#include "resource.h"
#include "string"

IMPLEMENT_DYNCREATE(LoginView, CFormView)

using namespace std;

LoginView::LoginView() : CFormView(IDD_LOGINVIEW)
{}

LoginView::~LoginView()
{}

void LoginView::SetState(const ViewType& type)
{
	switch (type)
	{
	case ViewType::Id:
		state = std::make_unique<IdState>(valueEdit, enterValueStatic, maxChars);
		break;
	case ViewType::Pin:
		state = std::make_unique<PinState>(valueEdit, enterValueStatic, maxChars);
		break;
	}
}

BEGIN_MESSAGE_MAP(LoginView, CFormView)
ON_BN_CLICKED(IDC_LOGINBUTTON, &LoginView::OnLoginButtonClicked)
ON_EN_CHANGE(IDC_VALUEEDIT, &LoginView::OnEnChangeValueedit)
END_MESSAGE_MAP()

void LoginView::OnLoginButtonClicked()
{
	if(typeid(*state) == typeid(IdState))
		SetState(ViewType::Pin);
	else
		SetState(ViewType::Id);
	UpdateData(TRUE);
	//AfxGetMainWnd()->PostMessageW(WM_LOGIN);
}

void LoginView::DoDataExchange(CDataExchange * pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ENTERVALUESTATIC, enterValueStatic);
	DDX_Control(pDX, IDC_VALUEEDIT, valueEdit);
	DDX_Text(pDX, IDC_VALUEEDIT, value);
	DDV_MaxChars(pDX, value, maxChars);
	DDX_Control(pDX, IDC_LOGINBUTTON, loginButton);
}

void LoginView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	SetState(ViewType::Id);
	//loginButton.EnableWindow(false);
}

void LoginView::OnEnChangeValueedit()
{
	loginButton.EnableWindow(valueEdit.GetWindowTextLengthW() == maxChars);
}
