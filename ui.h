#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "professor.h"
#include "messworker.h"
//#include "messsupervisor.h"
#pragma once
class ui
{   int loginid;
    string password;
    string cpassword;
 public:
    student p1;
    professor p2;
    messworker p3;
  //  messsupervisor p4;
    void display(ui E);

};
void ui::display(ui E)
{   cout<<"\n LOGIN SYTEM 1.STUDENT 2.PROFESSOR 3.MESS WORKER  ";
        cout<<"\n Enter your choice : ";
        int ch;
        cin>>ch;
        if(ch==1)
        {   cout<<"\n Menu 1.New id 2.login old id ";
            int ch1;
            cin>>ch1;
            if(ch1==1)
            {   cout<<"\n Enter your id (no) you would like to have : ";
                cin>>E.loginid;
                do{
                    cout<<"\n Enter the password:";
                    cin.ignore();
                    gets(E.password);
                    cout<<"\n Enter the password again for conformation : ";
                    gets(E.cpassword);
                    if(strcmp(E.password,E.cpassword)==0)
                        break;
                }while(true);
                E.p1.student_input();
               // cout<<"\n id:"<<E.password<<","<<E.loginid;
                ofstream fout("student.dat",ios::out|ios::binary|ios::app);
                fout.write((char*)&E,sizeof(E));
                fout.close();
            }
            else if(ch1==2)
            {   cout<<"\n Enter your login id : ";
                int lg;
                string ps;
                cin>>lg;
                cin.ignore();
                cout<<"\n enter your password : ";
                gets(ps);
                ui A;
                int f=0;
                ifstream fin("student.dat",ios::in|ios::binary);

                while(fin.read((char*)&A,sizeof(A)))
                {   //cout<<"hi:"<<A.loginid<<","<<A.password;
                    if(A.loginid==lg &&strcmp(A.password,ps)==0)
                    {   cout<<"\nWelcome back\n";
                        f=1;
                        break;

                    }

                }
                if(f==0)
                    cout<<"\n wrong credentials";
            //using this do all student stuff.
                else
                {   A.p1.menu();
                }
            }
        }
        else if(ch==2)
        {
            cout<<"\n Menu 1.New id 2.login old id ";
            int ch1;
            cin>>ch1;
            if(ch1==1)
            {
                cout<<"\n Enter your id (no) you would like to have : ";
                cin>>E.loginid;
                do
                {
                    cout<<"\n Enter the password : ";
                    cin.ignore();
                    gets(E.password);
                    cout<<"\n Enter the password again for conformation : ";
                    gets(E.cpassword);
                    if(strcmp(E.password,E.cpassword)==0)
                        break;
                }while(true);
                E.p2.professor_input();
                ofstream fout("professor.dat",ios::out|ios::binary|ios::app);
                fout.write((char*)&E,sizeof(E));
            }
            else if(ch1==2)
            {
                cout<<"\n Enter your login id : ";
                int lg;
                char ps[20];
                cin>>lg;
                cout<<"\n enter your password : ";
                cin.ignore();
                gets(ps);
                ui A;
                int f=0;
                ifstream fin("professor.dat",ios::in|ios::binary);
                while(fin.read((char*)&A,sizeof(A)))
                {
                    if(A.loginid==lg &&strcmp(A.password,ps)==0)
                    {
                        cout<<"\nWelcome back\n";
                        f=1;
                        break;
                    }
                }
                if(f==0)
                    cout<<"\n wrong credentials";
                //using this do all student stuff.
                else
                    {
                        A.p2.menu();
                    }
            }
        }
        else if(ch==3)
        {
            cout<<"\n Menu 1.New id 2.login old id ";
            int ch1;
            cin>>ch1;
            if(ch1==1)
            {
                cout<<"\n Enter your id (no) you would like to have : ";
                cin>>E.loginid;
                do
                {
                    cin.ignore();
                    cout<<"\n Enter the password : ";
                    gets(E.password);
                    cout<<"\n Enter the password again for conformation : ";
                    gets(E.cpassword);
                    if(strcmp(E.password,E.cpassword)==0)
                        break;
                }while(1);
                E.p3.messworker_input();
                ofstream fout("messworker.dat",ios::out|ios::binary|ios::app);
                fout.write((char*)&E,sizeof(E));
            }
            else if(ch1==2)
            {
                cout<<"\n Enter your login id : ";
                int lg;
                string ps;
                cin>>lg;
                cin.ignore();
                cout<<"\n enter your password : ";
                gets(ps);
                ui A;
                int f=0;
                ifstream fin("messworker.dat",ios::in|ios::binary);
                while(fin.read((char*)&A,sizeof(A)))
                {
                    if(A.loginid==lg &&strcmp(A.password,ps)==0)
                    {
                        cout<<"\nWelcome back\n";
                        f=1;
                        break;
                    }
                }
                if(f==0)
                    cout<<"\n wrong credentials";
                //using this do all student stuff.
                else
                {
                    A.p3.menu();
                }

            }
            else
                cout<<"\n invalid choice:";

        }
}
