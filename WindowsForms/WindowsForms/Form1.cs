using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing;//Эту ли библиотеку? 19 19 17.11.2023

namespace WindowsForms
{
	public partial class Form1 : Form
	{
		bool show_date;
		bool visible_controls;
		public Form1()
		{
			InitializeComponent();
			this.Location = new System.Drawing.Point
				(
				System.Windows.Forms.Screen.PrimaryScreen.Bounds.Right - this.Width - 50,
				System.Windows.Forms.Screen.PrimaryScreen.Bounds.Top + 100
				);
			show_date = false;
			visible_controls = false;
			btnHideControls.Visible = false;
			btnClose.Visible = false;

			//choose_font = new WindowsForms.Font(label1.Font);

			//StreamReader sr = new StreamReader("Settings.cfg");
			
			//string font_file = sr.ReadLine();
			//int size = Convert.ToInt32(sr.ReadLine());
			//sr.Close();




			LoadSettings();
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			label1.Text = DateTime.Now.ToString("HH:mm:ss ");
			if (cbShowDate.Checked)label1.Text += $"\n{DateTime.Now.ToString("dd.MM.yyyy")}";
			//cbShowDate// show date// visible - false
			notifyIcon1.Text = DateTime.Now.ToString("hh:mm:ss tt");
		}

		public void LoadSettings()
		{
		//	MessageBox.Show(this, Directory.GetCurrentDirectory(), "Directory", MessageBoxButtons.);
		//		StreamReader sr = new StreamReader("Settings.cfg");
		//string font_file
		


		//		PrivateFontCollection pfc = new PrivateFontCollection();
		//	pfc.AddFontFile(font_file);
		//	System.
		}

		private void SetShowDate(bool show_date)
		{
			this.show_date = show_date;
			cbShowDate.Checked = show_date;
			showDateToolStripMenuItem.Checked = show_date;
		}

		private void label1_DoubleClick(object sender, EventArgs e)
		{
			this.FormBorderStyle = FormBorderStyle.Sizable;
			this.TransparencyKey = Color.AliceBlue;
			this.ShowInTaskbar = true;
			this.cbShowDate.Visible = true;
			

			this.btnHideControls.Visible = true;
			this.btnClose.Visible = true;
			//this.notifyIcon1.Visible = false;
			//SetControlsVisibility(true);
		}

		private void btnHideControls_Click(object sender, EventArgs e)
		{
			this.FormBorderStyle= FormBorderStyle.None;
			this.TransparencyKey = SystemColors.Control;
			
			this.ShowInTaskbar = false;
			this.cbShowDate.Visible = false;
			this.btnHideControls.Visible= false;
			this.btnClose.Visible= false;
			//this.notifyIcon1.Visible = true;

			//SetControlsVisibility(false);
		}

		private void SetControlsVisibility(bool visible_controls)
		{
			this.visible_controls = visible_controls;
			this.FormBorderStyle = visible_controls ? FormBorderStyle.Sizable: FormBorderStyle.None;
			this.TransparencyKey = visible_controls ? Color.AliceBlue : SystemColors.Control;

			this.ShowInTaskbar = visible_controls;
			this.cbShowDate.Visible = visible_controls;

			this.btnHideControls.Visible = visible_controls;
			this.btnClose.Visible = visible_controls;
			//this.notifyIcon1.Visible = !visible_controls;

			this.showControlsToolStripMenuItem.Checked= visible_controls; 

			//19 00 - 19 04 пара 13.11
		}


		

		private void label1_MouseDoubleClick(object sender, MouseEventArgs e)
		{

		}

		

		private void btnClose_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void closeToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void showDateToolStripMenuItem_Click(object sender, EventArgs e)
		{
			//cbShowDate.Checked = showDateToolStripMenuItem.Checked;
		this.show_date = showDateToolStripMenuItem.Checked;
			SetShowDate(show_date);

		}

		private void showControlsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (showControlsToolStripMenuItem.Checked) label1_DoubleClick(sender, e);
			else btnHideControls_Click(sender, e);
		}

		private void cbShowDate_CheckedChanged(object sender, EventArgs e)
		{
			SetShowDate(cbShowDate.Checked);
		}

		private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
		{
			label1_DoubleClick(sender, e);
		}

		private void btnFont_Click(object sender, EventArgs e)
		{
			Font font = new Font(label1.Font);
			font.ShowDialog(this);
			label1.Font = font.OldFont;
		}

		private void foregroundToolStripMenuItem_Click(Object sender, EventArgs e)
		{
			colorDialog1.ShowDialog(this);
			label1.ForeColor = colorDialog1.Color;

		}

		~Form1()
		{
			StreamWriter sw = new StreamWriter("Settings.cfg");
			//sw.WriteLine("Font:" + choose_font.FontFile);
			sw.WriteLine("Size:" + label1.Font.Size);
			sw.WriteLine("ForeColor:" + label1.ForeColor);
			sw.WriteLine("BackColor:" + label1.BackColor);
			sw.Close();
		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}

		
	}
}
