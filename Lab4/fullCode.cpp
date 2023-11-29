#include <iostream>
#include <cassert>
#include <span>

struct DynamicArray {
    int* data;
    size_t length;
    size_t capacity;
};

// 1.1 Создайте factory-функцию, которая возвращает массив изначальной максимальной длины, заданной параметром capacity.
DynamicArray createDynamicArrayWithCapacity(size_t capacity) {
    DynamicArray arr;
    arr.data = new int[capacity];
    arr.length = 0;
    arr.capacity = capacity;
    return arr;
}

// 1.2 Создайте factory-функцию, которая выставляет какой-нибудь дефолтный capacity (например 4).
DynamicArray createDynamicArray() {
    return createDynamicArrayWithCapacity(4);
}

// 3. При добавлении элементов в массив, удваивайте длину, если массив полный.
void addElementToArray(DynamicArray* arr, int element) {
    if (arr->length == arr->capacity) {
        // проверка на нулевое capacity
        size_t newCapacity = (arr->capacity == 0) ? 1 : arr->capacity * 2;
        int* newData = new int[newCapacity];
        std::copy(arr->data, arr->data + arr->length, newData);
        delete[] arr->data;
        arr->data = newData;
        arr->capacity = newCapacity;
    }

    arr->data[arr->length++] = element;
}

// 4. Создайте функцию для доступа к элементам массива по индексу. Выполняйте проверку длины в этой функции, используя assert.
int getElementAtIndex(const DynamicArray* arr, size_t index) {
    assert(index < arr->length);
    return arr->data[index];
}

// 5. Создайте функцию, которая возвращает текущий кусок массива как std::span.
std::span<int> getCurrentSpan(const DynamicArray* arr) {
    return {arr->data, arr->length};
}

// 6. Создайте функцию, которая очищает динамическую память, выделенную функциями массива. Вызывайте эту функцию когда память массива больше не нужна
void freeDynamicArray(DynamicArray* arr) {
    delete[] arr->data;
    arr->length = 0;
    arr->capacity = 0;
}


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
