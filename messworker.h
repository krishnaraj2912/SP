#include <stdlib.h>
#include "leave.h"
#include "timetable.h"
#include "feedback.h"
#pragma once
class messworker:public timetable
{
    int id,i,countdays;
    char name[20];
    char gender;
    float salary;
    leave a[10];
public:
    void messworker_input();
    void menu();
    void salary_update(float value);
    void view_salary();
};
void messworker::salary_update(float value)
{   salary+=value;
    cout<<"\n updated value:"<<salary;

}
void messworker::menu()
{   cout<<"\n Menu 1.view time table 2. view balance 3. apply leave 4. enter feedback 5.inform pay not yet given 6. exit";
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
            a[i].input_leave();
            countdays+=a[i].ret_no_of_days();
            i++;
            salary-=countdays*50;
        }
        else if(ch==4)
        {   feedback A;
            A.feedback_enter(name,'m');
            ofstream  fout("messworker_complain.dat",ios::out|ios::binary|ios::app);
            fout.write((char*)&A,sizeof(A));
            fout.close();

        }
        else if(ch==5)
        {   cout<<"\n DO you want to tell boss that your monthly pay is not yet given:";;
            char cht;
            cin>>cht;
            if(cht=='Y'||cht=='y')
            {   ofstream fout("inform_pay.dat",ios::out|ios::binary|ios::app);
                fout.write((char*)this,sizeof(messworker));
                fout.close();
            }


        }
        else if(ch==6)
        {//exit
            break;
        }
        else
            cout<<"\n invalid choice:";
    }while(ch!=5);
}
void messworker::messworker_input()
{   i=0;
    cout<<"\n enter id :";
    cin>>id;
    cout<<"\n enter name:";
    cin>>name;
    cout<<"\n gender(m/f)?:";
    cin>>gender;
    salary =10000;//basic start
}
void messworker::view_salary()
{
    cout<<"Balance is :"<<salary;
    cout<<"\n Number of leaves taken:"<<i<<endl;
}

