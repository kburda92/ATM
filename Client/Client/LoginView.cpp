#include "LoginView.h"
#include "resource.h"
#include "string"

IMPLEMENT_DYNCREATE(LoginView, CFormView)

using namespace std;

LoginView::LoginView() : CFormView(IDD_LOGINVIEW)
{}

LoginView::~LoginView()
{}


BEGIN_MESSAGE_MAP(LoginView, CFormView)
ON_BN_CLICKED(IDC_LOGINBUTTON, &LoginView::OnLoginButtonClicked)
ON_EN_CHANGE(IDC_VALUEEDIT, &LoginView::OnEnChangeValueEdit)
END_MESSAGE_MAP()

void LoginView::OnLoginButtonClicked()
{
	UpdateData(TRUE);
	if(typeid(*state) == typeid(IdState))
		state = std::make_unique<PinState>(this);
	else
	{
		if (!AfxGetMainWnd()->SendMessage(WM_LOGIN, _ttoi(idValue), _ttoi(pinValue)))
			state = std::make_unique<IdState>(this);
		else
			state.release();
	}

	if (state)
	{
		state->Init();
		UpdateData(FALSE);
	}
}

void LoginView::DoDataExchange(CDataExchange * pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ENTERVALUESTATIC, enterValueStatic);
	DDX_Control(pDX, IDC_VALUEEDIT, valueEdit);
	DDX_Text(pDX, IDC_VALUEEDIT, state->GetValue());
	DDV_MaxChars(pDX, state->GetValue(), state->GetMaxChars());
	DDX_Control(pDX, IDC_LOGINBUTTON, loginButton);
}

void LoginView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(TRUE);
	GetParentFrame()->CenterWindow();
}

void LoginView::OnEnChangeValueEdit()
{
	loginButton.EnableWindow(valueEdit.GetWindowTextLengthW() == state->GetMaxChars());
	loginButton.SetFocus();
}
