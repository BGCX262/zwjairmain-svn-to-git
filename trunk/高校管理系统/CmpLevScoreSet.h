#if !defined(AFX_CMPLEVSCORESET_H__4311639D_4F12_4DEF_8AC0_019599F109D0__INCLUDED_)
#define AFX_CMPLEVSCORESET_H__4311639D_4F12_4DEF_8AC0_019599F109D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CmpLevScoreSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCmpLevScoreSet recordset

class CCmpLevScoreSet : public CRecordset
{
public:
	CCmpLevScoreSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCmpLevScoreSet)

// Field/Param Data
	//{{AFX_FIELD(CCmpLevScoreSet, CRecordset)
	CString	m_STU_ID;
	CString	m_STU_NAME;
	CString	m_PERSON_ID;
	long	m_LEV1_STATE;
	long	m_LEV1_SCORE;
	long	m_LEV2_STATE;
	long	m_LEV2_SCORE;
	CString	m_TEST_PLACE;
	CTime	m_TESE_DATE;
	CString	m_DIRECTION;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmpLevScoreSet)
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

#endif // !defined(AFX_CMPLEVSCORESET_H__4311639D_4F12_4DEF_8AC0_019599F109D0__INCLUDED_)
