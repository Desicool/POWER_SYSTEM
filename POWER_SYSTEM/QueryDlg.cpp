// QueryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "QueryDlg.h"
#include "afxdialogex.h"


// CQueryDlg 对话框

IMPLEMENT_DYNAMIC(CQueryDlg, CDialog)

CQueryDlg::CQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_QUERY_TAB, pParent)
{

}

CQueryDlg::~CQueryDlg()
{
}

void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_QUERY_BUTTON, query_button);
}


BEGIN_MESSAGE_MAP(CQueryDlg, CDialog)
ON_WM_SIZE()
ON_BN_CLICKED(IDC_QUERY_BUTTON, &CQueryDlg::OnBnClickedQueryButton)
END_MESSAGE_MAP()


// CQueryDlg 消息处理程序


BOOL CQueryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	GetWindowRect(&rc);
	// TODO:  在此添加额外的初始化
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	character = pWnd->getCharacter();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void CQueryDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	CWnd *pWnd;

	pWnd = GetDlgItem(IDC_QUERY_BUTTON);

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


void CQueryDlg::OnBnClickedQueryButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CString msg, ad;
	ad = CString(character->get_character_name().c_str());
	msg.Format(_T("您当前的身份为：\t%s\r\n您当前可使用的功能有：\r\n"),ad);
	int tmp = character->getPrivilege();
	if (tmp & P_QUERY)
	{
		ad.Format(_T("\t\t查询功能\r\n"));
		msg += ad;
	}
	if (tmp & P_ADD_USER)
	{
		ad.Format(_T("\t\t添加用户\r\n"));
		msg += ad;
	}
	if (tmp & P_UPDATE)
	{
		ad.Format(_T("\t\t更新用户权限\r\n"));
		msg += ad;
	}
	MessageBox(msg);
}
