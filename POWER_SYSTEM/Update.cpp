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
}


BEGIN_MESSAGE_MAP(CUpdate, CDialog)
END_MESSAGE_MAP()


// CUpdate 消息处理程序
