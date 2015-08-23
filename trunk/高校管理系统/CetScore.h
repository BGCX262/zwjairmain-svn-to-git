#if !defined(AFX_CETSCORE_H__A6342DBA_55FC_4417_9F25_4557D99156CA__INCLUDED_)
#define AFX_CETSCORE_H__A6342DBA_55FC_4417_9F25_4557D99156CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CetScore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCetScore form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCetScore : public CFormView
{
private:
	CFont Font;
protected:
	CCetScore();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCetScore)

// Form Data
public:
	//{{AFX_DATA(CCetScore)
	enum { IDD = IDD_DIALOG7 };
	CString	m_type;
	CString	m_cet4_score;
	CString	m_cet4_state;
	CString	m_cet6_score;
	CString	m_cet6_state;
	CString	m_date;
	CString	m_direction;
	CString	m_personID;
	CString	m_place;
	CString	m_stuID;
	CString	m_stu_name;
	//}}AFX_DATA

// Attributes
public:
	void initial();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCetScore)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCetScore();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCetScore)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CETSCORE_H__A6342DBA_55FC_4417_9F25_4557D99156CA__INCLUDED_)
