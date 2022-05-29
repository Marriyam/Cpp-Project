#include <iostream>
#include<iomanip>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;

class teammember
{
    string projectmember[7][5];
    ofstream file_obj;
    ifstream file;
public:
    teammember()
    {
        for (int i = 0; i < 7; i++)                               //ROWS
        {
            for (int j = 0; j < 5; j++)                           //COLUMN
            {
                projectmember[i][j] = '0';
            }
        }
    }  
    void fixeddata()                     // predefined data
    {
        file.open("fixed data.txt");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5;)
            {
                getline(file, projectmember[i][j]);
                j++;
            }
        }

    }
    void membername()                               //displaying predefined data
    {
      cout  << "1 " << projectmember[0][1] << endl
            << "2 " << projectmember[1][1] << endl
            << "3 " << projectmember[2][1] << endl
            << "4 " << projectmember[3][1] << endl;
    }
    void decision()
    {
        char option;
        cout << "ALREADY EXISTING MEMBER ARE:" << endl;
        membername();
        cout << "ENTER THE OPTION (A,E,D):";    //add,edit,delete
        cin >> option;
        if (option == 'A' || option == 'a')
        {
            add();
        }
        else if (option == 'E' || option == 'e')
        {
            edit();
        }
        else if(option == 'D' || option == 'd')
        {
            del();
        }
    }
    void add()              //adding new data
    {
        int no=0;
        file_obj.open("member.txt");
        cout << "HOW MANY MEMBER YOU WANT TO ADD:"<<endl;
        cin >> no;
        no += 4;
        cout << "ENTER THE DATA OF MEMBER:"<<endl;
        for (int i = 4; i < no;i++)
        {
            cout << "MEMBER:" << i + 1<<endl ;
            projectmember[i][0]=to_string(i+1);
            cout << "enter the name:";
            cin.ignore();
            getline(cin, projectmember[i][1]);
            validationN();
            cout << "enter the address:";
            getline(cin, projectmember[i][2]);
            cout << "enter the phone no.:";
            cin >> projectmember[i][3];
            validationP();
            cout << "enter th gmail:";
            cin >> projectmember[i][4]; 
        }
        for (int j = 4; j < no; j++)
        {
            if (projectmember[j][1] == "invalid")
            {
                cout << "ENTER THE CORRECT DATA (NAME):";
                cin >> projectmember[j][1];
                this->validationN();
            }
            else if (projectmember[j][3] == "invalid")
            {
                cout << "ENTER THE CORRECT DATA (PHONE):";
                cin >> projectmember[j][3];
                this->validationP();
            }
        }
    }
    void edit()                  //editing data
    {
        int l = 0, c = 0;
        cout << "ENTER THE ID TO BE EDITED (1,2,3...):";
        cin >> c;
        l = c - 1;
        for (int a = l; a < l+1; a++)
        {
            cout << "enter the name:";
            cin.ignore();
            getline(cin, projectmember[a][1]);
            validationN();
            cout << "enter the address:";
            getline(cin, projectmember[a][2]);
            cout << "enter the phone no.:";
            cin >> projectmember[a][3];
            validationP();
            cout << "enter th gmail:";
            cin >> projectmember[a][4];
        }
        for (int j = l; j < l+1; j++)
        {
            if (projectmember[j][1] == "invalid")
            {
                cout << "ENTER THE CORRECT DATA (NAME):";
                cin >> projectmember[j][1];
                this->validationN();
            }
            else if (projectmember[j][3] == "invalid")
            {
                cout << "ENTER THE CORRECT DATA (PHONE):";
                cin >> projectmember[j][3];
                this->validationP();
            }
        }
    }
    void del()              //deleting data
    {
        int d = 0,k=0;
        cout << "ENTER THE ID TO BE DELETED:";
        cin >>d;
        k = d - 1;
        for (int i = k; i < d; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                projectmember[i][j] = "0";
            }
        }
    }
    void repeatation()      //for re-entring data
    {
    	char opt;
    	cout << endl << "DO YOU WANT TO ENTER AGAIN:(Y/N)" << endl;
    	cin >> opt;
    	while(opt == 'Y' || opt == 'y')
    	{
            decision();
            cout << endl << "DO YOU WANT TO ENTER AGAIN:(Y/N)" << endl;
            cin >> opt;
		}
		print();
	}
    void validationN()
    { //NAME
            for (int i = 0; i < 5; i++)
            {
                string name = projectmember[i][1];
                int lname = name.length();
                int count = 0;
                for (int n = 0; n <= lname - 1; n++)
                {
                    if (isalpha(name[n]) || name[n] == ' ')
                    {
                        count++;
                    }
                }
                if (count == lname)
                {
                    return;
                }
                else
                {
                    projectmember[i][1] = "invalid";
                }
            }
    }
    void validationP()
    {//PHONE
        for (int j = 0; j < 5; j++)
        {
            string phone = projectmember[j][3];
            int lphone = phone.length();
            int cal = 0;
            for (int p = 0; p <= lphone - 1 && p < 11; p++)
            {
                if (isdigit(phone[p]))
                {
                    cal++;

                }
            }
            if (cal == lphone)
            {
                return;
            }
            else
            {
                projectmember[j][3] = "invalid";
            }
        }
    }
    void print()
    {
        cout << "MEMBER ID" << "|" << "NAME" << "|" << "ADDRESS" << "|" << "PHONE" << "|" << "EMAIL";
        for (int i = 0; i < 7;i++)
        {
            if (projectmember[i][1] != "0")
            {
                cout << endl << "   " << projectmember[i][0] << "   " << projectmember[i][1] << "   " << projectmember[i][2]
                    << "   " << projectmember[i][3] << "   " << projectmember[i][4];
            }
        }
    }
    void fprint()
    {
        file_obj << "MEMBER ID" << "|" << "NAME" << "|" << "ADDRESS" << "|" << "PHONE" << "|" << "EMAIL";
        for (int i = 0; i < 7; i++)
        {
            if (projectmember[i][1] != "0")
            {
                file_obj << endl << projectmember[i][0] << "   " << projectmember[i][1] << "   " << projectmember[i][2]
                    << "   " << projectmember[i][3] << "   " << projectmember[i][4];
            }
        }
        file_obj.close();
    }
};
int main()
{
    teammember m;
    m.fixeddata();
    m.decision();
    m.repeatation();
    m.fprint();
    return 0;
}
