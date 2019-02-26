
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "graphics/OpenGLWnd.h"


// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void OnGLDraw(CDC * pDC);

//member valuable
private:
	double m_linefmx;
	double m_linefmy;
	double m_linetox;
	double m_linetoy;
	double m_x;
	double m_y;
	double m_angle;
	double m_lenth;
public:
	afx_msg void OnStepstuffLineendto0();
	afx_msg void OnStepstuffLinedialog();

	afx_msg void OnStepstuffStarinput();
	afx_msg void OnStepstuffStardialog();
	afx_msg void OnStepstuffRotate25();
};

