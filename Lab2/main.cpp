#include <iostream>
using namespace std;
int main()
{
    int i = 69;
    int number;
    number = 72;
    i = 69 + 72;
    int array[3];
    int *iPointer = &i;
    number = *iPointer;
    *iPointer = 15;
    iPointer = /*&*/array[0];
    iPointer += 2;
    array[0] = 5;
    *iPointer = 6;

    return 0;
}
