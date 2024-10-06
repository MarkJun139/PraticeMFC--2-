
// PraticeMFCView.cpp : CPraticeMFCView Ŭ������ ����
//

#include "stdafx.h"
#include "PraticeMFC.h"

#include "PraticeMFCDoc.h"
#include "PraticeMFCView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPraticeMFCView

IMPLEMENT_DYNCREATE(CPraticeMFCView, CView)

BEGIN_MESSAGE_MAP(CPraticeMFCView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()




// CPraticeMFCView ����/�Ҹ�

CPraticeMFCView::CPraticeMFCView()
{
	//AfxMessageBox(L"������ ����");
}

CPraticeMFCView::~CPraticeMFCView()
{
	//AfxMessageBox(L"������ �Ҹ�");
	//delete m_week2;
}


int CPraticeMFCView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if(CView::OnCreate(lpCreateStruct) == -1)
	{	
		return -1;
	}
	AfxMessageBox(L"�����찡 �����Ǿ����ϴ�.");
	return 0;

}

void CPraticeMFCView::OnDestroy()
{
	AfxMessageBox(L"�����찡 ����Ǿ����ϴ�.");
	CView::OnDestroy();

	KillTimer(m_timer);
}




BOOL CPraticeMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}


void CPraticeMFCView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_drag = FALSE;
	m_edit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(10, 10, 500, 40), this, 1);
	m_edit2.Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(10, 90, 500, 120), this, 2);
	m_edit3.Create(WS_CHILD | WS_VISIBLE, CRect(10, 150, 300, 180), this, 3);
	SetText();

	m_timer = NULL;

}

void CPraticeMFCView::OnSize(UINT nType, int cx, int cy)
{
	//Wnd ������ ���� �� ȣ��
	CView::OnSize(nType, cx, cy);

	width = cx;
	height = cy;

	if(m_edit.GetSafeHwnd())
	{
		SetText();
	}

}

void CPraticeMFCView::OnMouseMove(UINT nFlags, CPoint point)
{
// 	m_pos = point;
// 	Invalidate();
// 	if(m_drag == TRUE)
// 	{
// 		SetText2(L"�巡�� ��");
// 	}
// 	else if(m_drag == FALSE)
// 	{	
// 		SetText2(L"���콺�� �̵���");
// 	}
// 	CView::OnMouseMove(nFlags, point);
}	


void CPraticeMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
// 	m_drag = TRUE;
// 	SetText2(L"���� ���콺 Ŭ��");
// 	CView::OnLButtonDown(nFlags, point);
	m_timer = SetTimer(1, 1000, NULL);
	DrawTimer();
}

void CPraticeMFCView::OnRButtonDown(UINT nFlags, CPoint point)
{
// 	SetText2(L"������ ���콺 Ŭ��");
// 	CView::OnRButtonDown(nFlags, point);
	KillTimer(m_timer);
	SetText2(L"");
}


void CPraticeMFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if(m_drag == TRUE)
	{
		m_drag = FALSE;
		SetText2(L"���콺�� �̵���");
		
	}
	CView::OnLButtonUp(nFlags, point);
}

void CPraticeMFCView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString tem;
	//tem.Format(L"%d Ű�ٿ�", nChar);
	//SetText2(tem);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);

	if(nChar == 37 || nChar == 38 || nChar == 39 || nChar == 40)
	{
		CRect rect;
		m_edit3.GetWindowRect(&rect);
		ScreenToClient(&rect);

		CRect clientRect;
		GetClientRect(&clientRect);

		int x, y, x2, y2;

		if(m_timer != NULL)
		{

			if(nChar == 37)
			{
				rect.OffsetRect(-5, 0);

				x = rect.left;
				y = rect.top;

				if(x < 10)
				{
					AfxMessageBox(L"���̻� �������� �̵��� �� �����ϴ�!");
				}
				else
				{
					m_edit3.MoveWindow(&rect);
				}
				
		
			}
			if(nChar == 38)
			{
				rect.OffsetRect(0, -10);

				x = rect.left;
				y = rect.top;

				if(y < 0)
				{
					AfxMessageBox(L"���̻� �������� �̵��� �� �����ϴ�!");
				}
				else
				{
					m_edit3.MoveWindow(&rect);
				}


			}
			if(nChar == 39)
			{

				rect.OffsetRect(5, 0);

				x2 = clientRect.right;
				y2 = clientRect.bottom;

				x = rect.right;
				y = rect.top;

				if(x > x2)
				{
					AfxMessageBox(L"���̻� ���������� �̵��� �� �����ϴ�!");
				}
				else
				{
					m_edit3.MoveWindow(&rect);
				}

			
			}
			if(nChar == 40)
			{
				rect.OffsetRect(0, 5);

				x2 = clientRect.right;
				y2 = clientRect.bottom;

				x = rect.right;
				y = rect.bottom;

				if(y > y2)
				{
					AfxMessageBox(L"���̻� �Ʒ������� �̵��� �� �����ϴ�!");
				}
				else
				{
					m_edit3.MoveWindow(&rect);
				}

			
			}	
		}
	}
}

void CPraticeMFCView::SetText()
{	
	CString temp;
	temp.Format(L"������ ũ���� �ʺ�� %d, ���̴� %d, ���̴� %d�Դϴ�.", width, height, width*height);
	m_edit.SetWindowText(temp);
}

void CPraticeMFCView::SetText2(CString str)
{
	CString temp;
	temp.Format(L"%s", str);
	m_edit3.SetWindowText(temp);
}

void CPraticeMFCView::DrawTimer()
{
	if(m_timer != NULL)
	{
		CTime cTime = CTime::GetCurrentTime();

		CString strTime;
		strTime.Format(_T("����� %04d�� %02d�� %02d�� %02d�� %02d�� %02d��"),
			cTime.GetYear(),
			cTime.GetMonth(),
			cTime.GetDay(),
			cTime.GetHour(),
			cTime.GetMinute(),
			cTime.GetSecond());

		SetText2(strTime);
	}
}

void CPraticeMFCView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == m_timer)
	{
		Invalidate();
	}
	CView::OnTimer(nIDEvent);
}

void CPraticeMFCView::OnDraw(CDC* /*pDC*/)
{
	
	CPraticeMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CString strPoint;
	strPoint.Format(_T("���콺 ��ǥ (%4d, %4d)"), m_pos.x, m_pos.y);
	m_edit2.SetWindowText(strPoint);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	DrawTimer();

}


// CPraticeMFCView �μ�

BOOL CPraticeMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPraticeMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPraticeMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CPraticeMFCView ����

#ifdef _DEBUG
void CPraticeMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CPraticeMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPraticeMFCDoc* CPraticeMFCView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPraticeMFCDoc)));
	return (CPraticeMFCDoc*)m_pDocument;
}


#endif //_DEBUG


// CPraticeMFCView �޽��� ó����
