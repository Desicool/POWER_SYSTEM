
// POWER_SYSTEM.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPOWER_SYSTEMApp: 
// �йش����ʵ�֣������ POWER_SYSTEM.cpp
//

class CPOWER_SYSTEMApp : public CWinApp
{
public:
	CPOWER_SYSTEMApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPOWER_SYSTEMApp theApp;
