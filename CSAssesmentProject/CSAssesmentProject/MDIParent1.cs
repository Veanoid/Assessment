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
        private int childFormNumber = 0;
        Bitmap drawArea;

        Storage demoStorage;

        public MDIParent1()
        {
            InitializeComponent();
            drawArea = new Bitmap(pictureBox1.Width, pictureBox1.Height);

            demoStorage = new Storage();
            demoStorage.pos = new Point(10, 10);
            demoStorage.size = new Size(20, 20);

            textBox2.Text = demoStorage.pos.X.ToString();
            textBox3.Text = demoStorage.pos.Y.ToString();
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
                    //s.name = new String(textBox1.Text);
                    //listBox1.DisplayMember = "FileName";
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
            Graphics g = Graphics.FromImage(drawArea);
            Storage s = null;
            for (int i = 0; i < listBox1.Items.Count; ++i)
            {
                s = (Storage)listBox1.SelectedItem;
            }
            g.DrawImage(s.Image, s.pos);
            pictureBox1.Image = drawArea;
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

            if(x >= pictureBox1.Location.X && x <= pictureBox1.Location.X + pictureBox1.Width && y >= pictureBox1.Location.Y && y <= pictureBox1.Location.Y + pictureBox1.Height)
            {
                string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
                pictureBox1.Image = Image.FromFile(files[0]);
            }

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if(textBox2.Text != "")
            {
                Point p = demoStorage.pos;
                p.X = int.Parse(textBox2.Text);
                demoStorage.pos = p;

                pictureBox1.Invalidate();

            }
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawRectangle(new Pen(Color.LawnGreen, 10), new Rectangle(demoStorage.pos, new Size(20, 20)));
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            if (textBox3.Text != "")
            {
                Point p = demoStorage.pos;
                p.Y = int.Parse(textBox3.Text);
                demoStorage.pos = p;

                pictureBox1.Invalidate();

            }
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            if (textBox4.Text != "")
            {
                Size s = demoStorage.size;
                s.Height = int.Parse(textBox4.Text);
                demoStorage.size = s;
            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            if (textBox5.Text != "")
            {
                Size s = demoStorage.size;
                s.Width = int.Parse(textBox5.Text);
                demoStorage.size = s;
            }
        }
    }
}
