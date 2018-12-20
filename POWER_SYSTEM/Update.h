#pragma once


// CUpdate 对话框

class CUpdate : public CDialog
{
	DECLARE_DYNAMIC(CUpdate)

public:
	CUpdate(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUpdate();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
