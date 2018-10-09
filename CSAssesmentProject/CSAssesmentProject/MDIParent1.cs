using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSAssesmentProject
{
    public partial class MDIParent1 : Form
    {
        public List<PictureBox> PicArray;

        private int childFormNumber = 0;
       

       

        public MDIParent1()
        {
            InitializeComponent();
            PicArray = new List<PictureBox>();
        }

        private void ShowNewForm(object sender, EventArgs e)
        {
            Form childForm = new Form();
            childForm.MdiParent = this;
            childForm.Text = "Window " + childFormNumber++;
            childForm.Show();
        }

        private void OpenFile(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            openFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            if (openFileDialog.ShowDialog(this) == DialogResult.OK)
            {
                string FileName = openFileDialog.FileName;
            }
        }

        private void SaveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.Personal);
            saveFileDialog.Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
            if (saveFileDialog.ShowDialog(this) == DialogResult.OK)
            {
                string FileName = saveFileDialog.FileName;
            }
        }

        private void ExitToolsStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void CutToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void CopyToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void PasteToolStripMenuItem_Click(object sender, EventArgs e)
        {
        }

        private void ToolBarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStrip.Visible = toolBarToolStripMenuItem.Checked;
        }

        private void StatusBarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            statusStrip.Visible = statusBarToolStripMenuItem.Checked;
        }

        private void CascadeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.Cascade);
        }

        private void TileVerticalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileVertical);
        }

        private void TileHorizontalToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void ArrangeIconsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LayoutMdi(MdiLayout.ArrangeIcons);
        }

        private void CloseAllToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form childForm in MdiChildren)
            {
                childForm.Close();
            }
        }
        // adding the image into the listbox
        private void button1_Click(object sender, EventArgs e)
        {

            listBox1.MultiColumn = true;

            listBox1.SelectionMode = SelectionMode.MultiExtended;

            OpenFileDialog ofd = new OpenFileDialog();

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                if (ofd.CheckFileExists == true)
                {
                    Storage s = new Storage();
                    s.name = Path.GetFileName(ofd.FileName);
                    s.pos = new Point(0, 0);
                    s.Image = new Bitmap(ofd.FileName);
                    s.size = s.Image.Size;
                    listBox1.Items.Add(s);
                }
            }
        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
      
        }
        // adding the image to the picutebox
        private void button2_Click(object sender, EventArgs e)
        {

            PictureBox p = new PictureBox();
            p.Parent = panel1;
            PicArray.Add(p);

            Storage s = null;
        
                s =(Storage)listBox1.SelectedItems; 

            p.Image = s.Image;


           
        }
        // Delete the sleceted image from the listbox
        private void button3_Click(object sender, EventArgs e)
        {
            for (int i = listBox1.SelectedIndices.Count-1; i >= 0; i--)
            {
             listBox1.Items.RemoveAt(listBox1.SelectedIndices[i]);

            }
        }
        // able to move the image around in the picture box 
        private void pictureBox1_DragDrop(object sender, DragEventArgs e)
        {
        }

        private void listBox1_DragDrop(object sender, DragEventArgs e)
        {
            int x = this.PointToClient(new Point(e.X,e.Y)).X;
            int y = this.PointToClient(new Point(e.X, e.Y)).Y;

         

        }
        // moving the imagealong the X axis around with Textbox
     

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
           // e.Graphics.DrawRectangle(new Pen(Color.LawnGreen, 10), new Rectangle(demoStorage.pos, new Size(20, 20)));
        }
        // moving the imagealong the Y axis around with Textbox
     
        // remove image from listbox and picturebox
        private void Remove_Click(object sender, EventArgs e)
        {
            for (int i = listBox2.SelectedIndices.Count - 1; i >= 0; i--)
            {
                listBox2.Items.RemoveAt(listBox2.SelectedIndices[i]);
               
               
              
            }
        }
    }
}
