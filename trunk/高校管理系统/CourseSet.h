#if !defined(AFX_COURSESET_H__B2229B5C_5200_4700_9AE4_9BB9BA636B92__INCLUDED_)
#define AFX_COURSESET_H__B2229B5C_5200_4700_9AE4_9BB9BA636B92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseSet recordset

class CCourseSet : public CRecordset
{
public:
	CCourseSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCourseSet)

// Field/Param Data
	//{{AFX_FIELD(CCourseSet, CRecordset)
	CString	m_COURSE_ID;
	CString	m_COURSE_NAME;
	CString	m_COURSE_TIME;
	CTime	m_START_DATE;
	CTime	m_END_DATE;
	long	m_CENT;
	CString	m_COURSE_TEACHER;
	CString	m_REQUIRE;
	CString	m_INSTRUCTION;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseSet)
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

#endif // !defined(AFX_COURSESET_H__B2229B5C_5200_4700_9AE4_9BB9BA636B92__INCLUDED_)
