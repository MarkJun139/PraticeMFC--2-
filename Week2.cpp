
#pragma once
#include "stdafx.h"
#include "PraticeMFC.h"
#include "Week2.h"

#include "PraticeMFCDoc.h"
#include "PraticeMFCView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPraticeMFCView

IMPLEMENT_DYNCREATE(CWeek2, CView)

BEGIN_MESSAGE_MAP(CWeek2, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

void CWeek2::OnDraw(CDC* pDC)
{

}

int CWeek2::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if(CView::OnCreate(lpCreateStruct) == -1)
	{
		AfxMessageBox(L"������ ����");
		return -1;
	}
}

void CWeek2::OnDestroy()
{
	AfxMessageBox(L"������ ����");
	CView::OnDestroy();
}


BOOL CWeek2::PreCreateWindow(CREATESTRUCT& cs)
{
	return TRUE;
}

BOOL CWeek2::OnPreparePrinting(CPrintInfo* pInfo)
{
	return TRUE;
}

void CWeek2::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{

}

void CWeek2::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{

}

// CPraticeMFCView ����/�Ҹ�

CWeek2::CWeek2()
{
}

CWeek2::~CWeek2()
{
}

