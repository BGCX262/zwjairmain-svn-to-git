#if !defined(AFX_COURSELIST_H__6B4E0DFB_D4B8_4859_A138_8130826E5710__INCLUDED_)
#define AFX_COURSELIST_H__6B4E0DFB_D4B8_4859_A138_8130826E5710__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseList form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCourseList : public CFormView
{
private:
	CFont Font;
protected:
	CCourseList();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCourseList)

// Form Data
public:
	//{{AFX_DATA(CCourseList)
	enum { IDD = IDD_DIALOG5 };
	CString	m_key;
	CString	m_weekday;
	CString	m_building;
	CString	m_class;
	CString	m_cost;
	CString	m_courseID;
	CString	m_course_name;
	CString	m_dayhour;
	CString	m_room;
	CString	m_teacher;
	//}}AFX_DATA

// Attributes
public:
	
// Operations
public:
	void OnDestroy();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseList)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCourseList();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCourseList)
	afx_msg void OnButtonSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSELIST_H__6B4E0DFB_D4B8_4859_A138_8130826E5710__INCLUDED_)
