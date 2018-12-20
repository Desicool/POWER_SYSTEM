// POWER_SYSTEM_MAINFRAME.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "POWER_SYSTEM_MAINFRAME.h"
#include "afxdialogex.h"
// POWER_SYSTEM_MAINFRAME �Ի���



IMPLEMENT_DYNAMIC(POWER_SYSTEM_MAINFRAME, CDialogEx)

POWER_SYSTEM_MAINFRAME::POWER_SYSTEM_MAINFRAME(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAINFRAME, pParent)
{

}

POWER_SYSTEM_MAINFRAME::~POWER_SYSTEM_MAINFRAME()
{

}

void POWER_SYSTEM_MAINFRAME::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FUNC_TAB, func_tab);
}


BEGIN_MESSAGE_MAP(POWER_SYSTEM_MAINFRAME, CDialogEx)
	ON_WM_CREATE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_FUNC_TAB, &POWER_SYSTEM_MAINFRAME::OnTcnSelchangeFuncTab)
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// POWER_SYSTEM_MAINFRAME ��Ϣ��������


int POWER_SYSTEM_MAINFRAME::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ�������ר�õĴ�������

	return 0;
}



void POWER_SYSTEM_MAINFRAME::OnTcnSelchangeFuncTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	//�ѵ�ǰ��ҳ����������
	pDlgPage[m_CurSelTab]->ShowWindow(SW_HIDE);
	//�õ��µ�ҳ������
	m_CurSelTab = func_tab.GetCurSel();
	//���µ�ҳ����ʾ����
	pDlgPage[m_CurSelTab]->ShowWindow(SW_SHOW);

	*pResult = 0;
}


BOOL POWER_SYSTEM_MAINFRAME::OnInitDialog()
{
	CDialogEx::OnInitDialog();                        

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	//ΪTab Control����ҳ��
	func_tab.InsertItem(0, _T("��ѯ"));
	func_tab.InsertItem(1, TEXT("�ҵ�"));
	func_tab.InsertItem(2, TEXT("�����û�"));
	//�����Ի���
	query_page.Create(IDD_QUERY_TAB, &func_tab);
	info_page.Create(IDD_PERSONAL_INFO, &func_tab);
	add_user_page.Create(IDD_ADD_USER, &func_tab);
	//�趨��Tab����ʾ�ķ�Χ
	CRect rc;
	func_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	query_page.MoveWindow(&rc);
	info_page.MoveWindow(&rc);
	add_user_page.MoveWindow(&rc);
	//�ѶԻ������ָ�뱣������
	pDlgPage[0] = &query_page;
	pDlgPage[1] = &info_page;
	pDlgPage[2] = &add_user_page;
	//��ʾ��ʼҳ��
	pDlgPage[0]->ShowWindow(SW_SHOW);
	//���浱ǰѡ��
	m_CurSelTab = 0;
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	user = pWnd->getUser();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

User * POWER_SYSTEM_MAINFRAME::getUser()
{
	return user;
}

void POWER_SYSTEM_MAINFRAME::setUser(User * us)
{
	user = us;
}


void POWER_SYSTEM_MAINFRAME::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	// TODO: �ڴ˴�������Ϣ�����������
	
}


void POWER_SYSTEM_MAINFRAME::OnClose()
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ

	CDialogEx::OnClose();
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	pWnd->SendMessage(WM_CLOSE);

}