#include <iostream>
#include "ui.h"
#include "messsupervisor.h"
#include <fstream>
#pragma once
using namespace std;

int main()
{   cout<<"\n Login as 1)admin 2)others:";
    int chl;
    cin>>chl;
    if(chl==1)
    {   messsupervisor p4;
        cout<<"\n Enter admin id:";
        char id[30],PS[30];
        cin.ignore();
        gets(id);
        cout<<"\n Enter the password:";
        gets(PS);
        if(strcmp(id,"123")==0&&strcmp(PS,"abcd")==0)
        {   cout<<"\n Welcome admin:";
            p4.menu();
        }
        else
            cout<<"\n wrong credentials:";
    }
    else if(chl==2)
    {
        ui A;
        char ch;
        do
        {   A.display(A);
            cout<<"\n Do you want to exit(y/n)";
            cin>>ch;
        }while(ch!='y'&&ch!='Y');
    }
    else
        cout<<"\n invalid:";

    return 0;
}
