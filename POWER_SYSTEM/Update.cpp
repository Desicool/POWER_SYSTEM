// Update.cpp : 实现文件
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "Update.h"
#include "afxdialogex.h"


// CUpdate 对话框

IMPLEMENT_DYNAMIC(CUpdate, CDialog)

CUpdate::CUpdate(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_UPDATE, pParent)
{

}

CUpdate::~CUpdate()
{
}

void CUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USER_LIST, user_list);
	DDX_Control(pDX, IDC_BAN_BUTTON, ban_button);
	DDX_Control(pDX, IDC_FREE_BUTTON, free_button);
}


BEGIN_MESSAGE_MAP(CUpdate, CDialog)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BAN_BUTTON, &CUpdate::OnBnClickedBanButton)
END_MESSAGE_MAP()


// CUpdate 消息处理程序


BOOL CUpdate::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetWindowRect(&rc);
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	user = pWnd->getUser();

	item_list.push_back(GetDlgItem(IDC_USER_LIST));
	item_list.push_back(GetDlgItem(IDC_BAN_BUTTON));
	item_list.push_back(GetDlgItem(IDC_FREE_BUTTON));

	//初始化用户列表
	CFont* m_font = new CFont();
	m_font->CreatePointFont(150, LPCTSTR("Arial"), NULL);
	user_list.SetFont(m_font);
	vector<CString>uname = user->get_all();
	for (auto p : uname)
	{
		user_list.AddString(p);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CUpdate::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
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

	// TODO: 在此处添加消息处理程序代码
}


void CUpdate::OnBnClickedBanButton()
{
	// TODO: 在此添加控件通知处理程序代码
	int cur = user_list.GetCurSel();
	CString name;
	user_list.GetText(cur, name);
	CString msg;
	if (user->ban_user((LPCSTR)(CStringA)name))
		msg = CString("操作成功，已禁止该用户登录");
	else
		msg = CString("出现错误，请重试");
	MessageBox(msg);
}
