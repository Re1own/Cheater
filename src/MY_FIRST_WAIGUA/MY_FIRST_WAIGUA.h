
// MY_FIRST_WAIGUA.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMY_FIRST_WAIGUAApp:
// �йش����ʵ�֣������ MY_FIRST_WAIGUA.cpp
//

class CMY_FIRST_WAIGUAApp : public CWinApp
{
public:
	CMY_FIRST_WAIGUAApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMY_FIRST_WAIGUAApp theApp;