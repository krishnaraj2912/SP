#include<string.h>
#include <iostream>
#pragma once
class timetable
{private:
    std::vector<std::string> b(7);
    std::vector<std::string> l(7);
    std::vector<std::string> s(7);
    std::vector<std::string> d(7);
public:
    void create_timetable(int f=0)
    {   ofstream fout;
        fout.open("timetable.txt");
        std::vector<std::string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        for(int i=0;i<7;i++)
        {
            cout<<"Enter the Breakfast for "<<days[i]<<" : ";
            cin.ignore();
            gets(b[i]);
            fout<<b[i]<<endl;
            cout<<"Enter the Lunch for "<<days[i]<<" : ";
            gets(l[i]);
            fout<<l[i]<<endl;
            cout<<"Enter the Snacks for "<<days[i]<<" : ";
            gets(s[i]);
            fout<<s[i]<<endl;
            cout<<"Enter the Dinner for "<<days[i]<<" : ";
            gets(d[i]);
            fout<<d[i]<<endl;

        }
        fout.close();
    }
    void view_timetable()
    {   std:string e;
        std:string f;
        std:string g;
        std:string h;
        std::vector<std::string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        ifstream fin("timetable.txt");
        cout<<"\t\tBreakfast \t"<<"Lunch\t\t"<<"Snacks\t\t"<<"Dinner\n";
        for(int i=0;i<7;i++)
        {   getline(fin,e);
            strcpy(b[i],e.c_str());
            getline(fin,f);
            strcpy(l[i],f.c_str());
            getline(fin,g);
            strcpy(s[i],g.c_str());
            getline(fin,h);
            strcpy(d[i],h.c_str());
            cout<<days[i];
            if(strlen(days[i])<8)
            {
                if(strlen(l[i])<8)
                {
                    cout<<"\t\t"<<e<<"\t\t"<<f<<"\t\t"<<g<<"\t\t"<<h<<"\n";
                }
                else
                {
                    cout<<"\t\t"<<e<<"\t\t"<<f<<"\t"<<g<<"\t\t"<<h<<"\n";
                }
            }
            else
            {
                if(strlen(l[i])<8)
                {
                    cout<<"\t"<<e<<"\t\t"<<f<<"\t\t"<<g<<"\t\t"<<h<<"\n";
                }
                else
                {
                    cout<<"\t"<<e<<"\t\t"<<f<<"\t"<<g<<"\t\t"<<h<<"\n";
                }
            }
        }
        fin.close();
    }
    void edit_timetable(int f=0)//flag is set one only for mess supervisor
    {
        if(f==1)
        {
            std::vector<std::string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
            std::string day;
            view_timetable();
            cout<<"Which day's timetable do you want to edit?(first letter caps) ";
            cin>>day;
            fstream fout("timetable.txt");
            for(int i=0;i<7;i++)
            {
                if(strcmp(days[i],day)==0)
                {
                    char time;
                    cout<<"Do you want to edit breakfast(b)/lunch(l)/snacks(s)/dinner(d)? ";
                    cin>>time;
                    cin.ignore();
                    if(time=='b')
                    {
                        cout<<"Enter the dish to modify  : ";
                        gets(b[i]);
                    }
                    else if(time=='l')
                    {
                        cout<<"Enter the dish to modify  : ";
                        gets(l[i]);
                    }
                    else if(time=='s')
                    {
                        cout<<"Enter the dish to modify  : ";
                        gets(s[i]);
                    }
                    else if(time=='d')
                    {
                        cout<<"Enter the dish to modify  : ";
                        gets(d[i]);
                    }
                }
                fout<<b[i]<<endl<<l[i]<<endl<<s[i]<<endl<<d[i]<<endl;
            }
            fout.close();
        }
        else
        {
            cout<<"\nSorry, you are not eligible to edit the timetable!!!";
        }
    }
};
