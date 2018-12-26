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


	return 0;
}



void POWER_SYSTEM_MAINFRAME::OnTcnSelchangeFuncTab(NMHDR *pNMHDR, LRESULT *pResult)
{
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
	this->SetWindowTextW(L"权限系统");
	//获取当前用户与权限角色
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	user = pWnd->getUser();
	character = pWnd->getCharacter();
	//设定在Tab内显示的范围
	CRect rc;
	func_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	//为Tab Control增加页面
	int nItem = 0;
	bool flag = true;
	if (character->getPrivilege() & P_QUERY)
	{
		func_tab.InsertItem(nItem, _T("查询"));
		pDlgPage[nItem++] = &query_page;
		query_page.Create(IDD_QUERY_TAB, &func_tab);
		query_page.MoveWindow(&rc);
	}
	if (character->getPrivilege() & P_ADD_USER)
	{
		func_tab.InsertItem(nItem, TEXT("添加用户"));
		pDlgPage[nItem++] = &add_user_page;
		add_user_page.Create(IDD_ADD_USER, &func_tab);
		add_user_page.MoveWindow(&rc);
	}
	if (character->getPrivilege() & P_UPDATE)
	{
		func_tab.InsertItem(nItem, TEXT("更新用户权限"));
		pDlgPage[nItem++] = &update_page;
		update_page.Create(IDD_UPDATE, &func_tab);
		update_page.MoveWindow(&rc);
	}
	if (character->getPrivilege() & P_DISTRIBUTE_CHARACTER)
	{
		func_tab.InsertItem(nItem, TEXT("分配角色"));
		pDlgPage[nItem++] = &d_characterDlg;
		flag = false;
		d_characterDlg.Create(IDD_DISTRIBUTE_CHARACTER, &func_tab);
		d_characterDlg.MoveWindow(&rc);
		d_characterDlg.setLists(true);
	}
	if (character->getPrivilege() & P_DISTRIBUTE_FUNC)
	{
		func_tab.InsertItem(nItem, TEXT("分配功能"));
		pDlgPage[nItem++] = &d_characterDlg;
		if (flag)
		{
			d_characterDlg.Create(IDD_DISTRIBUTE_CHARACTER, &func_tab);
			d_characterDlg.MoveWindow(&rc);
			d_characterDlg.setLists(false);
			flag = true;
		}
		//d_functionDlg.Create(IDD_DISTRIBUTE_FUNC, &func_tab);
		//d_functionDlg.MoveWindow(&rc);
		//d_functionDlg.setLists(false);
	}
	if (character->getPrivilege() & P_ADD_CHARACTER)
	{
		func_tab.InsertItem(nItem, TEXT("添加角色"));
		pDlgPage[nItem++] = &add_character_page;
		add_character_page.Create(IDD_ADD_CHARACTER, &func_tab);
		add_character_page.MoveWindow(&rc);
	}
	func_tab.InsertItem(nItem, TEXT("我的"));
	info_page.Create(IDD_PERSONAL_INFO, &func_tab);
	pDlgPage[nItem++] = &info_page;
	info_page.MoveWindow(&rc);
	CDialog* m_page = new CDialog();
	
	//显示初始页面
	pDlgPage[0]->ShowWindow(SW_SHOW);
	//保存当前选择
	m_CurSelTab = 0;
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
	
}


void POWER_SYSTEM_MAINFRAME::OnClose()
{

	CDialogEx::OnClose();
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	pWnd->SendMessage(WM_CLOSE);

}
