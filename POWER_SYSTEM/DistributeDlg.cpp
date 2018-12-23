// DistributeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "DistributeDlg.h"
#include "afxdialogex.h"
#include "POWER_SYSTEM_MAINFRAME.h"

// CDistributeDlg 对话框

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


// CDistributeDlg 消息处理程序


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
	//初始化用户列表
	CFont* m_font = new CFont();
	m_font->CreatePointFont(150, LPCTSTR("Arial"), NULL);
	listA.SetFont(m_font);
	listB.SetFont(m_font);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDistributeDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	for (auto pWnd : item_list)
	{
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

	}
	GetClientRect(&rc);//将变化后的对话框大小设为旧大小

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

	// TODO: 在此处添加消息处理程序代码
	HWND hWnd = ::FindWindow(NULL, L"权限系统");
	POWER_SYSTEM_MAINFRAME* pWnd = (POWER_SYSTEM_MAINFRAME*)POWER_SYSTEM_MAINFRAME::FromHandle(hWnd);
	int cur = pWnd->m_CurSelTab;
	setLists(cur == 3);
}
