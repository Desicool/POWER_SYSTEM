// AddCharacterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "AddCharacterDlg.h"
#include "afxdialogex.h"


// CAddCharacterDlg 对话框

IMPLEMENT_DYNAMIC(CAddCharacterDlg, CDialogEx)

CAddCharacterDlg::CAddCharacterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD_CHARACTER, pParent)
{

}

CAddCharacterDlg::~CAddCharacterDlg()
{
}

void CAddCharacterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddCharacterDlg, CDialogEx)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_ADD_CHARACTER_BUTTON, &CAddCharacterDlg::OnBnClickedAddCharacterButton)
END_MESSAGE_MAP()


// CAddCharacterDlg 消息处理程序


BOOL CAddCharacterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	character = pWnd->getCharacter();
	item_list.push_back(GetDlgItem(IDC_CNAME_STATIC));

	item_list.push_back(GetDlgItem(IDC_CNAME_INPUT));

	item_list.push_back(GetDlgItem(IDC_ADD_CHARACTER_BUTTON));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CAddCharacterDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
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


void CAddCharacterDlg::OnBnClickedAddCharacterButton()
{
	// TODO: 在此添加控件通知处理程序代码
	Character* new_character = new Character();
	CString cname;
	GetDlgItem(IDC_CNAME_INPUT)->GetWindowTextW(cname);
	CString msg;
	if (new_character->add_character(UnicodeToUtf8(cname)))
		msg = CString("添加成功！");
	else
		msg = CString("出错，请稍后重试");
	MessageBox(msg);
}
