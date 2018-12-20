#pragma once
#include <vector>
#include "User.h"
using namespace std;

// CAddUserDlg 对话框

class CAddUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddUserDlg)
private:
	CRect rc;
	vector<CWnd*> item_list;
public:
	CAddUserDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddUserDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddUserButton();
};
