#include "dynamicArray.h"

Variant *createVariant(void)
{
    Variant *v = (Variant *)malloc(sizeof(Variant));
    return v;
}

DynamicArray *createDynamicArray()
{
    DynamicArray *d;
    d = (DynamicArray *)malloc(sizeof(DynamicArray));
    d->arrayLen = 0;
    d->capacity = 1;
    d->arr = (Variant *)malloc(sizeof(Variant));
    return d;
}

DynamicArray *createCapacityDynamicArray(uint capacity)
{
    DynamicArray *d;
    d = (DynamicArray *)malloc(sizeof(DynamicArray));
    d->arrayLen = 0;
    d->capacity = capacity;
    d->arr = (Variant *)malloc(sizeof(Variant)*capacity);
    return d;
}

DynamicArray *dynamicCopy(DynamicArray *dest, DynamicArray *source)
{
    int i;
    if (!dest || !source)
        return NULL;

    for (i=0; i<source->arrayLen; i++) {
        *((dest->arr)+i) = *((source->arr)+i);
    }

    dest->arrayLen = source->arrayLen;

    return dest;
}

DynamicArray *dynamicDeepCopy(DynamicArray **dest, DynamicArray *src)
{
    int i;

    if (!src || !dest)
        return NULL;

    if (!(*dest))
        *dest = createCapacityDynamicArray(src->capacity);

    for (i=0; i<src->arrayLen; i++) {
        dynamicInsert(dest, i, dynamicGet(src, i));
    }

    return *dest;
}

DynamicArray *dynamicInsert(DynamicArray **arr, uint index, Variant *value)
{
    DynamicArray *newArr;
    if (!arr)
        return NULL;

    //printf("insert %d\n", index);

    if (index >= (*arr)->arrayLen) {
        newArr = createCapacityDynamicArray(index*2);
        dynamicCopy(newArr, *arr);
        *arr = newArr;
        (*arr)->arrayLen = index+1;
    }

    *(((*arr)->arr)+index) = *value;

    return *arr;
}

DynamicArray *dynamicAppend(DynamicArray **arr, Variant *value)
{
    if (!arr)
        return NULL;
    return dynamicInsert(arr, (*arr)->arrayLen, value);
}

Variant *dynamicGet(DynamicArray *arr, uint index)
{
    if (!arr || index >= arr->arrayLen)
        return NULL;

    return arr->arr+index;
}
