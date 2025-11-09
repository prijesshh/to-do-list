#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class task
{
    protected:
    vector<string> taskstr;//dynamic array
    string temp;
    //vector ma kei rakhna first ma temorary string ma data line 
    //ani vector ma oush back garne
    char condition;
    vector <string> readtask;//file bata read gareko task haru
    public:
    void gettask()
    {
        do
        {
            cout<<endl;
        cout<<"Enter the task:"<<endl;
        //cin>>temp; cin le after space read gardaina so
        getline(cin,temp);
        taskstr.push_back(temp);
        cout<<"Do you want to add another task?(y/n)";
        cin>>condition;
        cin.ignore();//cin codnition le \ny\n dinxa ani getline work gardaina so
        }while(condition=='y' || condition =='Y');
        appendtasktofile(taskstr);
    }
    void appendtasktofile(vector<string> add)
    {
        fstream file("file.txt", ios::app);
        if(!file)
        {
            cout<<"Error occurred task couldn't be added to the file."<<endl;
        }
        else
        {
            for(int i=0;i<add.size();i++)
            {
                file<<"▫"<<add[i]<<endl;//vector empty xaina vane we can use it like array
            }
            cout<<"Task added sucessfully."<<endl;
        }
    }
      void writetasktofile(vector<string> add)
    {
        fstream file("file.txt", ios::out);
        if(!file)
        {
            cout<<"Error occurred task couldn't be added to the file."<<endl;
        }
        else
        {
            for(int i=0;i<add.size();i++)
            {
                file<<add[i]<<endl;//vector empty xaina vane we can use it like array
            }
        }
         file.close();
    }
    void readfromfile()
    {
         readtask.clear();
        string temp2;
        fstream file("file.txt", ios::in);
        if(!file)
        {
            cout<<"Error occurred task couldn't be shown."<<endl;
        }
        else
        {
            if(file.peek()==EOF)//peek looks at next character in
            //file and that is first character of data we have kept so =EOF
            //garem vane if empty mathi ko statement true hunxa
            //if(file.peek()==eof()) yo chai gardainam bcz .eof is fn but EOF is const
            {
                cout<<"No task is added yet"<<endl;
            }
            else
            {
               while(getline(file,temp2)) 
            {
                readtask.push_back(temp2);
            }
            }
        }
         file.close();
    }
    void showtask()
    {
        cout<<endl;
       readfromfile();
        for(int i=0;i<readtask.size();i++)
            {
                cout<<i+1<<"."<<readtask[i]<<endl;
            } 
    }
    void search()
    {
        readfromfile();
        cout<<"\n";
        bool found=false;
        string s;
        cout<<"Enter the task you want to search"<<endl;
        getline(cin,s);
        for(int i =0;i<readtask.size();i++)
        {
             if(s==readtask[i].substr(3))
            {
                cout<<"Task found:"<<endl;
                cout<<i+1<<"."<<readtask[i];
                found=true;
                break;
            }
        } 
        if(!found)//!true → becomes false (0)
        {
            cout<<"Task not found"<<endl;
        }
    }
     void showwithstatus(string status)
        {
            readfromfile();
            for(int i=0;i<readtask.size();i++)
            {
                if(status==readtask[i].substr(0,3))
                {
                    //substr(0,3) takes character from 0 to 3
                    //substr(3) take all character from index 3
                    cout<<i+1<<readtask[i]<<endl;
                }
            }
        }
};
class mark:public task
{
  protected:
  int choice;
  public:
  void marktask()
  {
    showtask();
    cout<<endl;
    string temp3;
    cout<<"Which task you want to mark as complete?"<<endl;
    cin>>choice;
    while(readtask.size()<choice|| choice<1)
    {
        cout<<"Enter a valid choice"<<endl;
        cin>>choice;
        cin.ignore();
    }
    readtask[choice-1]="☑"+readtask[choice-1].substr(3);
    //so readtak[choice-1].substr(1) eslechai 1st char hatauxa but ▫️ yo
    //mulyiple byte ko xa so substr 3 garya
    writetasktofile(readtask);
    showtask();
  }  
  void unmark()
  {
   showtask();
    cout<<endl;
    string temp3;
    cout<<"Which task you want to unmark as complete?"<<endl;
    cin>>choice;
    while(readtask.size()<choice|| choice<1)
    {
        cout<<"Enter a valid choice"<<endl;
        cin>>choice;
        cin.ignore();
    }
    readtask[choice-1]="▫"+readtask[choice-1].substr(3);
    //so readtak[choice-1].substr(1) eslechai 1st char hatauxa but ▫️ yo
    //mulyiple byte ko xa so substr 3 garya
    writetasktofile(readtask);
    showtask();
  }   
};
class del:public task
{
    protected:
    public:
    void delparticular()
    {
        cout<<endl;
        int choice;
        cout<<"Enter the task you want to delete:"<<endl;
        showtask();
        cin>>choice;
        cin.ignore();
        while(readtask.size()<choice|| choice<1)
    {
        cout<<"Enter a valid choice"<<endl;
        cin>>choice;
        cin.ignore();
    }
        readtask.erase(readtask.begin()+choice-1);
        //readtask.begin() is like a pointer which points to the first element
        //of vector ani choice-1 is index
        cout<<"Task successfully deleted."<<endl;
        writetasktofile(readtask);
        showtask();
    }
    void delall()
    {
        cout<<"\n";
        vector<string> deltask;
        char choice;
        cout<<"Are you sure you want to delete all your task?(y/n)"<<endl;
        cin>>choice;
        cin.ignore();
        if(choice=='y'||choice=='Y')
        {
            readfromfile();
            if(readtask.empty())//readtask.size() le unsigned integer return garxa
            {
                cout<<"No task has been added yet"<<endl;
            }
            else{
                readtask.clear();
                writetasktofile(readtask);
                cout<<"All tasks have been cleared."<<endl;
            }
         }
         else
         {
            cout<<"Canceled task deletion."<<endl;
         }  
        }     
    };
    class update:public task
    {
        protected:
        int s;
        string newtask;
        public:
        void updatetask()
        {
            cout<<endl;
            showtask();
            string first;
            cout<<"Select the task you want to update."<<endl;
            cin>>s;
            cout<<"Enter updated task"<<endl;
            cin.ignore();
            getline(cin,newtask);
            first=readtask[s-1].substr(0,3);//readtask[s-1].substr(0,3) le 3 char extract garxa from first 
            readtask[s-1]=first+newtask;
            writetasktofile(readtask);
            cout<<"Task sucessfully updated."<<endl;
            showtask();
            
        }
    };
    class authentication
    {
        private:
        string password;
        string passwordfromfile;
        public:
        bool notempty()
        {
            fstream file("password.txt",ios::in);
            if(!file)
            {
                return false;
            }
            else
            {
                if(file.peek()==EOF)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            file.close();
        }
        void newpassword()
        {
            string check;
            do
            {
                cout<<"Enter your password:"<<endl;
                cin>>password;
                cout<<"Re-enter your password:"<<endl;
                cin>>check;
            }while(password!=check);
            writetopassword(password);
            cout<<"Password sucessfully set."<<endl;
        }
        void writetopassword(string sent)
        {
            fstream file("password.txt",ios::out);
                if(!file)
                {
                cout<<"File not found."<<endl;
                }
                else
                {
                    file<<sent;
                }
            file.close();
        }
        void resetpassword()
        {
            string check;
            readfrompassword();
            cout<<"Enter your current password:"<<endl;
            cin>>check;
            if(check==passwordfromfile)
            newpassword();
        }
        void readfrompassword()
        {
            fstream file("password.txt",ios::in);
            if(!file)
            cout<<"File not found"<<endl;
            else
            {
                file>>passwordfromfile;//file ma euta matra string xa so
            }
            file.close();
        }
        void removepassword()
        {
            string check;
            readfrompassword();
            cout<<"Enter your current password:"<<endl;
            cin>>check;
            if(check==passwordfromfile)
            {
                ofstream file("password.txt");
                {
                    if(!file)
                    cout<<"File not found"<<endl;
                    else
                    {
                        file.close();//file write mmode ma kholne bittikai close=clears file
                    }
                }
            }
        }
        void checkpassword()
        {
            readfrompassword();
            string check;
            int i;
            for( i=3;i>0;i--)
            {
                cout<<"Enter password:"<<endl;
                cin>>check;
                if(passwordfromfile==check)
                {
                    cout<<"Opening the program..."<<endl;
                    break;
                }
                else
                {
                    cout<<"Wrong password you have "<<i<<" attempts left..."<<endl;
                }
            }
            if(i==0)
            {
                cout<<"Too many incorrec attempts"<<endl;
                cout<<"Exiting program..."<<endl;
                exit(-1);
            }
            
        }
    };
int main()
{
    task t;
    mark m;
    del d;
    update u;
    authentication a;
 int choice;
if(a.notempty())
{
    a.checkpassword();
    
}
 cout<<"\nTO_DO LIST"<<endl;
 do
 {
    cout<<"\n\n";
    cout<<"Enter your choice:"<<endl;
    cout<<"1.Add task."<<endl;
    cout<<"2.List task."<<endl;
    cout<<"3.Search task."<<endl;
    cout<<"4.Mark task as completed."<<endl;
    cout<<"5.Revert task to incomplete."<<endl;
    cout<<"6.Update task."<<endl;
    cout<<"7.Delete task."<<endl;
    cout<<"8.Clear all task."<<endl;
    cout<<"9.Authentication"<<endl;
    cout<<"10.Exit."<<endl;
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
        t.gettask();
        break;

        case 2:
        {
            int choice2;
            cout<<"1.Show all task."<<endl;
            cout<<"2.Show completed task."<<endl;
            cout<<"3.Show uncompleted task."<<endl;
            cin>>choice2;
            cin.ignore();
            switch(choice2)
            {
                cout<<endl;
                case 1:
                t.showtask(); 
                break;

                case 2:
                {
                 string status="☑";
                 t.showwithstatus(status);
                 break;
                }

                case 3:
                {
                 string status="▫";
                 t.showwithstatus(status);
                 break;
                }

                break;

            }
            break;
        }

        case 3:
        t.search();
        break;

        case 4:
        m.marktask();
        break;

        case 5:
        m.unmark();
        break;

        case 6:
        u.updatetask();
        break;

        case 7:
        d.delparticular();
        break;

        case 8:
        d.delall();
        break;

        case 9:
        {
            bool forpassword=a.notempty();
            if(!forpassword)//forpassword is true if not empty
            {
                int choice9;
                cout<<"Enter your choice:"<<endl;
                cout<<"1.Set pasword."<<endl;
                cout<<"2.Go back to menu"<<endl;
                cin>>choice9;
                cin.ignore();
                switch (choice9)
                {
                    cout<<endl;
                case 1:
                a.newpassword();
                break;

                case 2:
                cout<<"Returning to main menu..."<<endl;
                break;
                
                default:
                cout<<"Invalid choice"<<endl;
                break;
                }
            }
            else if(forpassword)
            {
               int choice9;
               cout<<"Enter a choice:"<<endl;
               cout<<"1.Reset password."<<endl;
               cout<<"2.Remove password."<<endl;
               cout<<"3.Return to main menu."<<endl;
               cin>>choice9;
               cin.ignore();
               switch(choice9)
               {
                case 1:
                a.resetpassword();
                break;

                case 2:
                a.removepassword();
                break;

                case 3:
                cout<<"Returning to main menu..."<<endl;
                break;

                default:
                cout<<"Invalid choice."<<endl;
               }
            }
        }

        case 10:
        cout<<"Exiting the program....."<<endl;
        break;

        default:
        cout<<"Invalid choice.\nTry again:"<<endl;
    }
 }while(choice!=10);
 return 0;
}