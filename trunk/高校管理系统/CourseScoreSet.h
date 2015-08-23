#if !defined(AFX_COURSESCORESET_H__80DC74FA_ADB2_47AB_ADEC_1108D6DD6CD1__INCLUDED_)
#define AFX_COURSESCORESET_H__80DC74FA_ADB2_47AB_ADEC_1108D6DD6CD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseScoreSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseScoreSet recordset

class CCourseScoreSet : public CRecordset
{
public:
	CCourseScoreSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCourseScoreSet)

// Field/Param Data
	//{{AFX_FIELD(CCourseScoreSet, CRecordset)
	CString	m_STU_ID;
	CString	m_COURSE_ID;
	CString	m_COURSE_NAME;
	long	m_SCORE;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseScoreSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSESCORESET_H__80DC74FA_ADB2_47AB_ADEC_1108D6DD6CD1__INCLUDED_)
