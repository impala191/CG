// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"

#include <stack>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
//#include<stack>


#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(IDM_SEEDFILL, OnSeedfill)
	ON_COMMAND(IDM_LINE, OnLine)
	ON_COMMAND(IDM_RECTANGLE, OnRectangle)
	ON_COMMAND(IDM_POLYGON, OnPolygon)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView construction/destruction

CDrawView::CDrawView()
{
	// TODO: add construction code here
	m_ptStart=m_ptEnd=(0,0);
	m_drawType=0;

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView printing

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

EDGE* CDrawView::GetET(CArray<CPoint,CPoint>* m_ptArray)
{

	EDGE* pHead =NULL;
	EDGE* p=NULL;
	for(int i=0;i<m_ptArray->GetSize();i++)
	{
		//用当前点和下一个点 ，构成一条边
		CPoint point1=(CPoint)m_ptArray->GetAt(i);
		CPoint point2;
		if(i==m_ptArray->GetSize()-1)
			point2=(CPoint)m_ptArray->GetAt(0);
		else
			point2=(CPoint)m_ptArray->GetAt(i+1);
		if(point1.y==point2.y)//不考虑平行x轴的边
			continue;
		EDGE* edge=new EDGE();//构造边结构
		//这里是斜率的倒数
		edge->fm=(double)(point2.x-point1.x)/(point2.y-point1.y);
		if(point1.y>point2.y)
		{
			edge->ymax=point1.y;edge->ymin=point2.y;
			edge->xmin=point2.x;
		}
		else
		{
			edge->ymax=point2.y;edge->ymin=point1.y;
			edge->xmin=point1.x;
		}
		edge->next=NULL;edge->last=NULL;
		if(p==NULL)
		{
			pHead=edge;p=edge;
		}
		else
		{
			p->next=edge;
			edge->last=p;
			p=edge;
		}
	}
	p=pHead;

	EDGE* pNext=NULL;
	while(p!=NULL)
	{
		//如果没有下面一条边了，就和第一条比较
		if(p->next==NULL)
		{
			pNext=pHead;
		}
		else
			pNext=p->next;
		//如果两条边分别在点的两侧，则不是局部极大/极小点
		if(p->ymin!=pNext->ymin&&p->ymax!=pNext->ymax)
		{
			if(p->ymax>pNext->ymax)//缩减上面那条边的端点
			{
				p->ymin++;
				p->xmin+=p->fm;
			}
			else
			{
				pNext->ymin++;
				pNext->xmin+=pNext->fm;
			}
		}
		p=p->next;
	}
	SortET(pHead);//对链表进行排序
    return pHead;///返回排序好的链表
}

void CDrawView::SortET(EDGE *pEDGE)
{

	EDGE* p1=pEDGE;
	EDGE* p2=NULL;
	
	while(p1!=NULL)
	{
		p2=p1->next;
		while(p2!=NULL)
		{
			//ymin也是索引值
			if(p1->ymin>p2->ymin||(p1->ymin==p2->ymin&&p1->xmin>p2->xmin))
			{
				int cid; double cdd;
				cid=p1->ymax;p1->ymax=p2->ymax;p2->ymax=cid;
				cid=p1->ymin;p1->ymin=p2->ymin;p2->ymin=cid;
				cdd=p1->xmin;p1->xmin=p2->xmin;p2->xmin=cdd;
				cdd=p1->fm;p1->fm=p2->fm;p2->fm=cdd;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}

}


void CDrawView::SortAET(EDGE *pEDGE)
{
	EDGE* p1=pEDGE;
	EDGE* p2=NULL;
	
	while(p1!=NULL)
	{
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->xmin>p2->xmin)
			{
				int cid;double cdd;
				cid=p1->ymax;p1->ymin=p2->ymin;p2->ymin=cid;
				cdd=p1->xmin;p1->xmin=p2->xmin;p2->xmin=cdd;
				cdd=p1->fm;p1->fm=p2->fm;p2->fm=cdd;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}


void CDrawView::Polygonfill(CDC *pDC,CArray<CPoint,CPoint>* m_ptArray,COLORREF color)
{
    EDGE* pET=GetET(m_ptArray);
    EDGE* pAET=NULL;
    int y=pET->ymin;
    int ymax=pET->ymax;
    while(y<=ymax)
    {
       while(pET!=NULL&&pET->ymin==y)
       {
          EDGE*p=pET;
          pET=pET->next;
          p->next=NULL;
          if(pAET==NULL)
          {
              pAET=p;
          }
          else
          {
              pAET->next=p;
              p->last=pAET;
              pAET=p;
          }
          if(ymax<pAET->ymax)
              ymax=pAET->ymax;
       }
       while(pAET->last!=NULL)
       {
          pAET=pAET->last;
       }
       SortAET(pAET);
       EDGE* pFill=pAET;

       while(pFill!=NULL)
       {
          for(int i=(int)pFill->xmin;i<=(int)pFill->next->xmin;i++)
          ///pDC->SetPixel(i,y,color);//实线填充
		  if(i%10==y%10)//花纹填充
		  {
			  pDC->SetPixel(i,y,color);
		  }
		  pFill=pFill->next->next;
	   }
       pFill=pAET;
       while(pFill!=NULL)
	   {
          if(pFill->ymax==y)
		  { 
              if(pFill->last!=NULL)
                 pFill->last->next=pFill->next;
              else
                 pAET=pFill->next;
              if(pFill->next!=NULL)
			  {
                 pFill->next->last=pFill->last;
			  }
              EDGE* pdelete=pFill;
              pFill=pFill->next;
              delete pdelete;        
		  } 
          else
              pFill=pFill->next;
       }
       if(pAET!=NULL)
       { 
           pFill=pAET;
           while(pFill!=NULL)
           {
               pFill->xmin+=pFill->fm;
               pFill=pFill->next;
           }
           SortAET(pAET);
           while(pAET->next!=NULL)
               pAET=pAET->next;
       }
       y++;
    }
}


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptStart=point;
	m_ptArray.Add(point);
	
	CView::OnLButtonDown(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptEnd=point;
	CDC *pDC=GetDC();
	if(m_drawType==1)
	{
		pDC->Rectangle(m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y);
		m_ptArray.RemoveAll();
	}
	
	if(m_drawType==3)
	{
		ScanSeedfill(pDC,point.x,point.y,RGB(0,0,0),RGB(0,0,192));	
	}


	ReleaseDC(pDC);
	CView::OnLButtonUp(nFlags, point);
}

void CDrawView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//	m_ptEnd=point;
	CDC *pDC=GetDC();
    //Polygonfill(pDC,&m_ptArray,RGB(0,255,0));
	if(m_drawType==2&&m_ptArray.GetSize()>2)
	{ 
		Polygonfill(pDC,&m_ptArray,RGB(0,255,0));
		CPoint p1,p2;
		for(int i=0;i<=m_ptArray.GetSize()-1;i++)
		{
			p1=(CPoint)m_ptArray.GetAt(i);
			if(i==m_ptArray.GetSize()-1)
			{
				p2=(CPoint)m_ptArray.GetAt(0);
			}
			else
			{
				p2=(CPoint)m_ptArray.GetAt(i+1);
			}
			pDC->MoveTo(p1);
			pDC->LineTo(p2);
		}
	}
   /*
	
	if(m_drawType==4&&m_ptArray.GetSize()>1)
	{
		CPoint p1,p2;
		for(int i=0;i<=m_ptArray.GetSize()-1;i++)
		{
			p1=(CPoint)m_ptArray.GetAt(i);
			if(i==m_ptArray.GetSize()-1)
			{
				p2=(CPoint)m_ptArray.GetAt(0);
			}
			else
			{
				p2=(CPoint)m_ptArray.GetAt(i+1);
			}
			pDC->MoveTo(p1);
			pDC->LineTo(p2);
		}
	}
	*/
	ReleaseDC(pDC);
	m_ptArray.RemoveAll();
	CView::OnLButtonDblClk(nFlags, point);
}

void CDrawView::ScanSeedfill(CDC *pDC, int x, int y, COLORREF boundaryvalue, COLORREF newvalue)
{
		//0:seed;xl:左边界点;xr:右边界
	int x0,xl,xr,y0,xid;
	int flag,xnextspan;//跨度引用

	stack<CPoint>s;
	CPoint p;
	s.push(CPoint(x,y));//拾取点，第一粒种子入栈，从外面传入
	while(!s.empty())//判断栈不为空，则执行如下操作
	{
		p=s.top();//取出栈顶种子
		s.pop();//，然后弹出
		pDC->SetPixel(p.x,p.y,newvalue);//栈顶（初始为拾取点），赋指定颜色。
		x=p.x;
		y=p.y;

		x0=x+1;//种子向右挪动，搜索填充
		while(pDC->GetPixel(x0,y)!=boundaryvalue)
		{
			pDC->SetPixel(x0,y,newvalue);
			x0++;
		}
		xr=x0-1;//最右边元素

		x0=x-1;//种子向左移动,搜索填充
		while(pDC->GetPixel(x0,y)!=boundaryvalue)
		{
			pDC->SetPixel(x0,y,newvalue);
			x0--;
		}
		xl=x0+1;//最左边边界（因为上面x0经历递减循环，判断到达边缘颜色后再退出的循环，所以+1（这里的最左边界是上色的最左边界。
		
        y0=y;
		for(int i=1;i>=-1;i-=2)//上一行和下一行带代码的写法。
		{
			x0=xr;
			y=y0+i;
			while(x0>=xl)
			{
				flag=0;
				while((pDC->GetPixel(x0,y)!=boundaryvalue)
					&&(pDC->GetPixel(x0,y)!=newvalue)
					&&(x0>xl))
				{
					if(flag==0)//为保留最右边一个点作为新的种子
					{
						flag=1;
						xid=x0;
					}
					x0--;
				}
				if(flag==1)
				{
					s.push(CPoint(xid,y));
					flag=0;
				}
				xnextspan=x0;//xnextspan：像素段长度
				while((pDC->GetPixel(x0,y)==boundaryvalue)
				    ||(pDC->GetPixel(x0,y)==newvalue)&&(x0>=xl))
				{
					x0--;//和下一句x0--一样，避免死循环。
				}
				if(xnextspan==x0)x0--;
			}		
		}
	}	
}

void CDrawView::OnSeedfill() 
{
	// TODO: Add your command handler code here
	m_drawType=3;
	
}

void CDrawView::OnLine() 
{
	// TODO: Add your command handler code here
	m_drawType=2;
	
}

void CDrawView::OnRectangle() 
{
	// TODO: Add your command handler code here
	m_drawType=1;
	
}

void CDrawView::OnPolygon() 
{
	// TODO: Add your command handler code here
	m_drawType=4;
	
}
