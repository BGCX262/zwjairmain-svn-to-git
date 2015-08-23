// hoiceCourse.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "hoiceCourse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChoiceCourse

IMPLEMENT_DYNCREATE(ChoiceCourse, CFormView)

ChoiceCourse::ChoiceCourse()
	: CFormView(ChoiceCourse::IDD)
{
	//{{AFX_DATA_INIT(ChoiceCourse)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

ChoiceCourse::~ChoiceCourse()
{
}

void ChoiceCourse::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChoiceCourse)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ChoiceCourse, CFormView)
	//{{AFX_MSG_MAP(ChoiceCourse)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ChoiceCourse diagnostics

#ifdef _DEBUG
void ChoiceCourse::AssertValid() const
{
	CFormView::AssertValid();
}

void ChoiceCourse::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ChoiceCourse message handlers
