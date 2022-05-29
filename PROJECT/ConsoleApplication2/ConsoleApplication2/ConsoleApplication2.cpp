#include <iostream>
#include<iomanip>
#include<string.h>
#include<string>
#include<fstream>

using namespace std;

//-------------------------------------------------------------------------------------------------------------------
//************************************************MEMBER CLASS**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

class teammember
{
    string projectmember[7][5];                                   //2d array
    ofstream file_obj;                                            //saving data 
    ifstream fin;                                                //taking input
public:
    teammember()                                                  //null constructor
    {
        for (int i = 0; i < 7; i++)                               //ROWS
        {
            for (int j = 0; j < 5; j++)                           //COLUMN
            {
                projectmember[i][j] = '0';                        //making array zero  
            }
        }
    }
    void fixeddata()                                              // predefined data
    {
		fin.open("fix data.txt");
		if (fin.fail())
		{
			cout << "file has stopped working";
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					getline(fin, projectmember[i][j]);               //taking input from file  
				}
			}
		}
    }
    ~teammember()
    {

    }
    void membername()                                                //displaying predefined data
    {
		fixeddata();
		cout << endl << "ALREADY EXCISTING MEMBERS ARE:" << endl;
        cout << "1 " << projectmember[0][1] << endl
            << "2 " << projectmember[1][1] << endl
            << "3 " << projectmember[2][1] << endl
            << "4 " << projectmember[3][1] << endl;
    }

    void add()                                                      //adding new data
    {
        int no = 0;
        file_obj.open("member.txt");
        cout << "HOW MANY MEMBER YOU WANT TO ADD:" << endl;         //controlling the loop
        cin >> no;                                   
        no += 4;                                                    //to avoid overwritting
        cout << "ENTER THE DATA OF MEMBER:" << endl;
        for (int i = 4; i < no; i++)
        {                                                           // taking input
            cout << "MEMBER:" << i + 1 << endl;
            projectmember[i][0] = to_string(i + 1);
            cout << "enter the name:";
            cin.ignore();
            getline(cin, projectmember[i][1]);
            validationN();
            cout << "enter the address:";
            getline(cin, projectmember[i][2]);
            cout << "enter the phone no.:";
            cin >> projectmember[i][3];
            validationP();
            cout << "enter the gmail:";
            cin >> projectmember[i][4];
        }
        for (int j = 4; j < no; j++)                                //validatoion Name
        {
            if (projectmember[j][1] == "invalid")
            {
                cout << "ENTER THE CORRECT DATA (NAME):";           //re-enter
                cin >> projectmember[j][1];
                this->validationN();
            }
            else if (projectmember[j][3] == "invalid")             //validatoion Phone
            {
                cout << "ENTER THE CORRECT DATA (PHONE):";         //re-enter
                cin >> projectmember[j][3];
                this->validationP();
            }
        }
        
        char opt;
        cout << endl << "DO YOU WANT TO ENTER AGAIN:(Y/N)" << endl; // re-entery 
        cin >> opt;
        while (opt == 'Y' || opt == 'y')
        {
            add();
        }
        print();


        fprint();                                                 //for saving ina file
    }
    void edit()                                                   //editing data
    {
        int l = 0, c = 0;
        cout << "ENTER THE ID TO BE EDITED (1,2,3...):";         // id for edited
        cin >> c;
        l = c - 1;                                               //for accurate data to edited
        for (int a = l; a < l + 1; a++)                          // input 
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
            cout << "enter the gmail:";
            cin >> projectmember[a][4];
        }
        for (int j = l; j < l + 1; j++)                         //validatoion Name
        {
            if (projectmember[j][1] == "invalid")
            {
                cout << "ENTER THE CORRECT DATA (NAME):";       //re-enter
                cin >> projectmember[j][1];
                this->validationN();
            }
            else if (projectmember[j][3] == "invalid")         //validatoion Phone
            {
                cout << "ENTER THE CORRECT DATA (PHONE):";     //re-enter
                cin >> projectmember[j][3];
                this->validationP();
            }
        }


        char opt;
        cout << endl << "DO YOU WANT TO ENTER AGAIN:(Y/N)" << endl; //re-enter 
        cin >> opt;
        while (opt == 'Y' || opt == 'y')
        {
            edit();
        }
        print();


        fprint();
    }
    void del()                                                  //deleting data
    {
        int d = 0, k = 0;
        cout << "ENTER THE ID TO BE DELETED:";                  //ID to be deleted
        cin >> d;
        k = d - 1;                                              //for accurate data deleted
        for (int i = k; i < d; i++)                             // rows
        {               
            for (int j = 0; j < 5; j++)                         //column
            {                
                projectmember[i][j] = "0";                      //deleting data by making iut zero
            }
        }
        char opt;                                               //re-enter
        cout << endl << "DO YOU WANT TO ENTER AGAIN:(Y/N)" << endl;
        cin >> opt;
        while (opt == 'Y' || opt == 'y')
        {
            del();
        }
        print();


        fprint();
    }

    void validationN()                                           //validation on name
    { //NAME
        for (int i = 0; i < 5; i++)
        {
            string name = projectmember[i][1];                  //storing data of array in a string
            int lname = name.length();                          //taking length of string
            int count = 0;
            for (int n = 0; n <= lname - 1; n++)                //loop for counting length is same
            {
                if (isalpha(name[n]) || name[n] == ' ')         //checking all data is alphabets
                {
                    count++;
                }
            }
            if (count == lname)                                 //length is same 
            {
                return;
            }
            else
            {
                projectmember[i][1] = "invalid";
            }
        }
    }
    void validationP()                                         //validation on phone
    {//PHONE
        for (int j = 0; j < 5; j++)
        {
            string phone = projectmember[j][3];                //storing array data in a string
            int lphone = phone.length();                       //taking length of string
            int cal = 0;
            for (int p = 0; p <= lphone - 1 && p < 11; p++)    //loop counting length is same
            { 
                if (isdigit(phone[p]))                         //checking all data consits of digits only
                {
                    cal++;

                }
            }
            if (cal == lphone)                                //length is same
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
        cout << fixed << setw(19);
        cout << "MEMBER ID" << "\t|\t" << " NAME" << "\t  |\t" << "   ADDRESS" << "\t|\t" << "PHONE" << "\t    |    " << "    EMAIL";
        for (int i = 0; i < 7; i++)                            //for rows
        {                                                       
            cout << fixed << setw(19);

            if (projectmember[i][1] != "0")                    //for displaying non-zero data 
            {
                cout << fixed << setw(19);
                cout << endl << projectmember[i][0] << " \t \t " << projectmember[i][1] << "  \t " << projectmember[i][2]
                    << "  \t    " << projectmember[i][3] << " \t  " << projectmember[i][4];
            }
        }
        fprint();                                             //for saving in a file
    } 
    void fprint()                                             //for saving data in a file
    {
        file_obj << "MEMBER ID" << "|" << "NAME" << "|" << "ADDRESS" << "|" << "PHONE" << "|" << "EMAIL";
        for (int i = 0; i < 7; i++)
        {
            if (projectmember[i][1] != "0")
            {
                file_obj << endl << "   " << projectmember[i][0] << " \t" << projectmember[i][1] << "\t " << projectmember[i][2]
                    << "  \t" << projectmember[i][3] << " \t " << projectmember[i][4];
            }
        }
        file_obj.close();                                     //fo closing file after  saving data
    }
};

