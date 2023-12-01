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
using System.Drawing.Text;


namespace WindowsForms
{
	public partial class Font : Form
	{
		public string FontFile { get; set; }
		public System.Drawing.Font NewFont
		{get;set;}
		public System.Drawing.Font OldFont
		{ get; set; }

		//public Font(System.Drawing.Font oldFont)
		public Font(System.Drawing.Font oldFont)
		{
			InitializeComponent();
			string currectDirectory = Directory.GetCurrentDirectory();
			//MessageBox.Show(this, currectDirectory, "Current directory", MessageBoxButtons.OK);
			if(Directory.GetCurrentDirectory().Contains("bin"))Directory.SetCurrentDirectory("..\\..\\Fonts");
			MessageBox.Show(this, currectDirectory, "Current directory", MessageBoxButtons.OK);
			foreach (string i in Directory.GetFiles(currectDirectory))//.Split('\\')
			{
				if(i.Split('\\').Last().Contains(".ttf"))this.comboBox1.Items.Add(i.Split('\\').Last());
			}
			
			//numericUpDownForSize = new NumericUpDown();
			numericUpDownForSize.Value = (decimal)OldFont.Size;
			//cbFont.SelectedItem = oldFont.Name;
		}


		private void btnCancel_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void btnOK_Click(object sender, EventArgs e)
		{
			//NewFont.Size = (int)numbericUpDownFontSize.Value;
			OldFont = NewFont;
			this.Close();
		}


		private void comboBox1_SelectionChangeCommitted(object sender, EventArgs e)
		{
			//cbFont.Select
			//PrivateFontCollection pfs = new PrivateFontCollection();
			//pfs.AddFontFile(cbFont.SelectedItem.ToString());
			//NewFont = new System.Drawing.Font(pfs.Famililes[0], (int)numericUpDown.Font.Value);	//System.Drawing.
																								//NewFont = new System.Drawing.Font(pfs.Famililes[0], lblExample.Font.Size);//System.Drawing.
			//lblExample.Font = NewFont;

		}

	private void numericUpDownFontSize_ValueChanged(object sender, EventArgs e)
	{
		
		comboBox1_SelectionChangeCommitted(sender, e); 

	}

	

		// 19 00 - 19 05 пара 13.11// 19 25-19 29
	}
}
