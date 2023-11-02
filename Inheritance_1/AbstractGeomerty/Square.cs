using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AbstractGeomerty
{
	internal class Square:Rectangle, IDrowDiagonal
	{
		public Square(int side, int start_x, int start_y, int line_width, Color сolor) 
			: base(side, side, start_x, start_y, line_width, сolor) { }

		public void DrawDiagonal(PaintEventArgs e)
		{
			Pen pen = new Pen(сolor, 1);
			double a = StartX + SideA;
			double b = StartY + SideA;
			e.Graphics.DrawLine(pen, StartX, StartY,(float)a , (float)b);
		}

	}
}
