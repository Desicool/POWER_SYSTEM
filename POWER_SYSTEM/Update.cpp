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
}


BEGIN_MESSAGE_MAP(CUpdate, CDialog)
END_MESSAGE_MAP()


// CUpdate ��Ϣ�������
