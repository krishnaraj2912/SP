#include <iostream>
#pragma once
class visitor
{   int no_of_visitors;
    int no_of_days;
    float rate;
    std::vector<std::string> name_visitors;
    std::string purpose_visit;
    char hotel_style;
    char food;
public:
    visitor()(int no_of_visitors=3):no_of_visitors(no_of_visitors){
    }
    void visitor_input();
    float rate_to_be_paid();
    void deduct(float &balance);
    void menu(float &balance);
    void done();
};
void visitor::done()
{   no_of_days=0;
    no_of_visitors=0;
    for(int i=0;i<no_of_visitors;i++)
        strcpy(name_visitors[i],"");
    strcpy(purpose_visit,"");
    hotel_style=0;
    food=0;
}
void visitor::deduct(float &balance)
{   balance-=rate_to_be_paid();
}
void visitor::menu(float &balance)
{   cout<<"\n Menu 1.apply for visitors  2. bill to be payed:";
    int ch;
    cin>>ch;
    if(ch==1)
        visitor_input();
    else if(ch==2)
    {   if(no_of_visitors==0)
            cout<<"\n you have no visitors:";
        else
        {   cout<<"\n the bill to be payed is Rs: "<<rate_to_be_paid();
            cout<<"\n Would you like to pay it now:(y/n)";
            char ch1;
            cin>>ch1;
            if(ch1=='y'||ch1=='Y')
            {   balance-=rate_to_be_paid();
                done();
            }

        }
    }
}
void visitor::visitor_input()
{   do{
        cout<<"\n Enter the number of visitors (<=3)";
        cin>>no_of_visitors;
     }while(no_of_visitors>3||no_of_visitors<1);
     cout<<"\n Enter the no of days of visit:";
    cin>>no_of_days;
    cout<<"\n Enter the purpose of the visit:";
    cin>>purpose_visit;
    cout<<"\n Types of hotels available D(duelex),S(super duelex),N(normal),A(normal with Ac),E(elite)";
    cin>>hotel_style;
    cout<<"\n Enter the type of food preffered V(veg),N(non veg)";
    cin>>food;


}

float visitor::rate_to_be_paid()
{   if(food=='V'||food=='v')
        rate=500*no_of_days*no_of_visitors;
    else
        rate=300*no_of_days*no_of_visitors;
    if(hotel_style=='D'||hotel_style=='d')
        rate+=no_of_days*2000;
    else if(hotel_style=='S'||hotel_style=='s')
        rate+=no_of_days*3000;
    else if(hotel_style=='A'||hotel_style=='a')
        rate+=no_of_days*1000;

    else if(hotel_style=='e'||hotel_style=='E')
        rate+=no_of_days*4000;
    else
        rate+=no_of_days*500;

    return rate;
}

