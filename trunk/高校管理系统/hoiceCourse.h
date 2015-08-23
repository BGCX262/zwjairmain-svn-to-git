#if !defined(AFX_HOICECOURSE_H__2F0C9688_AADF_4DAC_9AAB_1C864A90813F__INCLUDED_)
#define AFX_HOICECOURSE_H__2F0C9688_AADF_4DAC_9AAB_1C864A90813F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hoiceCourse.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ChoiceCourse form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class ChoiceCourse : public CFormView
{
protected:
	ChoiceCourse();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(ChoiceCourse)

// Form Data
public:
	//{{AFX_DATA(ChoiceCourse)
	enum { IDD = IDD_HOICECOURSE_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChoiceCourse)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~ChoiceCourse();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(ChoiceCourse)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOICECOURSE_H__2F0C9688_AADF_4DAC_9AAB_1C864A90813F__INCLUDED_)