//-------------------------------------------------------------------------------------------------------------------
//************************************************RESOURCES CLASS**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------


class Resources

{
protected:
    string R[5][2]; //string data type 
    ofstream new_file;

public:
    Resources() //default constructor 
    {
        for (int i = 0; i < 3; i++) // control number of rows
        {
            for (int j = 0; j < 2; j++)//control number of columns
            {
                R[i][j] = '0'; // all rows and column have value 0
            }
        }
        R[0][0] = to_string(1);
        R[0][1] = "Laptop";
    }

    ~Resources()
    {

    }
    void Adding() // input function to get resources input 
    {
        new_file.open("resources.txt");//file open 
        for (int i = 1; i < 5; i++)// loop for rows
        {
            cout << "RESOURCE: " << i + 1 << endl;
            R[i][0] = to_string(i);
            cout << "Enter the Resource Name:" << endl;
            cin.ignore(); //ignore the buffer values
            getline(cin, R[i][1]);
            //................................................................................................................asking to enter more

            char c;
            cout << " " << "\n\tDO YOU WANT TO  ENTER AGAIN ...?...\n\t\t SELECT.....(y/n)" << endl;
            cin >> c;
            if (c == 'n' || c == 'N')
                break;

        }


    }
    void decision_to_edit()
    {

        int edit, e;
        cout << "\n\n\t\t Dear User....! Select the resources from the following that you want to edit...? \n\tID\tResources\n";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << "\t" << R[i][j];
            }
            cout << endl;
        }
        cout << "\n\t\tYOUR SELECTION.....";
        cin >> edit;
        e = edit - 1;//always step back of what number user enter 
        for (int i = e; i < edit; i++)
        {
            cout << "Enter the Resource Name:" << endl;
            cin.ignore(); //ignore the buffer values
            getline(cin, R[i][1]);
        }

    }

    void decision_to_delete()
    {
        int del, d;
        cout << "\n\n\t\t Dear User....! Select the resources from the following that you want to delete...? \n\tID\tResources\n";
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << "\t" << R[i][j];
            }
            cout << endl;

        }
        cout << "\n\t\tYOUR SELECTION.....";
        cin >> del;
        d = del - 1;
        for (int i = d; i < del; i++)
        {
            R[i][0] = '0';
            R[i][1] = '0';
        }
    }


    void display_in_file()
    {
        for (int i = 0; i < 5; i++)
        {
            if (R[i][0] != "0")
            {
                new_file << R[i][0] << " " << R[i][1] << endl;//data display in file	
            }
            cout << endl;

        }
        new_file.close(); //file close 
    }

    void displayInfo()//display function to display get data 
    {
        cout << "\tID" << "\t" << setw(2) << "NAME" << endl; // display id and name heading
        for (int i = 0; i < 5; i++)
        {
            if (R[i][0] != "0")
            {
                cout << "\t" << R[i][0] << "\t" << R[i][1] << endl;
            }
        }

    }

};

//-------------------------------------------------------------------------------------------------------------------
//************************************************PROJECT CLASS**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

class Project
{
protected:
    int id;
    string name;
    string project[2][4];

public:
    Project()
    {
        id = 0;
        name = "nothing";
    }
    Project(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
    ~Project()
    {

    }
    void add(void);
    void display(void);
    void edit(void);
    void dElete(void);
    void file_handle(void);

};

//-------------------------------------------------------------------------------------------------------------------
//************************************************ADDING PROJECT IN A PROJECT CLASS**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

void Project::add(void)
{
    static int che = 0;

    cout << "\n Please enter the name of your project: ";
    cin.ignore();
    getline(cin, name);
    string Id = to_string(che + 1);
    project[0][che] = Id;
    project[1][che] = name;

    ++che;

    file_handle();

}
//-------------------------------------------------------------------------------------------------------------------
//************************************************DISPLAYING PROJECT IN A PROJECT CLASS**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

void Project::display(void)
{
    cout << "\n\t ID\t NAME\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "\t" << project[j][i];
        }
        cout << endl;
    }
    file_handle();
}

//-------------------------------------------------------------------------------------------------------------------
//************************************************ADDING PROJECT IN A PROJECT FILE**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

void Project::file_handle(void)
{
    ofstream myfile("Project.txt");
    myfile << "\t ID\t NAME";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            myfile << fixed << setprecision(6);
            if (project[0][i] != "0")
                myfile << "   " << project[j][i] << "\t  ";
        }
        myfile << "\n";
    }

}
//-------------------------------------------------------------------------------------------------------------------
//************************************************EDITING PROJECT IN A PROJECT CLASS**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------


void Project::edit(void)
{
    int n;
    string Data;
    cout << "\n \n\t\t Now you can edit your Project: ";
label4:
    cout << "\n\t\t Dear USER...! what do you want to edit..?  \n\t Please select from the below given options  :  \n\t\tNow just tell us NUMERICALLY..(i.e 1,2,3....)  \n";
    cout << "\n\t Select the from the given projects  :  \n\ttell us NUMERICALLY..(i.e 1,2,3....)  ";
    for (int i = 0; i < 4; i++)
    {
        cout << "\n\t" << i + 1 << " . " << project[1][i];
    }
    cin >> n;

    cout << "\n\t Enter the new title...  :   ";
    cin.ignore();
    getline(cin, Data);
    project[1][--n] = Data;
    cout << "\n\n\t\t****************EDITED SUCCESSFULLY********************";

    cout << "\n\n\t\t Do you want to edit more...?";
    cin >> n;
    if (n == 1)
    {
        goto label4;
    }
    file_handle();
}

//-------------------------------------------------------------------------------------------------------------------
//************************************************DELETING PROJECT IN A PROJECT CLASS**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------


void Project::dElete(void)
{

    int n;
    string Data;
    cout << "\n \n\t\t Now you can Delete your Project: ";
    cout << "\n\t\t Dear USER...! what do you want to delete..?  \n\t Please select from the below given options  :  \n\t\tNow just tell us NUMERICALLY..(i.e 1,2,3....)  \n";
    cout << "\n\t Select the from the given projects  :  \n\ttell us NUMERICALLY..(i.e 1,2,3....)  ";
    for (int i = 0; i < 4; i++)
    {
        cout << "\n\t" << i + 1 << " . " << project[1][i];
    }
    cin >> n;
    project[0][--n] = "deleted";
    project[1][n] = "deleted";
    cout << "\n\n\t\t****************DELETED SUCCESSFULLY********************";

    file_handle();
}


