// InfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "InfoDlg.h"
#include "afxdialogex.h"
#include "POWER_SYSTEM_MAINFRAME.h"

// InfoDlg 对话框

IMPLEMENT_DYNAMIC(InfoDlg, CDialog)

InfoDlg::InfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PERSONAL_INFO, pParent)
{

}

InfoDlg::~InfoDlg()
{
}

void InfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(InfoDlg, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_QUIT_BUTTON, &InfoDlg::OnBnClickedQuitButton)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// InfoDlg 消息处理程序


BOOL InfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	GetWindowRect(&rc);
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	user = pWnd->getUser();
	GetDlgItem(IDC_NAME_SHOW)->SetWindowTextW((LPCTSTR)((CString)user->getname().c_str()));
	GetDlgItem(IDC_EMAIL_SHOW)->SetWindowTextW((LPCTSTR)((CString)user->getemail().c_str()));
	GetDlgItem(IDC_IDENTITY_SHOW)->SetWindowTextW((LPCTSTR)((CString)user->getidentityNo().c_str()));
	GetDlgItem(IDC_PHONE_SHOW)->SetWindowTextW((LPCTSTR)((CString)user->getphoneNo().c_str()));
	GetDlgItem(IDC_CREATE_SHOW)->SetWindowTextW((LPCTSTR)((CString)user->getcreateDate().c_str()));
	GetDlgItem(IDC_ADDRESS_SHOW)->SetWindowTextW((LPCTSTR)((CString)user->getaddress().c_str()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void InfoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	CWnd *pWnd;

	pWnd = GetDlgItem(IDC_QUIT_BUTTON);

	if (pWnd)//判断是否为空，因为对话框创建时会调用此函数，而当时控件还未创建
	{
		CRect rect; //获取控件变化前大小
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);//将控件大小转换为在对话框中的区域坐标
							  //　cx/m_rect.Width()为对话框在横向的变化比例
		rect.left = rect.left*cx / rc.Width();/////调整控件大小
		rect.right = rect.right*cx / rc.Width();
		rect.top = rect.top*cy / rc.Height();
		rect.bottom = rect.bottom*cy / rc.Height();
		pWnd->MoveWindow(rect);//设置控件大小
	}
	GetClientRect(&rc);//将变化后的对话框大小设为旧大小
}


void InfoDlg::OnBnClickedQuitButton()
{
	delete user;
	//OnCancel();
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pLogin = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	pLogin->GetDlgItem(IDC_LOGIN_NAME_INPUT)->SetWindowTextW(NULL);
	pLogin->GetDlgItem(IDC_PWD_INPUT)->SetWindowTextW(NULL);

	hWnd = ::FindWindow(NULL, L"权限系统");
	POWER_SYSTEM_MAINFRAME* pWnd = (POWER_SYSTEM_MAINFRAME*)POWER_SYSTEM_MAINFRAME::FromHandle(hWnd);
	pWnd->EndDialog(0);

}


void InfoDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);
}
