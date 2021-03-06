

// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "step.h"
#include "ChildView.h"
#include "CLineDlg.h"
#include "CStarDlg.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_linefmx = 0.5;
	m_linefmy = 0.5;
	m_linetox = 0.2;
	m_linetoy = 0.55;

//loacation
	m_x = 0.3;
	m_y = 0.2;
	m_lenth = 0.2;
	m_angle = 0;

}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
	ON_COMMAND(ID_STEPSTUFF_LINEDIALOG, &CChildView::OnStepstuffLinedialog)
	ON_COMMAND(ID_STEPSTUFF_STARINPUT, &CChildView::OnStepstuffStarinput)
	ON_COMMAND(ID_STEPSTUFF_STARDIALOG, &CChildView::OnStepstuffStardialog)
	ON_COMMAND(ID_STEPSTUFF_ROTATE25, &CChildView::OnStepstuffRotate25)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}





void CChildView::OnGLDraw(CDC * pDC)
{
	// TODO: Add your implementation code here.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int width, height;
	GetSize(width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, // left
		1.0, // right
		0.0, // bottom
		GLdouble(height) / GLdouble(width), // top
		1.0, // near
		-1.0); // far

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	/*
	glBegin(GL_POLYGON);
	glVertex2d(0.25, 0.25);
	glVertex2d(0.75, 0.25);
	glVertex2d(0.75, 0.75);
	glVertex2d(0.25, 0.75);
	glEnd();
	

	glBegin(GL_LINE_STRIP);
	glVertex2d(0.1, 0.1);
	glVertex2d(0.8, 0.22);
	glVertex2d(0.78, 0.9);
	glVertex2d(0.2, 0.9);
	glEnd();
	*/
	
	//glColor3b(1., 0., 1.);
	/**
	glColor3d(1., 0., 0.);
	glBegin(GL_LINES);
	glVertex2d(m_linefmx, m_linefmy);
	glVertex2d(m_linetox, m_linefmy);
	glVertex2d(m_linetox, m_linetoy);
	glVertex2d(m_linefmx, m_linetoy);
	glEnd();
	*/

	
	double m_radius = (m_lenth / 2) / cos(18 * 3.141592653/ 180);


	glColor3d(1., 1., 0.);
	//use loop to connect the location.
	glBegin(GL_LINE_LOOP);
	//five star points location. 
	//the star's angle is 72
	glVertex2d(m_x + m_radius * sin((72 * 3 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 3 - m_angle)*3.141592653 / 180));
	glVertex2d(m_x + m_radius * sin((72 * 1 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 1 - m_angle)*3.141592653 / 180));
	glVertex2d(m_x + m_radius * sin((72 * 4 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 4 - m_angle)*3.141592653 / 180));
	glVertex2d(m_x + m_radius * sin((72 * 2 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 2 - m_angle)*3.141592653 / 180));
	glVertex2d(m_x + m_radius * sin((72 * 0 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 0 - m_angle)*3.141592653 / 180));
	glEnd();

	//the location of the rectangle when the angle is 0.
	double r_x1 = m_x + m_radius * sin((72 * 4)*3.141592653 / 180);
	double r_x2 = m_x + m_radius * sin((72 * 1)*3.141592653 / 180);
	double r_x3 = m_x + m_radius * sin((72 * 1)*3.141592653 / 180);
	double r_x4 = m_x + m_radius * sin((72 * 4)*3.141592653 / 180);
	double r_y1 = m_y + m_radius * cos((72 * 3)*3.141592653 / 180);
	double r_y2 = m_y + m_radius * cos((72 * 2)*3.141592653 / 180);
	double r_y3 = m_y + m_radius * cos((72 * 0)*3.141592653 / 180);
	double r_y4 = m_y + m_radius * cos((72 * 0)*3.141592653 / 180);

	glColor3d(1., 0., 0.);
	//the following method was found online
	//https://bbs.csdn.net/topics/392263610
	//x0=(x-rx0)*cos(a)-(y-ry0)*sin(a)+rx0.
	glBegin(GL_LINE_LOOP);
	glVertex2d((r_x1 - m_x)*cos((m_angle)*3.141592653 / 180) - (r_y1 - m_y)*sin((m_angle)*3.141592653 / 180) + m_x, (r_x1 - m_x)*sin((m_angle)*3.141592653 / 180) + (r_y1 - m_y)*cos((m_angle)*3.141592653 / 180) + m_y);
	glVertex2d((r_x2 - m_x)*cos((m_angle)*3.141592653 / 180) - (r_y2 - m_y)*sin((m_angle)*3.141592653 / 180) + m_x, (r_x2 - m_x)*sin((m_angle)*3.141592653 / 180) + (r_y2 - m_y)*cos((m_angle)*3.141592653 / 180) + m_y);
	glVertex2d((r_x3 - m_x)*cos((m_angle)*3.141592653 / 180) - (r_y3 - m_y)*sin((m_angle)*3.141592653 / 180) + m_x, (r_x3 - m_x)*sin((m_angle)*3.141592653 / 180) + (r_y3 - m_y)*cos((m_angle)*3.141592653 / 180) + m_y);
	glVertex2d((r_x4 - m_x)*cos((m_angle)*3.141592653 / 180) - (r_y4 - m_y)*sin((m_angle)*3.141592653 / 180) + m_x, (r_x4 - m_x)*sin((m_angle)*3.141592653 / 180) + (r_y4 - m_y)*cos((m_angle)*3.141592653 / 180) + m_y);
	glEnd();

	/*glColor3d(1., 0., 0.);
	glBegin(GL_LINE_LOOP);
	glVertex2d(m_x + m_radius * sin((72 * 4 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 3 - m_angle)*3.141592653 / 180));
	glVertex2d(m_x + m_radius * sin((72 * 1 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 2 - m_angle)*3.141592653 / 180));
	glVertex2d(m_x + m_radius * sin((72 * 1 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 0 - m_angle)*3.141592653 / 180));
	glVertex2d(m_x + m_radius * sin((72 * 4 - m_angle)*3.141592653 / 180), m_y + m_radius * cos((72 * 0 - m_angle)*3.141592653 / 180));
	glEnd();
	*/
	
}