//-------------------------------------------------------------------------------------------------------------------
//************************************************TASK CLASS**********************************                                  
//-------------------------------------------------------------------------------------------------------------------



class task : public Project
{
    int ID, From_day, To_day, From_month, To_month, From_year, To_year, current_day, current_month, current_year;
    string title, status, date;
    string Task[8][4];
    teammember Member;
    Resources resources;
public:
    task()
    {
        ID = From_day = To_day = From_month = To_month = From_year = To_year = current_day = current_month = current_year = 0;
    }
    task(int ID, int From_day, int To_day, int From_month, int To_month, int From_year, int To_year, int current_day, int current_month, int current_year, string title, string status)
    {
        this->ID = ID;
        this->From_day = From_day;
        this->From_month = From_month;
        this->From_year = From_year;
        this->To_day = To_day;
        this->To_month = To_month;
        this->To_year = To_year;
        this->current_day = current_day;
        this->current_month = current_month;
        this->current_year = current_year;
        this->title = title;
        this->status = status;
    }
    ~task()
    {

    }
    void ADD_task(int var);
    void display();
    void get_status();
    bool Is_a_leap_year(int year);
    bool Validate(int day, int month, int year);
    void EDIT_task();
    void DELETE_task();
    void func();
};

bool task::Validate(int day, int month, int year)
{

    if (month < 1 || month>12)
    {
        day = -1;
        return false;
    }
    if (day < 1 || day>31)
    {
        day = -1;
        return false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
    {
        day = -1;
        return false;
    }
    else if (month == 2)
    {
        if (Is_a_leap_year(year))
        {
            if (day > 29)
            {
                day = -1;
                return false;

            }
        }
        else if (day > 28)
        {
            day = -1;
            return false;

        }
    }
    return true;

}

//---------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------
//************************************************CHECKING FOR LEAP YEAR**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

bool task::Is_a_leap_year(int year)
{
    if (year % 400 == 0) return true;
    else if (year % 4 == 0) return true;
    else if (year % 100 == 0) return true;
    return false;
}

//-------------------------------------------------------------------------------------------------------------------
//************************************************ADDITION OF TASK**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

void task::ADD_task(int var)
{
    static int k = 0;
    cout << "\n\n\t\t Now it is the time to add task for your project";
    for (int i = k; i < 4; i++)
    {
        //taking the value for title from the user

        cout << "\n\t Dear user...!  Enter the title :  \n\t";
        cin.ignore();                                                    //so that we can use the getline easily
        getline(cin, title);

        //-------------------------------------------------------------------------------------------------------------------
        //taking the value of date from the user
        //-------------------------------------------------------------------------------------------------------------------

    label:
        cout << "\n\tDear user...! Enter the date bindings of your task...\n\tstarting date ";
        cin >> From_day >> From_month >> From_year;
        if (Validate(From_day, From_month, From_year) == false)
        {
            char rough;                             //this will only have the response from the user
            cout << "\n\t\tYou entered a wrong value......\n\t\t\t do you want to enter again...   (y/n)";
            cin >> rough;
            if (rough == 'y')                        //the meaning of this patch is just to allow user to give the value for date if it is entered wrong
                goto label;
        }

        //-------------------------------------------------------------------------------------------------------------------
        //starting date
        //-------------------------------------------------------------------------------------------------------------------

    label1:
        cout << "\n\t ending date";
        cin >> To_day >> To_month >> To_year;

        if (Validate(To_day, To_month, To_year) == false)
        {
            char rough;                             //this will only have the response from the user
            cout << "\n\t\tYou entered a wrong value......\n\t\t\t do you want to enter again...   (y/n)";
            cin >> rough;
            if (rough == 'y')                         //the meaning of this patch is just to allow user to give the value for date if it is entered wrong
                goto label1;
        }

        //-------------------------------------------------------------------------------------------------------------------
        //ending date
        //-------------------------------------------------------------------------------------------------------------------

    label3:
        cout << "\n\tDear user...! Enter the current date ... ";
        cin >> current_day >> current_month >> current_year;
        if (Validate(current_day, current_month, current_year) == false)
        {
            char rough;                             //this will only have the response from the user
            cout << "\n\t\tYou entered a wrong value......\n\t\t\t do you want to enter again...   (y/n)";
            cin >> rough;
            if (rough == 'y')                      //the meaning of this patch is just to allow user to give the value for date if it is entered wrong
                goto label3;
        }

        //-------------------------------------------------------------------------------------------------------------------
        //placing value in 2D array of task
        //-------------------------------------------------------------------------------------------------------------------
        Task[0][i] = to_string(i + 1);
        Task[1][i] = to_string(var);
        Task[2][i] = title;

        //-------------------------------------------------------------------------------------------------------------------
        //placing value of date in 2D array as a string
        //------------------------------------------------------------------------------------------------------------------- 
        string date = to_string(From_day) + " / " + to_string(From_month) + " / " + to_string(From_year);         //I did this just to make the value being able to be placed in the array
        string date1 = to_string(To_day) + " / " + to_string(To_month) + " / " + to_string(To_year);              //I did this just to make the value being able to be placed in the array

        Task[3][i] = date;
        Task[4][i] = date1;

        //-------------------------------------------------------------------------------------------------------------------
        //values of member 
        //-------------------------------------------------------------------------------------------------------------------
        string mem;
        cout << "\n\t\t Dear User...! Select the members in numbers....   ";
        Member.membername();
        cout << "\n\t\t SELECT  .....";
        cin >> mem;

        Task[5][i] = "[" + mem + " ]";

        //-------------------------------------------------------------------------------------------------------------------
        //values of resources
        //-------------------------------------------------------------------------------------------------------------------
        string p;
        cout << "\n\t\t Dear User...! Select the resources in numbers....   ";
        cout << "\tID" << "\t" << setw(2) << "NAME" << endl; // display id and name heading
        resources.displayInfo();

        cout << "\n\t\t SELECT  .....";
        cin >> p;
        Task[6][i] = "[" + p + " ]";

        //-------------------------------------------------------------------------------------------------------------------
        //checking the status
        //-------------------------------------------------------------------------------------------------------------------
        if (current_month < To_month)
        {
            status = "on going";
            Task[7][i] = status;
        }
        if (current_month == To_month)
        {
            if (current_day <= To_day)
            {
                status = "on going";
                Task[7][i] = status;
            }
            else
            {
                status = "Delayed";
                Task[7][i] = status;
            }
        }
        if (current_month == To_month)
        {
            if (current_day == To_day)
            {
                status = "done";
                Task[7][i] = status;
            }

        }
        if (current_year < To_year)
        {
            if (current_month > To_month)
            {
                status = "on going";
                Task[7][i] = status;
            }
            if (current_month == To_month)
            {
                if (current_day <= To_day)
                {
                    status = "on going";
                    Task[7][i] = status;
                }
                else
                {
                    status = "Delayed";
                    Task[7][i] = status;
                }
            }
        }

        //-------------------------------------------------------------------------------------------------------------------
       //asking user if she wants to add more tasks
       //-------------------------------------------------------------------------------------------------------------------

        int n;
        cout << "Dear user..! Do you want to add more tasks...?  (Type   *1 for yes*  AND  *0 for NO* ) ";
        cin >> n;
        if (n == 0)
        {
            break;
        }

    }
    ++k;
    func();
}

//-------------------------------------------------------------------------------------------------------------------
//************************************************DISPLAYING TASK**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

void task::display()
{
    //-------------------------------------------------------------------------------------------------------------------
    //it will display all the info of tasks
    //-------------------------------------------------------------------------------------------------------------------

    cout << fixed << setprecision(5);
    cout << "\n\tSo, the details of your task are= \n";
    cout << "\n  Task ID  \tProject ID   \tTitle\t\tFrom Date\t\tTo Date\t\t Member ID\t\tResources\tstatus\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << fixed << setprecision(4);
            if (Task[2][i] != "0")
                cout << "   " << Task[j][i] << "\t\t";
        }
        cout << "\n";
    }
    func();
}


