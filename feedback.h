#include <fstream>
#include <iostream>
#include <string.h>
#pragma once
class feedback
{   char name[20],type;//student or teacher or mess worker
    char feedback_words[100];
public:
    void feedback_enter(char n[20],char t)
    {   strcpy(name,n);
        type=t;
        cout<<"\n Enter your complaints / regards towards the  mess ";
        cin.ignore();
        gets(feedback_words);
    }
    void print_feedback()
    {   cout<<"\n The feedback is from : "<<name;
        cout<<"\n The feedback is : ";
        cout<<feedback_words;
    }
};
