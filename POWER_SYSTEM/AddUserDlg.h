#pragma once
#include <vector>
#include "User.h"
using namespace std;

// CAddUserDlg �Ի���

class CAddUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddUserDlg)
private:
	CRect rc;
	vector<CWnd*> item_list;
public:
	CAddUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddUserDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedAddUserButton();
};
