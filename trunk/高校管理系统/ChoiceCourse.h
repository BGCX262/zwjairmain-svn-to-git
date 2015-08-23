#if !defined(AFX_CHOICECOURSE_H__A682E6E6_CAE8_4E6E_9D81_803D2EE139CD__INCLUDED_)
#define AFX_CHOICECOURSE_H__A682E6E6_CAE8_4E6E_9D81_803D2EE139CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChoiceCourse.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoiceCourse form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CChoiceCourse : public CFormView
{
private:
	void initial();
	CFont Font;
protected:
	CChoiceCourse();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CChoiceCourse)

// Form Data
public:
	//{{AFX_DATA(CChoiceCourse)
	enum { IDD = IDD_DIALOG3 };
	CListCtrl	m_course;
	CString	m_teacher;
	CString	m_start;
	CString	m_require;
	CString	m_instruction;
	CString	m_end;
	CString	m_course_time;
	CString	m_course_name;
	CString	m_courseID;
	CString	m_cent;
	//}}AFX_DATA

// Attributes
public:
	void settext(int index);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoiceCourse)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CChoiceCourse();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CChoiceCourse)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOICECOURSE_H__A682E6E6_CAE8_4E6E_9D81_803D2EE139CD__INCLUDED_)
