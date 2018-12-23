// InfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "InfoDlg.h"
#include "afxdialogex.h"
#include "POWER_SYSTEM_MAINFRAME.h"

// InfoDlg �Ի���

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


// InfoDlg ��Ϣ�������


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
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void InfoDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	CWnd *pWnd;

	pWnd = GetDlgItem(IDC_QUIT_BUTTON);

	if (pWnd)//�ж��Ƿ�Ϊ�գ���Ϊ�Ի��򴴽�ʱ����ô˺���������ʱ�ؼ���δ����
	{
		CRect rect; //��ȡ�ؼ��仯ǰ��С
		pWnd->GetWindowRect(&rect);
		ScreenToClient(&rect);//���ؼ���Сת��Ϊ�ڶԻ����е���������
							  //��cx/m_rect.Width()Ϊ�Ի����ں���ı仯����
		rect.left = rect.left*cx / rc.Width();/////�����ؼ���С
		rect.right = rect.right*cx / rc.Width();
		rect.top = rect.top*cy / rc.Height();
		rect.bottom = rect.bottom*cy / rc.Height();
		pWnd->MoveWindow(rect);//���ÿؼ���С
	}
	GetClientRect(&rc);//���仯��ĶԻ����С��Ϊ�ɴ�С
}


void InfoDlg::OnBnClickedQuitButton()
{
	delete user;
	//OnCancel();
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pLogin = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	pLogin->GetDlgItem(IDC_LOGIN_NAME_INPUT)->SetWindowTextW(NULL);
	pLogin->GetDlgItem(IDC_PWD_INPUT)->SetWindowTextW(NULL);

	hWnd = ::FindWindow(NULL, L"Ȩ��ϵͳ");
	POWER_SYSTEM_MAINFRAME* pWnd = (POWER_SYSTEM_MAINFRAME*)POWER_SYSTEM_MAINFRAME::FromHandle(hWnd);
	pWnd->EndDialog(0);

}


void InfoDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);
}
