#include<iostream>
#include<cstdlib>

double add(double first, double second)
{
    return first + second;
}

int main()
{
    char* definitely_const_string = "This shall be string literal.";
    
    //std::cout<<definitely_const_string;

    // int* ptr = (int* )malloc(sizeof(int) * 12);

    int i = 0;

    for(i = 0; i < 10; ++i);

    std::cout<<"Incremented value: "<<i<<"\n";

    //double result = add(4, 2);
    //std::cout<<result;

    // free(ptr);

    return 0;
}
