#include <iostream>
#include <string>

#define NDEBUG
#include <cassert>


bool truth()
{
    return false;
}

void changeArray(int array[])
{
    array[0] = 3;
}

void changeString(std::string &string)
{
    string[0] = 'H';
}

int main()
{
    int array[] = {1};
    changeArray(array);

    std::string string = "hello\n";
    changeString(string);

    std::cout << array[0] << std::endl ;
    std::cout << string;

    assert(truth());

    std::cout << "done\n";

    return 0; 
    
}