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
    public partial class Form2 : Form
    {
        private Contact contact;

        public Contact getcontact() { return this.contact; }
        public void setcontact(Contact contact) { this.contact = contact; }
        public Form2()
        {
            InitializeComponent();
            this.contact = new Contact();
        }

        private void BTNOK_Click(object sender, EventArgs e)
        {
            this.contact.setid(this.texid.Text);
            this.contact.setname(this.texname.Text);
            this.contact.setphone(this.texphone.Text);
            this.contact.setemail(this.texemail.Text);
            this.contact.setaddress(this.texaddress.Text);
            this.contact.setresource(this.texresource.Text);
        }

        public void settxtid(string id) { this.texid.Text = id; }
        public void settxtname(string name) { this.texname.Text = name; }
        public void settxtphone(string phone) { this.texphone.Text = phone; }
        public void settxtemail(string email) { this.texemail.Text = email; }
        public void settxtaddress(string address) { this.texaddress.Text = address; }
        public void settxtresource(string resource) { this.texresource.Text = resource; }

    }
}
