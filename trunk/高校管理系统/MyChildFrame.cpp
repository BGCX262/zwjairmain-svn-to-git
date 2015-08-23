// MyChildFrame.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "MyChildFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyChildFrame

IMPLEMENT_DYNCREATE(CMyChildFrame, CMDIChildWnd)

CMyChildFrame::CMyChildFrame()
{
}

CMyChildFrame::~CMyChildFrame()
{
}


BEGIN_MESSAGE_MAP(CMyChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CMyChildFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyChildFrame message handlers
