// CLineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "step.h"
#include "CLineDlg.h"
#include "afxdialogex.h"


// CLineDlg dialog

IMPLEMENT_DYNAMIC(CLineDlg, CDialog)

CLineDlg::CLineDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LINEDLG, pParent)
	, m_fmx(0)
	, m_fmy(0)
	, m_tox(0)
	, m_toy(0)
{

}

CLineDlg::~CLineDlg()
{
}

void CLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FMX, m_fmx);
	DDX_Text(pDX, IDC_FMY, m_fmy);
	DDX_Text(pDX, IDC_TOX, m_tox);
	DDX_Text(pDX, IDC_TOY, m_toy);
}


BEGIN_MESSAGE_MAP(CLineDlg, CDialog)
	ON_EN_CHANGE(IDC_FMX, &CLineDlg::OnEnChangeFmx)
END_MESSAGE_MAP()


// CLineDlg message handlers


void CLineDlg::OnEnChangeFmx()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
