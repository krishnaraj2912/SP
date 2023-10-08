#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#pragma once
class token
{private:
    static int no_of_tokens;
    std::vector<std::string> applied_tokens(20);
public:
    void apply_token();
    int ret_token();
};
int token::no_of_tokens=0;
int token::ret_token() const
{   return no_of_tokens;
}
void token::apply_token()
{   std::vector<std::string> vfood={"Kadai paneer","chilli gobi","pav bhaji","gobi manchurian","vada pav","lasagne","pasta","veg biryani","aloo makan","aloo tiki"};
    std::vector<std::string> nvfood[12][30]={"Butter chicken","chicken 65","biryani","chicken tikka masala","omellete","kolidhi chicken","fish cury","chicken tikka masala","chicken tikka"};
    cout<<"\n Types of token 1.veg 2.non veg:";
    int ch2;
    cin>>ch2;
    if(ch2==1)
    {   
        srand(time(0));
        int d=rand()%10;
        cout<<"\n Today s token is :" <<vfood[d]<<"\n Do you want to apply(y/n)";
        char ch3;
        cin>>ch3;
        if(ch3=='y'||ch3=='Y')
        {   no_of_tokens++;
            strcpy(applied_tokens[no_of_tokens-1],vfood[d]);
        }
    }
    else if(ch2==2)
    {   
        srand(time(0));
        int d=rand()%10;
        cout<<"\n Today s token is :" <<nvfood[d]<<"\n Do you want to apply(y/n)";
        char ch3;
        cin>>ch3;
        if(ch3=='y'||ch3=='Y')
        {   
            no_of_tokens++;
            strcpy(applied_tokens[no_of_tokens-1],nvfood[d]);
        }
    }
    else
        cout<<"\n invalid choice:";

}
