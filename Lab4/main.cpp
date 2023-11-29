#include "dynamicArray.h"
#include <iostream>
#include <cassert>
#include <span>

void test1() {
    DynamicArray arr = createDynamicArrayWithCapacity(10);
    assert(arr.capacity == 10);
}

void test2() {
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0);
    addElementToArray(&arr, 5);
    assert(arr.length == 1);
}

void test3() {
    DynamicArray arr = createDynamicArrayWithCapacity(1);
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1);
    addElementToArray(&arr, 10);
    assert(arr.capacity == 2);
    addElementToArray(&arr, 20);
    assert(arr.capacity == 4);
}

void test4() {
    DynamicArray arr = createDynamicArray();
    addElementToArray(&arr, 5);
    int el = getElementAtIndex(&arr, 0);
    assert(el == 5);
}

void test5() {
    DynamicArray arr{};
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 6);
    addElementToArray(&arr, 7);

    std::span<int> span = getCurrentSpan(&arr);

    assert(span.size() == 3);
    assert(span[0] == 5);
    assert(span[1] == 6);
    assert(span[2] == 7);
}

// 7. Кастомный простенький тест, проверяющий, что созданный массив с дефолтным capacity имеет нулевую длину и соответствующую capacity:
void test6() {
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0);
    assert(arr.capacity == 4);
}

// тест проверяющий что случай с 0 capacity обрабатывается правильно
void test7() {
    DynamicArray arr = createDynamicArrayWithCapacity(0);
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1);
    assert(arr.length == 1);
    assert(arr.data[0] == 5);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();


    return 0;
}

