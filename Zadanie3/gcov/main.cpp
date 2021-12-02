#include<iostream>
#include<string>


std::string getParity(int value)
{
    if (value % 2)
    {
        return "even";
    }
    else
    {
        return "odd";
    }
}

int convertPointer(int* pointer)
{
    if (pointer == nullptr)
    {
        return 0;
    }

    switch(*pointer)
    {
        case 0:
            return 10;
            break;
        case 20:
            return 50;
            break;
        default:
            return 0;
    }
}

bool processValue(float value)
{
    if (value > 60.f)
    {
        std::cout << "ABNORMAL: value > 60";
    }

    if (value < 0.01f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void emptyFunction(bool flag)
{
    if(flag)
    {
        std::cout << "flag is set";
    }
}

int main()
{
    int testValue = 20;
    std::cout << convertPointer(&testValue);
    std::cout << getParity(testValue);

    return 0;
}