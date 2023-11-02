using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AbstractGeomerty
{
	internal class Triangle:Shape, IHaveHeight
	{
		double side_a;
		double side_b;
		double corner;

		public double SideA
		{
			get { return side_a; }
			set
			{
				if (value < MIN_SIZE) value = MIN_SIZE;
				if (value > MAX_SIZE) value = MAX_SIZE;
				side_a = value;
			}
		}
		public double SideB
		{
			get { return side_b; }
			set
			{
				if (value < MIN_SIZE) value = MIN_SIZE;
				if (value > MAX_SIZE) value = MAX_SIZE;
				side_b = value;
			}
		}

		public double Corner
		{
			get { return  corner; }
			set
			{
				if (value < MIN_CORNER) value = MIN_CORNER;
				if (value > MAX_CORNER) value = MAX_CORNER;
				corner = value;
			}
		}

		

		public Triangle(double side_a, double side_b, double corner , int start_x, int start_y, int line_width, Color сolor) : base(start_x, start_y, line_width, сolor)
		{
			SideA = side_a;
			SideB = side_b;
			Corner = corner;
		}
		public override double GetArea()
		{
			return 0.5*SideA * SideB* Math.Sin(Corner);
		}

		public override double GetPerimeter()
		{
			return SideA + SideB + Math.Sqrt(Math.Pow(SideA, 2) + Math.Pow(SideB, 2) - 2*SideA*SideB* Math.Cos(Corner));
		}

		public override void Draw(PaintEventArgs e) // некорректно
		{
			Pen pen = new Pen(сolor, LineWidth);
			//e.Graphics.Draw;
		}

		public override void Info(PaintEventArgs e)
		{
			Console.WriteLine($"Сторона А: {SideA}");
			Console.WriteLine($"Сторона B: {SideB}");
			Console.WriteLine($"Угол между этими сторонами: {Corner}");
			base.Info(e);
		}

		double IHaveHeight()
		{
			return 0;
		}

		public abstract double GetHeight();

	}
}
