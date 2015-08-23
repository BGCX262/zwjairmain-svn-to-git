#if !defined(AFX_DELCOURSE_H__1207C08A_CE44_4B2F_86DB_BE6570EEB821__INCLUDED_)
#define AFX_DELCOURSE_H__1207C08A_CE44_4B2F_86DB_BE6570EEB821__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DelCourse.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDelCourse form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CDelCourse : public CFormView
{
private:
	void settext(int index);
	void initial();
	CFont Font;
protected:
	CDelCourse();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDelCourse)

// Form Data
public:
	//{{AFX_DATA(CDelCourse)
	enum { IDD = IDD_DIALOG4 };
	CListCtrl	m_course;
	CString	m_cent;
	CString	m_courseID;
	CString	m_course_name;
	CString	m_course_time;
	CString	m_end;
	CString	m_instruction;
	CString	m_require;
	CString	m_start;
	CString	m_teacher;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelCourse)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDelCourse();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CDelCourse)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELCOURSE_H__1207C08A_CE44_4B2F_86DB_BE6570EEB821__INCLUDED_)
