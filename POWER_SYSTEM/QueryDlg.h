#pragma once
#include "afxwin.h"
#include "User.h"
#include "POWER_SYSTEMDlg.h"

// CQueryDlg �Ի���

class CQueryDlg : public CDialog
{
	DECLARE_DYNAMIC(CQueryDlg)

public:
	CQueryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CQueryDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUERY_TAB };
#endif
private:
	CRect rc;
	Character* character;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CButton query_button;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedQueryButton();
};
