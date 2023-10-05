#include <stdlib.h>
#include <iostream>
#include <cstring>

// Создаем структуру TwoInts, содержащую переменные а и b типа int

struct TwoInts
{
    int a;
    int b;
};

// Создаем структуру StructWithArray, содержащую массив arr из 4 элементов,
// и указатель someNumber

struct StructWithArray
{
    int arr[4];
    int *someNumber;
};

int main()
{
    // Создаем экземпляр структуры TwoInts под названием i2, указываем
    // что значения a и b по умолчанию равны 0, затем меняем их значения
    // в экземпляре структуры на 5 и 7

    TwoInts i2 = {};
    i2.a = 5;
    i2.b = 7;

    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;

    // Создаем экземпляры структуры StructWithArray s и s1,
    // в них устанавливаем значения первого элемента массива arr
    // на 10 и 15 соответственно

    StructWithArray s = {};
    s.arr[0] = 10;

    StructWithArray s1 = {};
    s1.arr[0] = 15;

    // Создаем указатель sPointer на переменную s
    // Меняем значение arr[0] на 20 с помощью указателя
    // в той структуре, на которую указывает указатель (s)

    StructWithArray *sPointer = &s;
    sPointer->arr[0] = 20;

    // Выводим значение arr[0] из экземпляра s, меняем его на 25
    // Выводим значение arr[0] из экземпляра s, меняем его на 30 с помощью указателя
    // Выводим его с новым значением

    std::cout << s.arr[0] << std::endl;
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl;
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl;

    // Переключаем указатель на экземпляр s1
    // С помощью указателя меняем значение arr[0] в экземпляре s1 на 35
    // Выводим первый элемент массива из экземпляров s и s1

    sPointer = &s1;
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl;
    std::cout << s1.arr[0] << std::endl;

    // Создаем массив structArray состоящий из типа StructWithArray

    StructWithArray structArray[2] = {};

    // Меняем значение arr[3] в структуре structArray[0] на 77

    structArray[0].arr[3] = 77;

    //  Переключаем указатель someNumber в структуре structArray[1] на arr[3] структуры structArray[0]

    structArray[1].someNumber = &structArray[0].arr[3];
    
    // Переключаем указатель sPointer на структуру s
    // Создаем указатель pointer, который указывает на arr[3] структуры, на которую указывает sPointer(s),
    // меняем его значение на 72, выводим его с помощью указателя pointer   

    sPointer = &s;
    int *pointer = &sPointer->arr[3];
    s.arr[3] = 72;
    std::cout << *pointer;

    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));
    return 0;
}