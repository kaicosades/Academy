using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AbstractGeomerty
{
	internal class Circle: Shape
	{
		double radius;
		public double Radius
		{
			get { return radius; }
			set
			{
				if (value < MIN_SIZE) value = MIN_SIZE;
				if (value > MAX_SIZE) value = MAX_SIZE;
				radius = value;
			}
		}
		

		public Circle(double radius, int start_x, int start_y, int line_width, Color сolor) : base(start_x, start_y, line_width, сolor)
		{
			Radius = radius;
		}
		public override double GetArea()
		{
			return Math.PI * Math.Pow(Radius, 2);
		}

		public override double GetPerimeter()
		{
			return Math.PI * Radius* 2;
		}

		public override void Draw(PaintEventArgs e) // некорректно
		{
			Pen pen = new Pen(сolor, LineWidth);
			//e.Graphics.DrawRectangle(pen, StartX, StartY, (int)SideA, (int)SideB);
		}

		public override void Info(PaintEventArgs e)
		{
			Console.WriteLine($"Радиус: {Radius}");
			base.Info(e);
		}

	}
}
