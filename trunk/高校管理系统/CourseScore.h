#if !defined(AFX_COURSESCORE_H__D47E4CFB_E9D9_4486_8C89_0D8C39ACC15E__INCLUDED_)
#define AFX_COURSESCORE_H__D47E4CFB_E9D9_4486_8C89_0D8C39ACC15E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseScore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseScore form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CCourseScore : public CFormView
{
private:
	CFont Font;
protected:
	CCourseScore();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCourseScore)

// Form Data
public:
	//{{AFX_DATA(CCourseScore)
	enum { IDD = IDD_DIALOG6 };
	CListCtrl	m_course;
	CString	m_courseID;
	CString	m_course_name;
	CString	m_stuID;
	CString	m_score;
	//}}AFX_DATA

// Attributes
public:
	void initial();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseScore)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCourseScore();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCourseScore)
	afx_msg void OnClickListCourseScore(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSESCORE_H__D47E4CFB_E9D9_4486_8C89_0D8C39ACC15E__INCLUDED_)
