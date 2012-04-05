// ChildView.cpp : CChildView ���ʵ��
//

#include "stdafx.h"
#include "Demo.h"
#include "ChildView.h"
#include ".\childview.h"
#include "gldemo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_CREATE()
ON_WM_CREATE()
ON_WM_SIZE()
//ON_WM_SIZING()
ON_WM_ERASEBKGND()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()



// CChildView ��Ϣ�������

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{ 
	if (!CWnd::PreCreateWindow(cs))
		return FALSE; 

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);


	return TRUE;
}



void CChildView::OnPaint() 
{
	CPaintDC dc(this); // ���ڻ��Ƶ��豸������
	
	// TODO: �ڴ˴������Ϣ����������
	// ��ҪΪ������Ϣ������ CWnd::OnPaint()
	if (m_rotate == FALSE) {
		return;
	}
	GLPaint();
	Invalidate(FALSE);
}




int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pDC = new CClientDC(this);
	m_rotate = TRUE;

	GLCreate(m_pDC->GetSafeHdc());
	return 0;
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	GLResize(cx, cy);
	// TODO: �ڴ˴������Ϣ����������
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return TRUE;
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nChar == VK_LEFT) {
		GLChangeFilter();
	}
	if (nChar == VK_RIGHT) {
		GLChangeEnvMode();
	}
	if (nChar == VK_SPACE) {
		GLChangeDemo();
	}
	Invalidate(FALSE);

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
