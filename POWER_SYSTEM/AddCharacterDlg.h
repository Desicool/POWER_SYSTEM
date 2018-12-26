#pragma once
#include <vector>
#include "POWER_SYSTEMDlg.h"
#include "solveUTF8.h"
using namespace std;
// CAddCharacterDlg �Ի���

class CAddCharacterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddCharacterDlg)

public:
	CAddCharacterDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddCharacterDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_CHARACTER };
#endif
private:
	vector<CWnd*> item_list;
	Character* character;
	CRect rc;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedAddCharacterButton();
};
