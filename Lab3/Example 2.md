В случае, если мы объявим функцию и вызовем ее в функции main файле main.cpp:
main.cpp
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
И также в файле f.cpp объявим функцию int hello(int x):


```cpp
#include <iostream>
using namespace std;
int hello(int x);
```
А затем скомпилируем
```
g++ main.cpp f.cpp
```
Мы получим ошибку
```
undefined reference to `hello(int)'
```
Так как как функция hello не определена.
При добавлении определения в функции hello в файл f.cpp, команда 
```
g++ main.cpp f.cpp
```
выполняется, и создается файл a.exe

Если скомпилировать только файл main.cpp, мы получим ошибку:
```cpp
undefined reference to `hello(int)'
```
так как в файле main.cpp остутствует определение функции hello.



Далее добавляем к определению функции модификатор static.
f.cpp:
```cpp
#include <iostream>
using namespace std;
static int hello(int x){
    return x;
}
```
При компиляции двух файлов мы получаем ошибку, так как из-за модификатора static функция hello становится видимой только в файле f.cpp.

Далее перекомпилируем определение функции в main.cpp:
```cpp
#include <iostream>
using namespace std;

static int hello(int x)
{
    return x;
}
int main()
{
    int result = hello(1);
    cout << result;
    return 0;
}
```
Компиляция проходит успешно, так как теперь определение функции hello находится в main.cpp и является видимым для компилятора.