//-------------------------------------------------------------------------------------------------------------------
//************************************************DISPLAYING TASK IN A FILE**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

void task::func()
{
    //-------------------------------------------------------------------------------------------------------------------
    //it will display all the info of tasks in the text file
    //-------------------------------------------------------------------------------------------------------------------

    ofstream myfile("abc.txt");
    myfile << fixed << setprecision(4);
    myfile << "\n\tSo, the details of your task are= \n";
    myfile << "\n  Task ID\t   Project ID\t   Title\t\t     From Date   \t\tTo Date  \t\t Member ID\t\t Resources  \tstatus\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            myfile << fixed << setprecision(6);
            if (Task[2][i] != "0")
                myfile << "   " << Task[j][i] << "\t\t ";
        }
        myfile << "\n";
    }
    myfile.close();

}


//-------------------------------------------------------------------------------------------------------------------
//************************************************CHECKING OF STATUS**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

void task::get_status()
{
    //-------------------------------------------------------------------------------------------------------------------
    //it will display all the delayed tasks
    //-------------------------------------------------------------------------------------------------------------------

    for (int i = 0; i < 4; i++)
    {
        if (Task[7][i] == "Delayed")

            cout << "\n The delayed tasks are: " << Task[2][i];
        else
        {
            cout << "\n\t\t*************************************";
            cout << "\n\t\t|  You have no delayed task: ......|";
            cout << "\n\t\t*************************************\n";
            break;
        }

    }

}

//-------------------------------------------------------------------------------------------------------------------
//************************************************DELETING OF TASK**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------

