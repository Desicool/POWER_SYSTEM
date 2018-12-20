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
	CString msg;
	msg.Format(_T("%d %d %d %d"), rc.top, rc.bottom, rc.left, rc.right);
	MessageBox(msg);
}
