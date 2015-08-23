#if !defined(AFX_USERCHANGE_H__85C0AD15_F3D4_4C6B_A467_A8151A3FF6E5__INCLUDED_)
#define AFX_USERCHANGE_H__85C0AD15_F3D4_4C6B_A467_A8151A3FF6E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserChange.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// UserChange form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CUserChange : public CFormView
{
private:
	CFont Font;
protected:
	CUserChange();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CUserChange)

// Form Data
public:
	//{{AFX_DATA(UserChange)
	enum { IDD = IDD_DIALOG1 };
	CString	m_old;
	CString	m_new;
	CString	m_new_sure;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:
	VOID OnDestroy();
	void OnInitialUpdate();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(UserChange)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
private:
		CFont LoginFont;

// Implementation
protected:
	virtual ~CUserChange();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(UserChange)
	afx_msg void OnButtonChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERCHANGE_H__85C0AD15_F3D4_4C6B_A467_A8151A3FF6E5__INCLUDED_)
