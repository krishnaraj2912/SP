#include <iostream>
#pragma once
class leave
{   
    int no_of_days;
    std:string purpose;
public:
    void input_leave()
    {   
        cout<<"\n Enter the number of days of leave : ";
        cin>>no_of_days;
        cin.ignore();
        cout<<"\n enter purpose of leave request : ";
        gets(purpose);

    }
    int ret_no_of_days()
    {
        return no_of_days;
    }

};
