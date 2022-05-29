using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace allaboutdatagridview
{
    public class Contact
    {
        private string id;
        private string name;
        private string phone;
        private string email;
        private string address;
        private string resource;

        public string getid() { return this.id; }
        public void setid(string id) { this.id = id; }

        public string getname() { return this.name; }
        public void setname(string name) { this.name = name; }

        public string getphone() { return this.phone; }
        public void setphone(string phone) { this.phone = phone; }

        public string getemail() { return this.email; }
        public void setemail(string email) { this.email = email; }

        public string getaddress() { return this.address; }
        public void setaddress(string address) { this.address = address; }

        public string getresource() { return this.resource; }
        public void setresource(string resource) { this.resource = resource; }

    }
}
