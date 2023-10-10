using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace AbstractGeomerty
{
	internal class Program
	{
		static void Main(string[] args)
		{
			IntPtr hwnd = GetConsoleWindow();
			System.Drawing.Graphics graphics = Graphics.FromHwnd(hwnd);
			System.Drawing.Rectangle window_rect = new System.Drawing.Rectangle
				(
				Console.WindowLeft, Console.WindowTop,
				Console.WindowWidth, Console.WindowWidth
				);
			PaintEventArgs e = new PaintEventArgs( graphics, window_rect );

			System.Drawing.Rectangle rect = new System.Drawing.Rectangle(200, 150, 100, 100);//, 5);//, Color.AliceBlue);
			//rect.Info(e);
			Rectangle test_1 = new Rectangle(200, 150, 100, 100, 5, Color.AliceBlue);
			test_1.Info(e);

		}
		[DllImport("kernel32.dll")]
		public static extern IntPtr GetConsoleWindow();
		[DllImport("kernel32.dll")]
		public static extern IntPtr GetDC(IntPtr hwnd);
	}
}
