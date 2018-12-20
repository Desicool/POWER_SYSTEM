#pragma once
#include "afxwin.h"
#include "User.h"
#include "POWER_SYSTEMDlg.h"

// CQueryDlg 对话框

class CQueryDlg : public CDialog
{
	DECLARE_DYNAMIC(CQueryDlg)

public:
	CQueryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CQueryDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUERY_TAB };
#endif
private:
	CRect rc;
	Character* character;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton query_button;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedQueryButton();
};
