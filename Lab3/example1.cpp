#include <iostream>
    using namespace std;

    int hello(int x);
    int hello (int x){
        return x;
    }
    int main()
    {
        int result = hello(1);
        cout << result;
        return 0;
    }