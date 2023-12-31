﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
//using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace AbstractGeomerty
{
	abstract class Shape
	{
		public static readonly int MIN_START_X = 10;
		public static readonly int MAX_START_X = 700;
		public static readonly int MIN_START_Y = 10;
		public static readonly int MAX_START_Y = 700;
		public static readonly int MIN_LINE_WIDTH = 1;
		public static readonly int MAX_LINT_WIDTH = 32;
		public static readonly int MIN_SIZE = 20;
		public static readonly int MAX_SIZE = 500;
		public static readonly int MIN_CORNER = 1;
		public static readonly int MAX_CORNER = 179;

		int start_x;
		int start_y;
		int line_width;
		public Color сolor { get; set; }
		public int StartX
		{
			get { return start_x; }
			set
			{
				if (value < MIN_START_X) value = MIN_START_X;
				if (value > MAX_START_X) value = MAX_START_X;
				start_x = value;
			}
		}
		public int StartY
		{
			get { return start_y; }
			set
			{
				if (value < MIN_START_Y) value = MIN_START_Y;
				if (value > MAX_START_Y) value = MAX_START_Y;
				start_y = value;
			}
		}
		public int LineWidth
		{
			get { return line_width; }
			set
			{
				if (value < MIN_LINE_WIDTH) value = MIN_LINE_WIDTH;
				if (value > MAX_LINT_WIDTH) value = MAX_LINT_WIDTH;
				line_width = value;
			}
		}
		public Shape(int start_x, int start_y, int line_width, Color color)
		{
			StartX = start_x;
			StartY = start_y;
			LineWidth = line_width;
			сolor = color;
		}

		public abstract double GetArea();
		public abstract double GetPerimeter();
		public abstract void Draw(PaintEventArgs e);
		public virtual void Info(PaintEventArgs e)
		{
            Console.WriteLine($"Площадь фигуры: {this.GetArea()}");
            Console.WriteLine($"Периметр фигуры: {this.GetPerimeter()}");
			this.Draw(e);
            Console.WriteLine();
        }
	}
}
