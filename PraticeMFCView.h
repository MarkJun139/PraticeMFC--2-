
// PraticeMFCView.h : CPraticeMFCView Ŭ������ �������̽�
//


#pragma once



class CPraticeMFCView : public CView
{
protected: // serialization������ ��������ϴ�.
	CPraticeMFCView();
	DECLARE_DYNCREATE(CPraticeMFCView)

// Ư���Դϴ�.
public:
	CPraticeMFCDoc* GetDocument() const;
	//void DoDataExchange(CDataExchange* pDX);

// �۾��Դϴ�.
public:
	int height;
	int width;
	int x;
	int y;
	CEdit	m_edit;
	CEdit	m_edit2;
	CEdit	m_edit3;
	CPoint	m_pos;
	BOOL	m_drag;

	//CWeek2 m_week2;
	

	void	OnInitialUpdate();
	void	OnSize(UINT nType, int cx, int cy);
	void	OnMouseMove(UINT nFlags, CPoint point);
	void	OnLButtonDown(UINT nFlags, CPoint point);
	void	OnRButtonDown(UINT nFlags, CPoint point);
	void	OnLButtonUp(UINT nFlags, CPoint point);
	void	OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

	void	SetText();
	void	SetText2(CString str);
	void	DrawTimer();

	void	OnTimer(UINT_PTR nIDEvent);


	UINT_PTR m_timer;

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	afx_msg int			 OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void		 OnDestroy();

// �����Դϴ�.
public:
	virtual ~CPraticeMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // PraticeMFCView.cpp�� ����� ����
inline CPraticeMFCDoc* CPraticeMFCView::GetDocument() const
   { return reinterpret_cast<CPraticeMFCDoc*>(m_pDocument); }
#endif

