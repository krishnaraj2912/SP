#include <iostream>
#pragma once

class bill
{
    float total_bill;
    float cash;

public:
    bill()(int cash = 50000):cash(cash){
    }
    void update_balance(float balance)
    {   
        cash=balance;
    }
    void calc_bill(int no_of_tokens)
    {
        total_bill = 3000+(50*no_of_tokens);
        cash -= total_bill;
        //(3000 basic amount)
    }
    void print_bill const(std::string name, int no_of_tokens)
    {   
        cout<<"\n Name:"<<name<<"\n No of tokens registered :"<<no_of_tokens;
        cout<<"\n The bill is :"<<total_bill;
        cout<<"\n Remaining balance:"<<cash;
    }
};
