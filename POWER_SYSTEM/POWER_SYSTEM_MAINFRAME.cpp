// POWER_SYSTEM_MAINFRAME.cpp : 实现文件
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "POWER_SYSTEM_MAINFRAME.h"
#include "afxdialogex.h"
// POWER_SYSTEM_MAINFRAME 对话框



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


// POWER_SYSTEM_MAINFRAME 消息处理程序


int POWER_SYSTEM_MAINFRAME::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}



void POWER_SYSTEM_MAINFRAME::OnTcnSelchangeFuncTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	//把当前的页面隐藏起来
	pDlgPage[m_CurSelTab]->ShowWindow(SW_HIDE);
	//得到新的页面索引
	m_CurSelTab = func_tab.GetCurSel();
	//把新的页面显示出来
	pDlgPage[m_CurSelTab]->ShowWindow(SW_SHOW);

	*pResult = 0;
}


BOOL POWER_SYSTEM_MAINFRAME::OnInitDialog()
{
	CDialogEx::OnInitDialog();                        

	// TODO:  在此添加额外的初始化
	//为Tab Control增加页面
	func_tab.InsertItem(0, _T("查询"));
	func_tab.InsertItem(1, TEXT("我的"));
	func_tab.InsertItem(2, TEXT("添加用户"));
	//创建对话框
	query_page.Create(IDD_QUERY_TAB, &func_tab);
	info_page.Create(IDD_PERSONAL_INFO, &func_tab);
	add_user_page.Create(IDD_ADD_USER, &func_tab);
	//设定在Tab内显示的范围
	CRect rc;
	func_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	query_page.MoveWindow(&rc);
	info_page.MoveWindow(&rc);
	add_user_page.MoveWindow(&rc);
	//把对话框对象指针保存起来
	pDlgPage[0] = &query_page;
	pDlgPage[1] = &info_page;
	pDlgPage[2] = &add_user_page;
	//显示初始页面
	pDlgPage[0]->ShowWindow(SW_SHOW);
	//保存当前选择
	m_CurSelTab = 0;
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	user = pWnd->getUser();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
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

	// TODO: 在此处添加消息处理程序代码
	
}


void POWER_SYSTEM_MAINFRAME::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	pWnd->SendMessage(WM_CLOSE);

}
