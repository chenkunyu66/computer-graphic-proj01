// CStarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "step.h"
#include "CStarDlg.h"
#include "afxdialogex.h"


// CStarDlg dialog

IMPLEMENT_DYNAMIC(CStarDlg, CDialog)

CStarDlg::CStarDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_STARDLG, pParent)
	, m_x(0)
	, m_y(0)
	, m_lenth(0)
	, m_angle(0)
{

}

CStarDlg::~CStarDlg()
{
}

void CStarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_X, m_x);
	DDX_Text(pDX, IDC_Y, m_y);
	DDX_Text(pDX, IDC_LENGTH, m_lenth);
	DDX_Text(pDX, IDC_ANGLE, m_angle);
}


BEGIN_MESSAGE_MAP(CStarDlg, CDialog)
END_MESSAGE_MAP()


// CStarDlg message handlers
