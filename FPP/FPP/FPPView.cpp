// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// FPPView.cpp : CFPPView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "FPP.h"
#endif

#include "FPPDoc.h"
#include "FPPView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFPPView

IMPLEMENT_DYNCREATE(CFPPView, CView)

BEGIN_MESSAGE_MAP(CFPPView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFPPView ����/����

CFPPView::CFPPView()
{
	// TODO:  �ڴ˴���ӹ������

}

CFPPView::~CFPPView()
{
}

BOOL CFPPView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CFPPView ����

void CFPPView::OnDraw(CDC* /*pDC*/)
{
	CFPPDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CFPPView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFPPView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFPPView ���

#ifdef _DEBUG
void CFPPView::AssertValid() const
{
	CView::AssertValid();
}

void CFPPView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFPPDoc* CFPPView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFPPDoc)));
	return (CFPPDoc*)m_pDocument;
}
#endif //_DEBUG


// CFPPView ��Ϣ�������
