#include <stdlib.h>
#include <fstream>
#include "ui.h"
#pragma once
class messsupervisor:public timetable
{
    int id;
    int i;
    std:sting name;
    char gender;
    float salary;
    float balance;
    std::vector<leave> b(10);
public:
    void messsupervisor_input();
    void menu();
    void view_salary();
    void view_feedback();
};
void messsupervisor::menu()
{   cout<<"\n Menu 1.view time table 2. view salary 3. edit timetable 4. apply leave 5. view feedback 6. create timetable 7.pay salary for workers 8. exit";
    int ch;
    do
    {
        cout<<"\n enter choice:";
        cin>>ch;
        if(ch==1)
        {
            view_timetable();
        }
        else if(ch==2)
        {
            view_salary();
        }
        else if(ch==3)
        {
            edit_timetable(1);
        }
        else if(ch==4)
        {
            b[i].input_leave();
            i++;
        }
        else if(ch==5)
        {
            view_feedback();
        }
        else if(ch==6)
        {
            create_timetable();
        }
        else if(ch==7)
        {   ui E;
            ifstream fin1("messworker.dat",ios::binary|ios::in);
            ofstream fout1("dummy.dat",ios::binary|ios::out);
            while(!fin1.eof())
            {   fin1.read((char*)&E,sizeof(ui));
                E.p3.salary_update(1000);
                fout1.write((char*)&E,sizeof(E));
            }
            fin1.close();
            fout1.close();
            remove("messworker.dat");
            rename("dummy.dat","messworker.dat");
        }
        else if(ch==8)
        {//exit
            break;
        }
        else
            cout<<"\n invalid choice:";
    }while(ch!=5);
}
void messsupervisor::messsupervisor_input()
{   i=0;
    cout<<"\n enter id :";
    cin>>id;
    cout<<"\n enter name:";
    cin>>name;
    cout<<"\n gender(m/f)?:";
    cin>>gender;
    cout<<"\n enter your balance amount in your account : ";
    cin>>balance;
    salary =10000;
    balance=balance+salary;
}
void messsupervisor::view_salary()
{
    cout<<"Current month salary is "<<salary;
    cout<<"Your total salary is "<<balance;
}
void messsupervisor::view_feedback()
{   cout<<"\n Enter which list you want to see 1.student 2.professor 3.mess workers";
    int ch;
    cin>>ch;
    ifstream fin;
    if(ch==1)
    {   fin.open("student_complain.dat",ios::binary|ios::in);
        feedback E;
        while(fin.read((char*)&E,sizeof(E)))
        {   E.print_feedback();

        }

    }
    else if(ch==2)
    {   fin.open("professor_complain.dat",ios::binary|ios::in);
        feedback E;
        while(fin.read((char*)&E,sizeof(E)))
        {   E.print_feedback();

        }

    }
    else if(ch==3)
    {   fin.open("messworker_complain.dat",ios::binary|ios::in);
        feedback E;
        while(fin.read((char*)&E,sizeof(E)))
        {   E.print_feedback();

        }
    }
    else
        cout<<"\n Invalid choice:";

}
