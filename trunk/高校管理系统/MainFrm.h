// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////
#include "MyChildFrame.h"
#if !defined(AFX_MAINFRM_H__3F996B54_D37A_4600_AFAB_E33A20986C2A__INCLUDED_)
#define AFX_MAINFRM_H__3F996B54_D37A_4600_AFAB_E33A20986C2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();
	
// Attributes
public:
	CMyChildFrame *m_pUserChange;
	CMyChildFrame *m_pStudentInfo;
	CMyChildFrame *m_pChoiceCourse;
	CMyChildFrame *m_pCourseList;
	CMyChildFrame *m_pDelCourse;
	CMyChildFrame *m_pCourseScore;
	CMyChildFrame *m_pCETScore;
	CMyChildFrame *m_pCmpLevScore;
	BOOL m_bLogin;
	BOOL m_bItemUserChange;
	BOOL m_bItemStudentInfo;
	BOOL m_bItemChioceCourse,m_bItemCourseList;
	BOOL m_bItemDelCourse;
	BOOL m_bItemCourseScore,m_bItemCETScore,m_bItemCmpLevScore;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUpdateSystemConnect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSystemDisconnect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateStudentInfo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateChoiceCourse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelCourse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCourseList(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCourseScore(CCmdUI* pCmdUI);
	afx_msg void OnUpdateComputerLeverScore(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCetScore(CCmdUI* pCmdUI);
	afx_msg void OnUpdateUserChange(CCmdUI* pCmdUI);
	afx_msg void OnSystemConnect();
	afx_msg void OnSystemDisconnect();
	afx_msg void OnStudentInfo();
	afx_msg void OnChoiceCourse();
	afx_msg void OnDelCourse();
	afx_msg void OnCourseList();
	afx_msg void OnCourseScore();
	afx_msg void OnCetScore();
	afx_msg void OnComputerLeverScore();
	afx_msg void OnUserChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__3F996B54_D37A_4600_AFAB_E33A20986C2A__INCLUDED_)