void CChildView::OnStepstuffLineendto0()
{
	// TODO: Add your command handler code here
	m_linetox = 0.1;
	m_linetoy = 0.1;

	Invalidate();
}


void CChildView::OnStepstuffLinedialog()
{
	// TODO: Add your command handler code here
	CLineDlg dlg;

	dlg.m_fmx = m_linefmx;
	dlg.m_fmy = m_linefmy;
	dlg.m_tox = m_linetox;
	dlg.m_toy = m_linetoy;

	if (dlg.DoModal() == IDOK)
	{
		m_linefmx = dlg.m_fmx;
		m_linefmy = dlg.m_fmy;
		m_linetox = dlg.m_tox;
		m_linetoy = dlg.m_toy;

		Invalidate();
	}
}


void CChildView::OnStepstuffStarinput()
{
	// TODO: Add your command handler code here
}


void CChildView::OnStepstuffStardialog()
{
	// TODO: Add your command handler code here
	CStarDlg dlg;

	dlg.m_x = m_x;
	dlg.m_y = m_y;
	dlg.m_lenth = m_lenth;
	dlg.m_angle = m_angle;

	if (dlg.DoModal() == IDOK)
	{
		m_x = dlg.m_x;
		m_y = dlg.m_y;
		m_lenth = dlg.m_lenth;
		m_angle = dlg.m_angle;

		Invalidate();
	}
}


void CChildView::OnStepstuffRotate25()
{
	// TODO: Add your command handler code here
	m_angle = m_angle + 25;
	Invalidate();
}