void task::DELETE_task()
{
    int spa = 0;          //just to store the users choice
    cout << "\n \n\t\t Now you can delete your task: ";
    cout << "\n\t\t Enter the task name you want to delete.....Dear USER...! ";
    cout << "\n\t For your ease we have got the list of the tasks that you entered for this project: ";
    for (int i = 0; i < 4; i++)
    {
        cout << "\n\t" << i + 1 << " . " << Task[2][i];
    }
    cout << "Now just tell us NUMERICALLY..(i.e 1,2,3....)  ";
    cin >> spa;

    //for (int j = 0;j < 8;j++)
    Task[2][--spa] = "0";
    cout << "\n\n\t\t****************DELETED SUCCESSFULLY********************";
    func();
}
//-------------------------------------------------------------------------------------------------------------------
//************************************************EDITING OF TASK**************************************************                                    
//-------------------------------------------------------------------------------------------------------------------
void task::EDIT_task()
{

    //-------------------------------------------------------------------------------------------------------------------
    //All the required identifiers
    //-------------------------------------------------------------------------------------------------------------------
    int space = 0;          //just to store the users choice
    int n;              //just to store the users choice
    string data;                     //just to store the users choice
    char opt;                     //just to store the users choice

    //-------------------------------------------------------------------------------------------------------------------
    // Allowing the user to edit the data
    //-------------------------------------------------------------------------------------------------------------------
    cout << "\n \n\t\t Now you can edit your task: ";
label4:
    cout << "\n\t\t Dear USER...! what do you want to edit..?  \n\t Please select from the below given options  :  \n\t\tNow just tell us NUMERICALLY..(i.e 1,2,3....)  \n";
    cout << "\n\t1. Title\n\t2. From Date\n\t3. To Date\n\t4. Member ID\t\n5. Resources "; //displaying the options
    cin >> space;

    //-------------------------------------------------------------------------------------------------------------------
    //                                                      first option
    //-------------------------------------------------------------------------------------------------------------------

    if (space == 1)
    {
        cout << "\n\t Select the titles of the task that are present for this project: \n\ttell us NUMERICALLY..(i.e 1,2,3....)  ";
        for (int i = 0; i < 4; i++)
        {
            cout << "\n\t" << i + 1 << " . " << Task[2][i];
        }
        cin >> n;

        cout << "\n\t Enter the new title...  :   ";
        cin.ignore();
        getline(cin, data);
        Task[2][--n] = data;
        cout << "\n\n\t\t****************EDITED SUCCESSFULLY********************";

        cout << "\n\tDear user...! Do you want to edit more...(y/n)";
        cin >> opt;
        if (opt == 'y')
            goto label4;
    }

    //-------------------------------------------------------------------------------------------------------------------
    //                                         Second Option
    //-------------------------------------------------------------------------------------------------------------------

    if (space == 2)
    {

        //-------------------------------------------------------------------------------------------------------------------
        //                                    Identifiers
        //-------------------------------------------------------------------------------------------------------------------
        int d, m, y, d1, m1, y1, p;

        //-------------------------------------------------------------------------------------------------------------------
        //                                   Allowing the access to USER
        //-------------------------------------------------------------------------------------------------------------------
        cout << "\n\t Select the titles of the task that are present for this project: \n\ttell us NUMERICALLY..(i.e 1,2,3....)  ";
        for (int i = 0; i < 4; i++)
        {
            cout << "\n\t" << i + 1 << " . " << Task[3][i];
        }
        cin >> n;

    label6:
        cout << "\n\t Enter the another starting date...  :      ";
        cin >> d >> m >> y;

        cout << "\n\t Do you want to re enter the current date :      (1/0)";
        cin >> p;
        if (p == 1)
        {
            cout << "\n\t Enter the  current date...  :      ";
            cin >> d1 >> m1 >> y1;
        }

        if (p == 0)

        {
            d1 = current_day;
            m1 = current_month;
            y1 = current_year;
        }


        //-------------------------------------------------------------------------------------------------------------------
        //                      Validating Date
        //-------------------------------------------------------------------------------------------------------------------

        if (Validate(d, m, y) == false)
        {
            char rough;                             //this will only have the response from the user
            cout << "\n\t\tYou entered a wrong value......\n\t\t\t do you want to enter again...   (y/n)";
            cin >> rough;
            if (rough == 'y')                        //the meaning of this patch is just to allow user to give the value for date if it is entered wrong
                goto label6;
        }

        //-------------------------------------------------------------------------------------------------------------------
        //                                                      Storing value
        //-------------------------------------------------------------------------------------------------------------------
        data = to_string(d) + " / " + to_string(m) + " / " + to_string(y);
        Task[3][--n] = data;
        cout << "\n\n\t\t****************EDITED SUCCESSFULLY********************";


        //-------------------------------------------------------------------------------------------------------------------
        // It will change the status accordingly
        //-------------------------------------------------------------------------------------------------------------------
        if (m1 < m)
        {
            status = "on going";
            Task[7][n] = status;
        }
        if (m1 == m)
        {
            if (d1 <= d)
            {
                status = "on going";
                Task[7][n] = status;
            }
            else
            {
                status = "Delayed";
                Task[7][n] = status;
            }
        }
        if (y1 < y)
        {
            if (m1 > m)
            {
                status = "on going";
                Task[7][n] = status;
            }
            if (m1 == m)
            {
                if (current_day <= To_day)
                {
                    status = "on going";
                    Task[7][n] = status;
                }
                else
                {
                    status = "Delayed";
                    Task[7][n] = status;
                }
            }
        }
        cout << "\n\tDear user...! Do you want to edit more...(y/n)";
        cin >> opt;
        if (opt == 'y')
            goto label4;
    }
    if (space == 3)
    {
        //-------------------------------------------------------------------------------------------------------------------
       //                                    Identifiers
       //-------------------------------------------------------------------------------------------------------------------
        int d, m, y, d1, m1, y1, p;
        d = m = y = d1 = m1 = y1 = p = 0;

        //-------------------------------------------------------------------------------------------------------------------
        //                                   Allowing the access to USER
        //-------------------------------------------------------------------------------------------------------------------
        cout << "\n\t Select the titles of the task that are present for this project: \n\ttell us NUMERICALLY..(i.e 1,2,3....)  ";
        for (int i = 0; i < 4; i++)
        {
            cout << "\n\t" << i + 1 << " . " << Task[4][i];
        }
        cin >> n;

    label7:
        cout << "\n\t Enter the another ending date...  :      ";
        cin >> d >> m >> y;

        cout << "\n\t Do you want to re enter the current date :      (1/0)";
        cin >> p;
        if (p == 1)
        {
            cout << "\n\t Enter the  current date...  :      ";
            cin >> d1 >> m1 >> y1;
        }

        if (p == 0)

        {
            d1 = current_day;
            m1 = current_month;
            y1 = current_year;
        }

        //-------------------------------------------------------------------------------------------------------------------
        //                      Validating Date
        //-------------------------------------------------------------------------------------------------------------------

        if (Validate(d, m, y) == false)
        {
            char rough;                             //this will only have the response from the user
            cout << "\n\t\tYou entered a wrong value......\n\t\t\t do you want to enter again...   (y/n)";
            cin >> rough;
            if (rough == 'y')                        //the meaning of this patch is just to allow user to give the value for date if it is entered wrong
                goto label7;
        }

        //-------------------------------------------------------------------------------------------------------------------
       //                                                      Storing value
       //-------------------------------------------------------------------------------------------------------------------
        data = to_string(d) + " / " + to_string(m) + " / " + to_string(y);
        Task[4][--n] = data;

        //-------------------------------------------------------------------------------------------------------------------
        // It will change the status accordingly
        //-------------------------------------------------------------------------------------------------------------------

        if (m1 < m)
        {
            status = "on going";
            Task[7][n] = status;
        }
        if (m1 == m)
        {
            if (d1 <= d)
            {
                status = "on going";
                Task[7][n] = status;
            }
            else
            {
                status = "Delayed";
                Task[7][n] = status;
            }
        }
        if (y1 < y)
        {
            if (m1 > m)
            {
                status = "on going";
                Task[7][n] = status;
            }
            if (m1 == m)
            {
                if (current_day <= To_day)
                {
                    status = "on going";
                    Task[7][n] = status;
                }
                else
                {
                    status = "Delayed";
                    Task[7][n] = status;
                }
            }
        }

        cout << "\n\n\t\t****************EDITED SUCCESSFULLY********************";

        cout << "\n\tDear user...! Do you want to edit more...(y/n)";
        cin >> opt;
        if (opt == 'y')
            goto label4;
    }
    if (space == 4)
    {
        //soon 
    }
    if (space == 5)
    {
        // soon
    }
    func();
}

//-------------------------------------------------------------------------------------------------------------------
//************************************************MAIN FUNCTION*******************************************                                    
//-------------------------------------------------------------------------------------------------------------------


