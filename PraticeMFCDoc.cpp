
// PraticeMFCDoc.cpp : CPraticeMFCDoc Ŭ������ ����
//

#include "stdafx.h"
#include "PraticeMFC.h"

#include "PraticeMFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPraticeMFCDoc

IMPLEMENT_DYNCREATE(CPraticeMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CPraticeMFCDoc, CDocument)
END_MESSAGE_MAP()


// CPraticeMFCDoc ����/�Ҹ�

CPraticeMFCDoc::CPraticeMFCDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CPraticeMFCDoc::~CPraticeMFCDoc()
{
}

BOOL CPraticeMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CPraticeMFCDoc serialization

void CPraticeMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CPraticeMFCDoc ����

#ifdef _DEBUG
void CPraticeMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPraticeMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPraticeMFCDoc ���
