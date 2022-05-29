namespace allaboutdatagridview
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form2));
            this.BTNCANCEL = new System.Windows.Forms.Button();
            this.BTNOK = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.texid = new System.Windows.Forms.TextBox();
            this.texresource = new System.Windows.Forms.TextBox();
            this.texaddress = new System.Windows.Forms.TextBox();
            this.texemail = new System.Windows.Forms.TextBox();
            this.texphone = new System.Windows.Forms.TextBox();
            this.texname = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // BTNCANCEL
            // 
            this.BTNCANCEL.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.BTNCANCEL.Font = new System.Drawing.Font("Algerian", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BTNCANCEL.Location = new System.Drawing.Point(453, 295);
            this.BTNCANCEL.Name = "BTNCANCEL";
            this.BTNCANCEL.Size = new System.Drawing.Size(120, 34);
            this.BTNCANCEL.TabIndex = 0;
            this.BTNCANCEL.Text = "CANCEL";
            this.BTNCANCEL.UseVisualStyleBackColor = true;
            // 
            // BTNOK
            // 
            this.BTNOK.BackColor = System.Drawing.Color.White;
            this.BTNOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.BTNOK.Font = new System.Drawing.Font("Algerian", 11F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BTNOK.Location = new System.Drawing.Point(334, 295);
            this.BTNOK.Name = "BTNOK";
            this.BTNOK.Size = new System.Drawing.Size(83, 34);
            this.BTNOK.TabIndex = 1;
            this.BTNOK.Text = "OK";
            this.BTNOK.UseVisualStyleBackColor = false;
            this.BTNOK.Click += new System.EventHandler(this.BTNOK_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial Narrow", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(235, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(26, 24);
            this.label1.TabIndex = 2;
            this.label1.Text = "ID";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Arial Narrow", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(235, 64);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(58, 24);
            this.label2.TabIndex = 3;
            this.label2.Text = "NAME";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Arial Narrow", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(235, 94);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(69, 24);
            this.label3.TabIndex = 4;
            this.label3.Text = "PHONE";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Arial Narrow", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(235, 128);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 24);
            this.label4.TabIndex = 5;
            this.label4.Text = "EMAIL";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Arial Narrow", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(235, 161);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(90, 24);
            this.label5.TabIndex = 6;
            this.label5.Text = "ADDRESS";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Arial Narrow", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(235, 200);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(104, 24);
            this.label6.TabIndex = 7;
            this.label6.Text = "RESOURCE";
            // 
            // texid
            // 
            this.texid.Location = new System.Drawing.Point(359, 26);
            this.texid.Name = "texid";
            this.texid.Size = new System.Drawing.Size(267, 26);
            this.texid.TabIndex = 8;
            // 
            // texresource
            // 
            this.texresource.Location = new System.Drawing.Point(359, 196);
            this.texresource.Name = "texresource";
            this.texresource.Size = new System.Drawing.Size(267, 26);
            this.texresource.TabIndex = 9;
            // 
            // texaddress
            // 
            this.texaddress.Location = new System.Drawing.Point(359, 157);
            this.texaddress.Multiline = true;
            this.texaddress.Name = "texaddress";
            this.texaddress.Size = new System.Drawing.Size(267, 33);
            this.texaddress.TabIndex = 10;
            // 
            // texemail
            // 
            this.texemail.Location = new System.Drawing.Point(359, 125);
            this.texemail.Name = "texemail";
            this.texemail.Size = new System.Drawing.Size(267, 26);
            this.texemail.TabIndex = 11;
            // 
            // texphone
            // 
            this.texphone.Location = new System.Drawing.Point(359, 93);
            this.texphone.Name = "texphone";
            this.texphone.Size = new System.Drawing.Size(267, 26);
            this.texphone.TabIndex = 12;
            // 
            // texname
            // 
            this.texname.Location = new System.Drawing.Point(359, 61);
            this.texname.Name = "texname";
            this.texname.Size = new System.Drawing.Size(267, 26);
            this.texname.TabIndex = 13;
            // 
            // Form2
            // 
            this.AcceptButton = this.BTNOK;
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.CancelButton = this.BTNCANCEL;
            this.ClientSize = new System.Drawing.Size(659, 372);
            this.Controls.Add(this.texname);
            this.Controls.Add(this.texphone);
            this.Controls.Add(this.texemail);
            this.Controls.Add(this.texaddress);
            this.Controls.Add(this.texresource);
            this.Controls.Add(this.texid);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.BTNOK);
            this.Controls.Add(this.BTNCANCEL);
            this.Name = "Form2";
            this.Text = "EDIT CONTACT";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BTNCANCEL;
        private System.Windows.Forms.Button BTNOK;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox texid;
        private System.Windows.Forms.TextBox texresource;
        private System.Windows.Forms.TextBox texaddress;
        private System.Windows.Forms.TextBox texemail;
        private System.Windows.Forms.TextBox texphone;
        private System.Windows.Forms.TextBox texname;
    }
}