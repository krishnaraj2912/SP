#include <fstream>
#include <iostream>
#include <string.h>
#pragma once
class feedback
{   
    char type;
    std:string name;
    std:string feedback_words[100];
public:
    void feedback_enter(std:string n,char t)
    {   
        strcpy(name,n);
        type=t;
        cout<<"\n Enter your complaints / regards towards the  mess ";
        cin.ignore();
        gets(feedback_words);
    }
    void print_feedback()
    {   
        cout<<"\n The feedback is from : "<<name;
        cout<<"\n The feedback is : ";
        cout<<feedback_words;
    }
};