int main()
{
    int addd, EDIT, DELETE, DISPLAY, response;
    addd = EDIT = DELETE = DISPLAY = response = 0;
    int N, N1, N2, N3, N4;
    N = N1 = N2 = N3 = N4 = 0;
    char sth2;
    Project P, P1, P2, P3;
    task T1, T2, T3, T;
    teammember M, M1, M2, M3;
    Resources res, res1, res2, res3;

    for (int i = 0; i < 10; i++)
    {
        cout << "\n\n\t\t                                        ___________";

        cout << "\n\n\t\t ************************************  | MAIN MENU  |****************************************** ";
        cout << "\n\t\t                                        ___________";
        cout << "\n\n\t\t        --------------------------------------";
        cout << "\n\t\t\t|      1) ADDING ACTIVITIES\t     |\n\t\t\t|      2) EDITING ACTIVITIES\t     |\n\t\t\t|      3) DELETING ACTIVITIES\t     |\n\t\t\t|      4) DISPLAYING ACTIVITIES\t     |\n\t\t\t|      5) GET STATUS\t\t     |\n\t\t\t|       6) EXIT\t\t\t     |" << endl;
        cout << "\t\t         ------------------------------------\n\n\t\t\t INPUT...........(1 2 3 4 5 6)________";
        cin >> response;

        //-------------------------------------------------------------------------------------------------------------------
        //************************************************ADDING ACTIVITIES*******************************************                                    
        //-------------------------------------------------------------------------------------------------------------------

        if (response == 1)
        {
        label4:
            cout << "\n\n\t\t                                   __________________";
            cout << "\n\n\t\t ********************************  | ADDING ACTIVITIES |************************************** ";
            cout << "\n\t\t                                     ___________________";
            cout << "\n\n\t\t        --------------------------------------";
            cout << "\n\t\t\t|      1) ADD PROJECT\t\t     |\n\t\t\t|      2) ADD TASK\t\t     |\n\t\t\t|      3) ADD MEMBERS\t\t     |\n\t\t\t|      4) ADD RESOURCES\t\t     |" << endl;
            cout << "\t\t         ------------------------------------\n\n\t\t\t INPUT...........(1 2 3 4 )";
            cin >> addd;

            //---------------------------------------------------------------------------------------------------------------------------------

            //----------------------------------------------------------------------------------------------------------------------------------

            if (addd == 1)
            {
                static int variab = 0;
                if (variab == 0)
                {

                    P.add();
                }
                if (variab == 1)
                {
                    P.add();
                }

                if (variab == 2)
                {

                    P.add();
                }

                if (variab == 3)
                {

                    P.add();
                }


            }

            //=================================================================================================================================

            if (addd == 2)
            {
                cout << "\n\t\t Dear user...!.... Select the project for which you want to add the tasks...!";
                P.display();
                cout << "\n\t\t SELECT FROM THE ABOVE......";
                cin >> N2;
                if (N2 == 1)
                {

                    T.ADD_task(1);
                }
                if (N2 == 2)
                {
                    T1.ADD_task(2);
                }

                if (N2 == 3)
                {

                    T2.ADD_task(3);
                }

                if (N2 == 4)
                {

                    T3.ADD_task(4);
                }

            }


            //=================================================================================================================================

            if (addd == 3)
            {
                int x, X;
                cout << "\n\t\t Dear user...!.... Select the project you want to make the changes in...!";
                P.display();
                cout << "\n\t\t SELECT FROM THE ABOVE......";
                cin >> N2;
                if (N2 == 1)
                {

                    cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the members ...!";
                    T.display();
                    cout << "\n\t\t Response......";
                    cin >> x;

                    if (x == 1)
                    {
                        M.membername();
                        M.add();
                    }

                    if (x == 2)
                    {
						M.membername();
						M.add();
                    }

                    if (x == 3)
                    {
						M.membername();
						M.add();
                    }
                    if (x == 4)
                    {
						M.membername();
						M.add();
                    }

                }
                if (N2 == 2)
                {
                    cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the members ...!";
                    T1.display();
                    cout << "\n\t\t Response......";
                    cin >> x;

                    if (x == 1)
                    {
                        M.membername();
                        M.add();

                    }

                    if (x == 2)
                    {
                        M1.membername();
                        M1.add();
                    }

                    if (x == 3)
                    {
                        M2.membername();
                        M2.add();
                    }
                    if (x == 4)
                    {
                        M3.membername();
                        M3.add();

                    }

                }

                if (N2 == 3)
                {

                    cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the members ...!";
                    T2.display();
                    cout << "\n\t\t Response......";
                    cin >> x;

                    if (x == 1)
					{
                        M.membername();
                        M.add();
                    }

                    if (x == 2)
                    {
                        M1.membername();
                        M1.add();
                    }

                    if (x == 3)
                    {

                        M2.membername();
                        M2.add();
                    }
                    if (x == 4)
                    {
                        M3.membername();
                        M3.add();

                    }

                }

                if (N2 == 4)
                {

                    cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the members ...!";
                    T3.display();
                    cout << "\n\t\t Response......";
                    cin >> x;

                    if (x == 1)
                    {
                        M.membername();
                        M.add();

                    }

                    if (x == 2)
                    {
                        M1.membername();
                        M1.add();
                    }

                    if (x == 3)
                    {

                        M2.membername();
                        M2.add();
                    }
                    if (x == 4)
                    {
                        M3.membername();
                        M3.add();

                    }

                }


            }



        }
        //=================================================================================================================================

        if (addd == 4)
        {
            int x;
            cout << "\n\t\t Dear user...!.... Select the project you want to make the changes in...!";
            P.display();
            cout << "\n\t\t SELECT FROM THE ABOVE......";
            cin >> N2;
            if (N2 == 1)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.Adding();
                }

                if (x == 2)
                {
                    res1.Adding();

                }

                if (x == 3)
                {

                    res2.Adding();
                }
                if (x == 4)
                {
                    res3.Adding();

                }

            }
            if (N2 == 2)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T1.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.Adding();
                }

                if (x == 2)
                {
                    res1.Adding();

                }

                if (x == 3)
                {

                    res2.Adding();
                }
                if (x == 4)
                {
                    res3.Adding();

                }
            }

            if (N2 == 3)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T2.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.Adding();
                }

                if (x == 2)
                {
                    res1.Adding();

                }

                if (x == 3)
                {

                    res2.Adding();
                }
                if (x == 4)
                {
                    res3.Adding();

                }
            }

            if (N2 == 4)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T3.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.Adding();
                }

                if (x == 2)
                {
                    res1.Adding();

                }

                if (x == 3)
                {

                    res2.Adding();
                }
                if (x == 4)
                {
                    res3.Adding();

                }
            }


        }
        //_________________________________________________________________________________________________________________________________________________________________
        cout << "\n\t\t*************************************************************";
        cout << "\n\t\t|  Do you want to do more adding activities......(1/0)......|";
        cout << "\n\t\t*************************************************************\n\t\t Response.....";
        cin >> N1;
        if (N1 == 1)
        {
            goto label4;
        }

    }


    //-------------------------------------------------------------------------------------------------------------------
