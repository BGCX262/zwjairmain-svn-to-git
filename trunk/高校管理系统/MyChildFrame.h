#if !defined(AFX_MYCHILDFRAME_H__6745C1AF_91DB_4D3B_AA67_A289D35832EB__INCLUDED_)
#define AFX_MYCHILDFRAME_H__6745C1AF_91DB_4D3B_AA67_A289D35832EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyChildFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyChildFrame frame

class CMyChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CMyChildFrame)
public:
	CMyChildFrame();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyChildFrame)
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyChildFrame();

	// Generated message map functions
	//{{AFX_MSG(CMyChildFrame)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCHILDFRAME_H__6745C1AF_91DB_4D3B_AA67_A289D35832EB__INCLUDED_)
