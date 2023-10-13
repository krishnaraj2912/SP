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
    std::vector<std::string> nvfood={"Butter chicken","chicken 65","biryani","chicken tikka masala","omellete","kolidhi chicken","fish cury","chicken tikka masala","chicken tikka"};
    cout<<"\n Types of token 1.veg 2.non veg:";
    int ch2;
    cin>>ch2;
    if(ch2==1)
    {   
        auto current_time = std::chrono::system_clock::now();
        auto time_since_epoch = current_time.time_since_epoch();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time_since_epoch);

        auto seed = static_cast<unsigned int>(seconds.count());
    
        std::mt19937 rng(seed);
        std::uniform_int_distribution distribution(1, 100);
        int d = distribution(rng)%10;
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
        auto current_time = std::chrono::system_clock::now();
        auto time_since_epoch = current_time.time_since_epoch();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time_since_epoch);

        auto seed = static_cast<unsigned int>(seconds.count());
        
        std::mt19937 rng(seed);
        std::uniform_int_distribution distribution(1, 100);
        int d = distribution(rng)%10;
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
