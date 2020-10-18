using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace CSDraw
{
    public partial class Form1 : Form
    {
        public Point m_ptStart, m_ptEnd;
        //定义变量，绘图的起始点和终止点
        public uint drawType;

        [DllImport("gdi32.dll")]   
        //绘图函数的定义：
        static public extern int SetPixel(IntPtr pDC,int x,int y,int color);
    
        public Form1()
         //构造函数中赋初值
         //起始点和终止点和drawType都为0
        {
            InitializeComponent();
            m_ptStart=m_ptEnd=new Point(0,0) ;
            drawType = 0;
        }

        public void  DDALine(IntPtr pDC, int x1, int y1,int x2,int y2, int color)
        {
            double dx,dy,e,x,y;
	        dx=x2-x1;
	        dy=y2-y1;
	        e=(System.Math.Abs(dx)>System.Math.Abs(dy))?System.Math.Abs(dx):System.Math.Abs(dy);
	        dx/=e;
        	dy/=e;
         	x=x1;
	        y=y1;
            for (int i = 1; i <= e; i++)
            {
                SetPixel(pDC, (int)(x + 0.5), (int)(y + 0.5), color);
		        x+=dx;
		        y+=dy;
            }
	            
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            //将鼠标点击后的点坐标传入ptstart起始点的坐标
            m_ptStart.X = e.X;
            m_ptStart.Y = e.Y;

        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            m_ptEnd.X = e.X;
            m_ptEnd.Y = e.Y;
            Graphics g = this.CreateGraphics();
            IntPtr pDC = g.GetHdc();
            DDALine(pDC,m_ptStart.X,m_ptStart.Y,m_ptEnd.X,m_ptEnd.Y,0x0000FF); 
            g.ReleaseHdc();

        }
    }
}
