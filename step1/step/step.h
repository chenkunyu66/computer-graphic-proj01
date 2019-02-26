
// step.h : main header file for the step application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CstepApp:
// See step.cpp for the implementation of this class
//

class CstepApp : public CWinApp
{
public:
	CstepApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CstepApp theApp;
