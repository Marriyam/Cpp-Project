using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace allaboutdatagridview
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //disable the edit and delete button if no row selected
            this.BTNEDIT.Enabled = false;
            this.BTNDELETE.Enabled = false;

        }
        //ADDING DATA AFTER CLICKING NEW BUTTON
        private void BTNNEW_Click(object sender, EventArgs e)
        {
            using (Form2 frmEDITCONTACT = new Form2())
            {
                if(frmEDITCONTACT.ShowDialog()==DialogResult.OK)
                {
                    this.dgvcontact.Rows.Add(frmEDITCONTACT.getcontact().getid(),
                                             frmEDITCONTACT.getcontact().getname(),
                                             frmEDITCONTACT.getcontact().getphone(),
                                             frmEDITCONTACT.getcontact().getemail(),
                                             frmEDITCONTACT.getcontact().getaddress(),
                                             frmEDITCONTACT.getcontact().getresource());
                }
            }
        }
        // VALIDATION FOR EDIT
        private void Dgvcontact_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if(e.ColumnIndex == -1 && e.RowIndex < this.dgvcontact.RowCount - 1 )
            {
                this.BTNEDIT.Enabled = true;
                this.BTNDELETE.Enabled = true;
            }
            else
            {
                this.BTNEDIT.Enabled = false;
                this.BTNDELETE.Enabled = false;
            }
        }
        // EDITING DATA
        private void BTNEDIT_Click(object sender, EventArgs e)
        {
            using (Form2 frmEDITCONTRACT = new Form2())
            {
                frmEDITCONTRACT.settxtid(this.dgvcontact.SelectedRows[0].Cells[0].Value.ToString());
                frmEDITCONTRACT.settxtname(this.dgvcontact.SelectedRows[0].Cells[1].Value.ToString());
                frmEDITCONTRACT.settxtphone(this.dgvcontact.SelectedRows[0].Cells[2].Value.ToString());
                frmEDITCONTRACT.settxtemail(this.dgvcontact.SelectedRows[0].Cells[3].Value.ToString());
                frmEDITCONTRACT.settxtaddress(this.dgvcontact.SelectedRows[0].Cells[4].Value.ToString());
                frmEDITCONTRACT.settxtresource(this.dgvcontact.SelectedRows[0].Cells[5].Value.ToString());

                if (frmEDITCONTRACT.ShowDialog() == DialogResult.OK)
                {
                    this.dgvcontact.SelectedRows[0].Cells[0].Value = frmEDITCONTRACT.getcontact().getid();
                    this.dgvcontact.SelectedRows[0].Cells[1].Value = frmEDITCONTRACT.getcontact().getname();
                    this.dgvcontact.SelectedRows[0].Cells[2].Value = frmEDITCONTRACT.getcontact().getphone();
                    this.dgvcontact.SelectedRows[0].Cells[3].Value = frmEDITCONTRACT.getcontact().getemail();
                    this.dgvcontact.SelectedRows[0].Cells[4].Value = frmEDITCONTRACT.getcontact().getaddress();
                    this.dgvcontact.SelectedRows[0].Cells[5].Value = frmEDITCONTRACT.getcontact().getresource();
                }
            }
        }

        private void BTNDELETE_Click(object sender, EventArgs e)
        {
            this.dgvcontact.Rows.RemoveAt(this.dgvcontact.SelectedRows[0].Index);
        }
    }
}
