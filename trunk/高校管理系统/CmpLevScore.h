#if !defined(AFX_CMPLEVSCORE_H__9B802427_A095_486D_9CDD_1C781C86E754__INCLUDED_)
#define AFX_CMPLEVSCORE_H__9B802427_A095_486D_9CDD_1C781C86E754__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CmpLevScore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCmpLevScore form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCmpLevScore : public CFormView
{
private:
	CFont Font;
protected:
	CCmpLevScore();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCmpLevScore)

// Form Data
public:
	//{{AFX_DATA(CCmpLevScore)
	enum { IDD = IDD_DIALOG8 };
	CString	m_date;
	CString	m_direction;
	CString	m_lev1_score;
	CString	m_lev1_state;
	CString	m_lev2_score;
	CString	m_lev2_state;
	CString	m_personID;
	CString	m_place;
	CString	m_stuID;
	CString	m_stu_name;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	void initial();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmpLevScore)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCmpLevScore();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCmpLevScore)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMPLEVSCORE_H__9B802427_A095_486D_9CDD_1C781C86E754__INCLUDED_)
