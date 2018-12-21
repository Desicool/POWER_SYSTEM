// QueryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "QueryDlg.h"
#include "afxdialogex.h"


// CQueryDlg �Ի���

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


// CQueryDlg ��Ϣ�������


BOOL CQueryDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	GetWindowRect(&rc);
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	HWND hWnd = ::FindWindow(NULL, L"POWER_SYSTEM");
	CPOWER_SYSTEMDlg* pWnd = (CPOWER_SYSTEMDlg*)CPOWER_SYSTEMDlg::FromHandle(hWnd);
	character = pWnd->getCharacter();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}



void CQueryDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	CWnd *pWnd;

	pWnd = GetDlgItem(IDC_QUERY_BUTTON);

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
	GetClientRect(&rc);//���仯��ĶԻ����С��Ϊ�ɴ�С
}


void CQueryDlg::OnBnClickedQueryButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString msg, ad;
	ad = CString(character->get_character_name().c_str());
	msg.Format(_T("����ǰ�����Ϊ��\t%s\r\n����ǰ��ʹ�õĹ����У�\r\n"),ad);
	int tmp = character->getPrivilege();
	if (tmp & P_QUERY)
	{
		ad.Format(_T("\t\t��ѯ����\r\n"));
		msg += ad;
	}
	if (tmp & P_ADD_USER)
	{
		ad.Format(_T("\t\t����û�\r\n"));
		msg += ad;
	}
	if (tmp & P_UPDATE)
	{
		ad.Format(_T("\t\t�����û�Ȩ��\r\n"));
		msg += ad;
	}
	MessageBox(msg);
}
