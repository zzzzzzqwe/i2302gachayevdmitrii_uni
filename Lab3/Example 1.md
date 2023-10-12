В случае, если мы объявим функцию и вызовем ее в функции main:
```cpp
#include <iostream>
using namespace std;

int hello(int x);
int main()
{
    int result = hello(1);
    cout << result;
    return 0;
}
```
Мы получим ошибку: 
```cpp
undefined reference to `hello(int)'
```
Что означает что компилятор не может найти определение функции "hello", несмотря на то что она объявлена.

Если мы введем определение функции "hello", компиляция пройдет успешно:
```cpp
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
```
По сути строка "int hello(int x)" в данном коде избыточна, но я решил ее оставить для более "явного" объявления функции.


