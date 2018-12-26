// AddCharacterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "AddCharacterDlg.h"
#include "afxdialogex.h"


// CAddCharacterDlg �Ի���

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


// CAddCharacterDlg ��Ϣ�������


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
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CAddCharacterDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
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


void CAddCharacterDlg::OnBnClickedAddCharacterButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Character* new_character = new Character();
	CString cname;
	GetDlgItem(IDC_CNAME_INPUT)->GetWindowTextW(cname);
	CString msg;
	if (new_character->add_character(UnicodeToUtf8(cname)))
		msg = CString("��ӳɹ���");
	else
		msg = CString("�������Ժ�����");
	MessageBox(msg);
}