//************************************************EDITING ACTIVITIES*******************************************                                    
//-------------------------------------------------------------------------------------------------------------------
    if (response == 2)
    {
    label5:
        cout << "\n\n\t\t                                    __________________";

        cout << "\n\n\t\t ********************************  | EDITING ACTIVITIES |************************************** ";
        cout << "\n\t\t                                      ___________________";
        cout << "\n\n\t\t        --------------------------------------";
        cout << "\n\t\t\t|      1) EDIT PROJECT\t     |\n\t\t\t|      2) EDIT TASK\t     |\n\t\t\t|      3) EDIT MEMBERS\t     |\n\t\t\t|      4) EDIT RESOURCES\t     |" << endl;
        cout << "\t\t         ------------------------------------\n\n\t\t\t INPUT...........(1 2 3 4 )";
        cin >> EDIT;

        //_________________________________________________________________________________________________________________________________________________________________

        if (EDIT == 1)
        {

            P.edit();

        }
        //=================================================================================================================================
        if (EDIT == 2)
        {
            cout << "\n\t\t Dear user...!.... Select the project you want to Edit the task in...!";
            P.display();
            cout << "\n\t\t SELECT FROM THE ABOVE......";
            cin >> N2;
            if (N2 == 1)
            {

                T.EDIT_task();
            }
            if (N2 == 2)
            {
                T1.EDIT_task();
            }

            if (N2 == 3)
            {

                T2.EDIT_task();
            }

            if (N2 == 4)
            {

                T3.EDIT_task();
            }

        }
        //=================================================================================================================================
        if (EDIT == 3)
        {
            int x;
            cout << "\n\t\t Dear user...!.... Select the project you want to make the changes in...!";
            P.display();
            cout << "\n\t\t SELECT FROM THE ABOVE......";
            cin >> N2;
            if (N2 == 1)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to edit the members ...!";
                T.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    M.print();
                    M.edit();
                }

                if (x == 2)
                {
                    M1.print();
                    M1.edit();

                }

                if (x == 3)
                {

                    M2.print();
                    M2.edit();
                }
                if (x == 4)
                {
                    M3.print();
                    M3.edit();

                }

            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 2)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T1.display();
                cout << "\n\t\t Response......";
                cin >> x;


                if (x == 1)
                {
                    M.print();
                    M.edit();
                }

                if (x == 2)
                {
                    M1.print();
                    M1.edit();

                }

                if (x == 3)
                {

                    M2.print();
                    M2.edit();
                }
                if (x == 4)
                {
                    M3.print();
                    M3.edit();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 3)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T2.display();
                cout << "\n\t\t Response......";
                cin >> x;


                if (x == 1)
                {
                    M.print();
                    M.edit();
                }

                if (x == 2)
                {
                    M1.print();
                    M1.edit();

                }

                if (x == 3)
                {

                    M2.print();
                    M2.edit();
                }
                if (x == 4)
                {
                    M3.print();
                    M3.edit();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 4)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T3.display();
                cout << "\n\t\t Response......";
                cin >> x;


                if (x == 1)
                {
                    M.print();
                    M.edit();
                }

                if (x == 2)
                {
                    M1.print();
                    M1.edit();

                }

                if (x == 3)
                {

                    M2.print();
                    M2.edit();
                }
                if (x == 4)
                {
                    M3.print();
                    M3.edit();

                }
            }

        }
        //=================================================================================================================================
        if (EDIT == 4)
        {
            int x;
            cout << "\n\t\t Dear user...!.... Select the project you want to make the changes in...!";
            P.display();
            cout << "\n\t\t SELECT FROM THE ABOVE......";
            cin >> N2;
            if (N2 == 1)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to edit the resources ...!";
                T.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.decision_to_edit();
                }

                if (x == 2)
                {
                    res1.decision_to_edit();

                }

                if (x == 3)
                {

                    res2.decision_to_edit();
                }
                if (x == 4)
                {
                    res3.decision_to_edit();

                }

            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 2)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T1.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.decision_to_edit();
                }

                if (x == 2)
                {
                    res1.decision_to_edit();

                }

                if (x == 3)
                {

                    res2.decision_to_edit();
                }
                if (x == 4)
                {
                    res3.decision_to_edit();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 3)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T2.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.decision_to_edit();
                }

                if (x == 2)
                {
                    res1.decision_to_edit();

                }

                if (x == 3)
                {

                    res2.decision_to_edit();
                }
                if (x == 4)
                {
                    res3.decision_to_edit();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 4)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T3.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.decision_to_edit();
                }

                if (x == 2)
                {
                    res1.decision_to_edit();

                }

                if (x == 3)
                {

                    res2.decision_to_edit();
                }
                if (x == 4)
                {
                    res3.decision_to_edit();

                }
            }

        }
        //=================================================================================================================================


        cout << "\n\t\t*************************************************************";
        cout << "\n\t\t|  Do you want to do more editing activities......(1/0)......|";
        cout << "\n\t\t*************************************************************\n\t\t Response.....";
        cin >> N1;
        if (N1 == 1)
        {
            goto label5;
        }

    }

    //-------------------------------------------------------------------------------------------------------------------
//************************************************DELETING ACTIVITIES*******************************************                                    
//-------------------------------------------------------------------------------------------------------------------
    if (response == 3)
    {
    label6:
        cout << "\n\n\t\t                                    _____________________";

        cout << "\n\n\t\t ********************************  | DELETING ACTIVITIES |************************************** ";
        cout << "\n\t\t                                      _____________________";
        cout << "\n\n\t\t        --------------------------------------";
        cout << "\n\t\t\t|      1) DELETE PROJECT\t     |\n\t\t\t|      2) DELETE TASK\t     |\n\t\t\t|      3) DELETE MEMBERS\t     |\n\t\t\t|      4) DELETE RESOURCES\t     |" << endl;
        cout << "\t\t         ------------------------------------\n\n\t\t\t INPUT...........(1 2 3 4 )";
        cin >> DELETE;
        //=================================================================================================================================
        if (DELETE == 1)
        {

            P.dElete();

        }
        //=================================================================================================================================
        if (DELETE == 2)
        {
            cout << "\n\t\t Dear user...!.... Select the project from which you want to Delete the task ...!";
            P.display();
            cout << "\n\t\t SELECT FROM THE ABOVE......";
            cin >> N2;
            if (N2 == 1)
            {

                T.DELETE_task();
            }
            if (N2 == 2)
            {
                T1.DELETE_task();
            }

            if (N2 == 3)
            {

                T2.DELETE_task();
            }

            if (N2 == 4)
            {

                T3.DELETE_task();
            }

        }
        //=================================================================================================================================
        if (DELETE == 3)
        {
            int x;
            cout << "\n\t\t Dear user...!.... Select the project you want to make the changes in...!";
            P.display();
            cout << "\n\t\t SELECT FROM THE ABOVE......";
            cin >> N2;
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 1)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to delete the members ...!";
                T.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    M.print();
                    M.del();
                }

                if (x == 2)
                {
                    M1.print();
                    M1.del();

                }

                if (x == 3)
                {

                    M2.print();
                    M2.del();
                }
                if (x == 4)
                {
                    M3.print();
                    M3.del();

                }

            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 2)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T1.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    M.print();
                    M.del();
                }

                if (x == 2)
                {
                    M1.print();
                    M1.del();

                }

                if (x == 3)
                {

                    M2.print();
                    M2.del();
                }
                if (x == 4)
                {
                    M3.print();
                    M3.del();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 3)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T2.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    M.print();
                    M.del();
                }

                if (x == 2)
                {
                    M1.print();
                    M1.del();

                }

                if (x == 3)
                {

                    M2.print();
                    M2.del();
                }
                if (x == 4)
                {
                    M3.print();
                    M3.del();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 4)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T3.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    M.print();
                    M.del();
                }

                if (x == 2)
                {
                    M1.print();
                    M1.del();

                }

                if (x == 3)
                {

                    M2.print();
                    M2.del();
                }
                if (x == 4)
                {
                    M3.print();
                    M3.del();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________


        }
        //=================================================================================================================================
        if (DELETE == 4)
        {
            int x;
            cout << "\n\t\t Dear user...!.... Select the project you want to make the changes in...!";
            P.display();
            cout << "\n\t\t SELECT FROM THE ABOVE......";
            cin >> N2;
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 1)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to delete the resources ...!";
                T.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.decision_to_delete();
                }

                if (x == 2)
                {
                    res1.decision_to_delete();

                }

                if (x == 3)
                {

                    res2.decision_to_delete();
                }
                if (x == 4)
                {
                    res3.decision_to_delete();

                }

            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 2)
            {
                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T1.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.decision_to_delete();
                }

                if (x == 2)
                {
                    res1.decision_to_delete();

                }

                if (x == 3)
                {

                    res2.decision_to_delete();
                }
                if (x == 4)
                {
                    res3.decision_to_delete();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 3)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T2.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.decision_to_delete();
                }

                if (x == 2)
                {
                    res1.decision_to_delete();

                }

                if (x == 3)
                {

                    res2.decision_to_delete();
                }
                if (x == 4)
                {
                    res3.decision_to_delete();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________

            if (N2 == 4)
            {

                cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
                T3.display();
                cout << "\n\t\t Response......";
                cin >> x;

                if (x == 1)
                {
                    res.decision_to_delete();
                }

                if (x == 2)
                {
                    res1.decision_to_delete();

                }

                if (x == 3)
                {

                    res2.decision_to_delete();
                }
                if (x == 4)
                {
                    res3.decision_to_delete();

                }
            }
            //_________________________________________________________________________________________________________________________________________________________________


        }


        cout << "\n\t\t*************************************************************";
        cout << "\n\t\t|  Do you want to do more deleting activities......(1/0)......|";
        cout << "\n\t\t*************************************************************\n\t\t Response.....";
        cin >> N1;
        if (N1 == 1)
        {
            goto label6;
        }
    }

    //-------------------------------------------------------------------------------------------------------------------
