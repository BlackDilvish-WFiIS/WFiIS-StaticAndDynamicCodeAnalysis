#include<iostream>
#include<cstdlib>

double add(double first, double second)
{
    return first + second;
}

void comparing_diff_arr_pointers_CERT()
{
    int array1[4] = {1, 2, 3, 4};
    int array3[4] = {1, 2, 3, 4};
    int* array2 = array3 + 2;

    if(array2 - array1 <= sizeof(array1)) 
    {
        std::cout<<"Not behind last element of array1\n";
    }
}

signed int* some_integer_violations_CERT()
{
    signed int signedInteger = 4;
    
    /* strange cast */
    unsigned int unsignedInteger = (unsigned int)signedInteger;

    std::cout<<unsignedInteger<<"\n";

    /* Returning not-dynamically created address */
    signed int* wrong_not_malloced_ptr = &signedInteger;

    return wrong_not_malloced_ptr;
}

void expression_violations_rule3_in_CERT()
{
    /* wrong argument number */
    some_integer_violations_CERT(4);

    /* NULL pointer dereferencing */
    int* ptr = NULL;
    std::cout<<*ptr;

    int val = 3;
    ptr = &val;

    /* relying on side effects in operands to sizeof */
    printf("%d", sizeof(ptr++));
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

    // proszę odkomentować przy sprawdzaniu CERT0a
    /*
    comparing_diff_arr_pointers_CERT();
    some_integer_violations_CERT();
    expression_violations_rule3_in_CERT();
    */

    return 0;
}