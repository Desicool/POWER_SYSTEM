// DistributeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "DistributeDlg.h"
#include "afxdialogex.h"
#include "POWER_SYSTEM_MAINFRAME.h"

// CDistributeDlg �Ի���

IMPLEMENT_DYNAMIC(CDistributeDlg, CDialog)

CDistributeDlg::CDistributeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DISTRIBUTE_CHARACTER, pParent)
{

}


CDistributeDlg::~CDistributeDlg()
{
	delete user;
	delete character;
}

void CDistributeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USER_LIST, listA);
	DDX_Control(pDX, IDC_CHARACTER_LIST, listB);
}


BEGIN_MESSAGE_MAP(CDistributeDlg, CDialog)
	ON_WM_SIZE()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDistributeDlg ��Ϣ�������


BOOL CDistributeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	GetWindowRect(&rc);
	//HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	//CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	//user = pWnd->getUser();
	user = new User();
	character = new Character();
	item_list.push_back(GetDlgItem(IDC_USER_LIST));
	item_list.push_back(GetDlgItem(IDC_CHARACTER_LIST));
	item_list.push_back(GetDlgItem(IDC_USERLIST_STATIC));
	item_list.push_back(GetDlgItem(IDC_CHARACTERLIST_STATIC));
	item_list.push_back(GetDlgItem(IDC_CHECK_BUTTON));
	//��ʼ���û��б�
	CFont* m_font = new CFont();
	m_font->CreatePointFont(150, LPCTSTR("Arial"), NULL);
	listA.SetFont(m_font);
	listB.SetFont(m_font);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDistributeDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	for (auto pWnd : item_list)
	{
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

	}
	GetClientRect(&rc);//���仯��ĶԻ����С��Ϊ�ɴ�С

}

void CDistributeDlg::setLists(bool is_character)
{
	listA.ResetContent();
	listB.ResetContent();
	if (is_character)
	{
		vector<CString>uname = user->get_all();
		for (auto p : uname)
			listA.AddString(p);
		uname = character->get_all();
		for (auto p : uname)
			listB.AddString(p);
	}
	else
	{
		vector<CString>uname = character->get_all();
		for (auto p : uname)
			listA.AddString(p);
		uname = character->get_all_privilege();
		for (auto p : uname)
			listB.AddString(p);
	}
}



void CDistributeDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: �ڴ˴������Ϣ����������
	HWND hWnd = ::FindWindow(NULL, L"Ȩ��ϵͳ");
	POWER_SYSTEM_MAINFRAME* pWnd = (POWER_SYSTEM_MAINFRAME*)POWER_SYSTEM_MAINFRAME::FromHandle(hWnd);
	int cur = pWnd->m_CurSelTab;
	setLists(cur == 3);
}
