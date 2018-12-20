// AddUserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "AddUserDlg.h"
#include "afxdialogex.h"


// CAddUserDlg 对话框

IMPLEMENT_DYNAMIC(CAddUserDlg, CDialogEx)

CAddUserDlg::CAddUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_USER, pParent)
{

}

CAddUserDlg::~CAddUserDlg()
{
}

void CAddUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddUserDlg, CDialogEx)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_ADD_USER_BUTTON, &CAddUserDlg::OnBnClickedAddUserButton)
END_MESSAGE_MAP()


// CAddUserDlg 消息处理程序


void CAddUserDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

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
	
}


BOOL CAddUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//GetWindowRect(&rc);
	// TODO:  在此添加额外的初始化
	item_list.push_back(GetDlgItem(IDC_USERNAME_REG_STATIC));
	item_list.push_back(GetDlgItem(IDC_IDENTITY_REG_STATIC));
	item_list.push_back(GetDlgItem(IDC_PHONE_REG_STATIC));
	item_list.push_back(GetDlgItem(IDC_ADDRESS_REG_STATIC));
	item_list.push_back(GetDlgItem(IDC_EMAIL_REG_STATIC));

	item_list.push_back(GetDlgItem(IDC_USERNAME_REG_INPUT2));
	item_list.push_back(GetDlgItem(IDC_IDENTITY_REG_INPUT));
	item_list.push_back(GetDlgItem(IDC_PHONE_REG_INPUT));
	item_list.push_back(GetDlgItem(IDC_ADDRESS_REG_INPUT));
	item_list.push_back(GetDlgItem(IDC_EMAIL_REG_INPUT));

	item_list.push_back(GetDlgItem(IDC_ADD_USER_BUTTON));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void CAddUserDlg::OnBnClickedAddUserButton()
{
	// TODO: 在此添加控件通知处理程序代码
	User* new_user = new User();
	CString name, address, pwd = L"123456", email, identity,phone;
	GetDlgItem(IDC_USERNAME_REG_INPUT2)->GetWindowTextW(name);
	GetDlgItem(IDC_ADDRESS_REG_INPUT)->GetWindowTextW(address);
	GetDlgItem(IDC_EMAIL_REG_INPUT)->GetWindowTextW(email);
	GetDlgItem(IDC_IDENTITY_REG_INPUT)->GetWindowTextW(identity);
	GetDlgItem(IDC_PHONE_REG_INPUT)->GetWindowTextW(phone);
	new_user->setaddress((LPCSTR)(CStringA)address);
	new_user->setname((LPCSTR)(CStringA)name);
	new_user->setpassword((LPCSTR)(CStringA)pwd);
	new_user->setphoneNo((LPCSTR)(CStringA)phone);
	new_user->setidentityNo((LPCSTR)(CStringA)identity);
	new_user->setemail((LPCSTR)(CStringA)email);
	MessageBox((CString)new_user->regist().c_str());
}
