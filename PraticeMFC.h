
// PraticeMFC.h : PraticeMFC ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CPraticeMFCApp:
// �� Ŭ������ ������ ���ؼ��� PraticeMFC.cpp�� �����Ͻʽÿ�.
//

class CPraticeMFCApp : public CWinApp
{
public:
	CPraticeMFCApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPraticeMFCApp theApp;
