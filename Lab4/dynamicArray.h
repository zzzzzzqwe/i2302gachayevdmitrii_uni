
#pragma once

#include <span>

struct DynamicArray {
    int* data;
    size_t length;
    size_t capacity;
};

DynamicArray createDynamicArrayWithCapacity(size_t capacity);
DynamicArray createDynamicArray();
void addElementToArray(DynamicArray* arr, int element);
int getElementAtIndex(const DynamicArray* arr, size_t index);
std::span<int> getCurrentSpan(const DynamicArray* arr);
void freeDynamicArray(DynamicArray* arr);
