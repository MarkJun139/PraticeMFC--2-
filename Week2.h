#pragma once

class CWeek2 : public CView
{
protected:
	CWeek2();
	DECLARE_DYNCREATE(CWeek2);

//Ư���Դϴ�.
public:
	

//�۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	int			 OnCreate(LPCREATESTRUCT lpCreateStruct);
	void		 OnDestroy();


// �����Դϴ�.
public:
	virtual ~CWeek2();


protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};