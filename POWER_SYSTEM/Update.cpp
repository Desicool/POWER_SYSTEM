// Update.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "Update.h"
#include "afxdialogex.h"


// CUpdate �Ի���

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


// CUpdate ��Ϣ�������


BOOL CUpdate::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetWindowRect(&rc);
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	user = pWnd->getUser();

	item_list.push_back(GetDlgItem(IDC_USER_LIST));
	item_list.push_back(GetDlgItem(IDC_BAN_BUTTON));
	item_list.push_back(GetDlgItem(IDC_FREE_BUTTON));

	//��ʼ���û��б�
	CFont* m_font = new CFont();
	m_font->CreatePointFont(150, LPCTSTR("Arial"), NULL);
	user_list.SetFont(m_font);
	vector<CString>uname = user->get_all();
	for (auto p : uname)
	{
		user_list.AddString(p);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CUpdate::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
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

	// TODO: �ڴ˴������Ϣ����������
}


void CUpdate::OnBnClickedBanButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int cur = user_list.GetCurSel();
	CString name;
	user_list.GetText(cur, name);
	CString msg;
	if (user->ban_user((LPCSTR)(CStringA)name))
		msg = CString("�����ɹ����ѽ�ֹ���û���¼");
	else
		msg = CString("���ִ���������");
	MessageBox(msg);
}