//************************************************DISPLAYING ACTIVITIES*******************************************                                    
//-------------------------------------------------------------------------------------------------------------------
    if (response == 4)
    {

        cout << "\n\n\t\t                                    _______________________";

        cout << "\n\n\t\t ********************************  | DISPLAYING ACTIVITIES |************************************** ";
        cout << "\n\t\t                                    _______________________";
        cout << "\n\n\t\t        --------------------------------------";
        cout << "\n\t\t\t|      1) DISPLAY PROJECT\t     |\n\t\t\t|      2) DISPLAY TASK\t\t      |\n\t\t\t|      3) DISPLAY MEMBERS\t     |\n\t\t\t|      4) DISPLAY RESOURCES\t     |" << endl;
        cout << "\t\t         ------------------------------------\n\n\t\t\t INPUT...........(1 2 3 4 )";
        cin >> DISPLAY;


        if (DISPLAY == 1)
        {

            P.display();

        }

        //...........______________________________________________________________________________________________________________________________________________________________________

        if (DISPLAY == 2)
        {
            cout << "\n\t\t Dear user...!.... Select the project from which you want to Delete the task ...!";
            P.display();
            cout << "\n\t\t SELECT FROM THE ABOVE......";
            cin >> N2;
            if (N2 == 1)
            {

                T.display();
            }
            if (N2 == 2)
            {
                T1.display();
            }

            if (N2 == 3)
            {

                T2.display();
            }

            if (N2 == 4)
            {

                T3.display();
            }

        }

        //___________________________________________________________________________________________________________________________________________________________________________________

        if (DISPLAY == 3)
        {

        }

        //_______________________________________________________________________________________________________________________________________________________________________________________

        if (DISPLAY == 4)

        {
            int x;
            cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to delete the resources ...!";
            T.display();
            cout << "\n\t\t Response......";
            cin >> x;

            if (x == 1)
            {
                res.displayInfo();
            }

            if (x == 2)
            {
                res1.displayInfo();

            }

            if (x == 3)
            {

                res2.displayInfo();
            }
            if (x == 4)
            {
                res3.displayInfo();

            }

        }
        if (N2 == 2)
        {
            int x;
            cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
            T1.display();
            cout << "\n\t\t Response......";
            cin >> x;
            //_________________________________________________________________________________________________________________________________________________________________


            if (x == 1)
            {
                res.displayInfo();
            }

            if (x == 2)
            {
                res1.displayInfo();

            }

            if (x == 3)
            {

                res2.displayInfo();
            }
            if (x == 4)
            {
                res3.displayInfo();

            }
        }
        //_________________________________________________________________________________________________________________________________________________________________

        if (N2 == 3)
        {
            int x;
            cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
            T2.display();
            cout << "\n\t\t Response......";
            cin >> x;


            if (x == 1)
            {
                res.displayInfo();
            }

            if (x == 2)
            {
                res1.displayInfo();

            }

            if (x == 3)
            {

                res2.displayInfo();
            }
            if (x == 4)
            {
                res3.displayInfo();

            }
        }
        //_________________________________________________________________________________________________________________________________________________________________

        if (N2 == 4)
        {
            int x;
            cout << "\n\t\t Dear user...!....  Now Select the Task for which you want to add the resources ...!";
            T3.display();
            cout << "\n\t\t Response......";
            cin >> x;


            if (x == 1)
            {
                res.displayInfo();
            }

            if (x == 2)
            {
                res1.displayInfo();

            }

            if (x == 3)
            {

                res2.displayInfo();
            }
            if (x == 4)
            {
                res3.displayInfo();

            }
        }

    }

    //_____________________________________________________________________________________________________________________________________________________________________________________________


//-------------------------------------------------------------------------------------------------------------------
//************************************************GETTING STATUS *******************************************                                    
//-------------------------------------------------------------------------------------------------------------------

    if (response == 5)
    {
        cout << "\n\t\t Dear user...!.... Select the project from which you want to Display the status of the task ...!";
        P.display();
        cout << "\n\t\t SELECT FROM THE ABOVE......";
        cin >> N;

        if (N == 1)
        {

            T.get_status();
        }
        else if (N == 2)
        {
            T1.get_status();
        }

        else  if (N == 3)
        {

            T2.get_status();
        }

        else if (N == 4)
        {

            T3.get_status();
        }
    }
    //-------------------------------------------------------------------------------------------------------------------
//************************************************EXITING ALL *******************************************                                    
//-------------------------------------------------------------------------------------------------------------------
    if (response == 6)
        return 0;


}
