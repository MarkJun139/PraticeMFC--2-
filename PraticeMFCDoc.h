
// PraticeMFCDoc.h : CPraticeMFCDoc Ŭ������ �������̽�
//


#pragma once


class CPraticeMFCDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CPraticeMFCDoc();
	DECLARE_DYNCREATE(CPraticeMFCDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CPraticeMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


