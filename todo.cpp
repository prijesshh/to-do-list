#include<iostream>
#include<fstream>
#include<vector>
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
        cout<<"Do you want to add another task?(Y/y)";
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
    }
    void showtask()
    {
        cout<<endl;
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
            for(int i=0;i<readtask.size();i++)
            {
                cout<<i+1<<"."<<readtask[i]<<endl;
            } 
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
        cout<<"Task sucessfully deleted."<<endl;
        writetasktofile(readtask);
        showtask();
    }
    void delall()
    {
        cout<<"\n";
        vector<string> deltask;
        char choice;
        cout<<"Are you sure you want to delete all your task?(Y/y)"<<endl;
        cin>>choice;
        cin.ignore();
        if(choice=='y'||choice=='Y')
        {
            string temp3;
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
                cout<<"No task is added yet..."<<endl;
             }
             else
                {
                     while(getline(file,temp3)) 
                     {
                     deltask.push_back(temp3);
                     }
                deltask.clear();
                writetasktofile(deltask);
                cout<<"All task has been deleted."<<endl;
             
               } 
            } 
         }
         else
         {
            cout<<"Canceled task deleteion"<<endl;
         }  
        }     
    };
int main()
{
    task t;
    mark m;
    del d;
 int choice;
 cout<<"TO_DO LIST"<<endl;
 do
 {
    cout<<"\n\n";
    cout<<"Enter your choice:"<<endl;
    cout<<"1.Add task"<<endl;
    cout<<"2.List task"<<endl;
    cout<<"3.Mark task as done"<<endl;
    cout<<"4.Unmark a task"<<endl;
    cout<<"5.Delete task"<<endl;
    cout<<"6.Clear all task"<<endl;
    cout<<"7.Exit"<<endl;
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
        t.gettask();
        break;

        case 2:
        t.showtask();
        break;

        case 3:
        m.marktask();
        break;

        case 4:
        m.unmark();
        break;


        case 5:
        d.delparticular();
        break;

        case 6:
        d.delall();
        break;

        case 7:
        cout<<"Exiting the program....."<<endl;
        break;

        default:
        cout<<"Invalid choice.\nTry again:"<<endl;
    }
 }while(choice!=7);
 return 0;
}