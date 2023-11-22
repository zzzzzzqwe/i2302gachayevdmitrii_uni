#include <stdlib.h>
#include <iostream>

// This program was designed to show you how the stack works.
// You shouldn't dereference pointers which are no longer in scope.
// Never do that, it's undefined behavior (anything can happen).

// Note that this program may break if you use optimizations.
// Also, I have only tried it on Zig C++ (Clang) on Windows.

// Also note, that this produces a warning on Zig C++ (Clang), which is expected.

// See the excel file for a visualization of the stack.

// Объявление функции stackMemory1, которая возвращает указатель на int значение, затем создаем локальную переменную a типа int и присваиваем ей значение 1.
// Возвращаем адрес переменной a.
int* stackMemory1() 
{
    int a = 1;
    return &a;
}
// Объявление функции stackMemory2, которая возвращает указатель на int значение, затем создаем локальную переменную b типа int и присваиваем ей значение 2.
// Возвращем адрес переменной b.
int* stackMemory2()
{
    int b = 2;
    return &b;
}

int main()
{
    // Объявляем переменную b как указатель на int, присваиваем ей адрес возвращаемого значения функции stackMemory1() (1)
    int* b = stackMemory1();
    // Присваиваем значение указателя b переменной a1 (разыменовываем указатель b)
    int a1 = *b; // 1
    // Объявляем переменную c как указатель на int, присваиваем ей адрес возвращаемого значения функции stackMemory1() (2)
    int* c = stackMemory2();
    // Присваиваем значение указателя c переменной a2
    int a2 = *c; // 2
    // Присваиваем значение указателя b переменной a2
    int a3 = *b; // 2
    // Выводим значения a1 > a2 > a3
    // Получаем
    // 1
    // 2
    // 2
    std::cout << a1 << std::endl; // prints 1
    std::cout << a2 << std::endl; // prints 2
    std::cout << a3 << std::endl; // prints 2
    // Сравниваем байтовое значение указателей b и c, получаем ноль, так как их байтовые значения равны, либо потому что они указывают на переменные хранящие одинаковые значения, либо потому что они оба типа int.
    std::cout << ((std::byte*) b - (std::byte*) c) << std::endl; // prints 0, pointers are equal

    return 0;
}   