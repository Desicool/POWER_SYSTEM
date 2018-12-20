// AddUserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "AddUserDlg.h"
#include "afxdialogex.h"


// CAddUserDlg �Ի���

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


// CAddUserDlg ��Ϣ�������


void CAddUserDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

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
	
}


BOOL CAddUserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//GetWindowRect(&rc);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
				  // �쳣: OCX ����ҳӦ���� FALSE
}



void CAddUserDlg::OnBnClickedAddUserButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
