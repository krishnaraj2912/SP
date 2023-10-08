#include <stdlib.h>
#include "feedback.h"
#include "token.h"
#include "leave.h"
#include "visitor.h"
#include "bill.h"
#include "timetable.h"
class professor:public timetable
{
    int id;
    int count_tokken;
    int vc;
    std:string name;
    char gender;
    float balance;
    std::vector<token> p(10);
    bill B;
    visitor v;
public:
    void professor_input();
   //make it as a member function for timetable class void view_timetable();
    void Apply_token();
    void visitor_have();
    void menu();
};
void professor::menu()
{   cout<<"\n Menu 1.view time table 2. apply token 3.apply for visitors 4.view bill 5. enter feedback 6.exit";
    int ch;
    do
    {
        cout<<"\n enter choice:";
        cin>>ch;
        if(ch==1)
        {   view_timetable();

        }
        else if(ch==2)
        {   Apply_token();


        }
        else if(ch==3)
        {   v.menu(balance);

        }
        else if(ch==4)
        {   B.update_balance(balance);
            B.print_bill(name,(p[count_tokken]).ret_token());

        }
        else if(ch==5)
        {   feedback A;
            A.feedback_enter(name,'p');
            ofstream  fout("professor_complain.dat",ios::out|ios::binary|ios::app);
            fout.write((char*)&A,sizeof(A));
            fout.close();
        }
        else if(ch==6)
        {//exit
            break;
        }
        else
            cout<<"\n invalid choice:";
    }while(ch!=5);

}
void professor::professor_input()
{   vc=0;
    count_tokken=0;
    cout<<"\n enter id :";
    cin>>id;
    cout<<"\n enter name:";
    cin>>name;
    cout<<"\n gender(m/f)?:";
    cin>>gender;
    balance =50000;
}
void professor::Apply_token()
{  // p[count_tokken]=new token;
    (p[count_tokken]).apply_token();
    count_tokken++;
    B.calc_bill(p[count_tokken-1].ret_token());
}
