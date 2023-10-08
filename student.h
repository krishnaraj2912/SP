#include <stdlib.h>
#include "token.h"
#include "feedback.h"
#include "leave.h"
#include "visitor.h"
#include "bill.h"
#include "timetable.h"
class student:public timetable
{   int rollno,count_tokken,vc;
    char name[20];
    char gender;
    float balance;
    token p[10];
    bill B;
    visitor P;
public:
    void student_input();
   //make it as a member function for timetable class void view_timetable();
    void Apply_token();
   // void visitor_have();
    void menu();
};
void student::menu()
{
    int ch;
    do
    {   cout<<"\n Menu 1.view time table 2. apply token 3.apply for visitors 4.view bill 5.enter feedback 6. exit";
        cout<<"\n enter choice:";
        cin>>ch;
        if(ch==1)
        {   view_timetable();

        }
        else if(ch==2)
        {   Apply_token();

        }
        else if(ch==3)
        {P.menu(balance);
        }
        else if(ch==4)
        {   B.update_balance(balance);
            B.print_bill(name,(p[count_tokken]).ret_token());

        }
        else if(ch==5)
        {   feedback A;
            A.feedback_enter(name,'s');
            ofstream  fout("student_complain.dat",ios::out|ios::binary|ios::app);
            fout.write((char*)&A,sizeof(A));
            fout.close();

        }
        else if(ch==6)
        {
            break;
        }//exit
        else
            cout<<"\n invalid choice:";
    }while(ch!=5);

}
void student::student_input()
{   cout<<"\n enter roll no:";
    cin>>rollno;
    cout<<"\n enter name:";
    cin>>name;
    cout<<"\n gender:(m/f)?:";
    cin>>gender;
    balance =50000;
    count_tokken=0;
    vc=0;//visitor count
}
void student::Apply_token()
{
    (p[count_tokken]).apply_token();
    count_tokken++;
    B.calc_bill(p[count_tokken-1].ret_token());
}
