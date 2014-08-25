#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <inttypes.h>
#include <stdlib.h>

typedef union _value {
    uint   int8;
    uint  int16;
    uint  int32;
    uint64_t  int64;
    float     fValue;
    double    dValue;
    char *    pStr;
    uint * pInt8;
    uint *pInt16;
    uint *pInt32;
    uint64_t *pInt64;
    void *    pVoid;
} Value;

typedef struct _variant {
    uint type;
    Value v;
} Variant;

typedef struct _dynamicArray {
    uint arrayLen;
    uint capacity;
    Variant *arr;
} DynamicArray;

Variant *     createVariant(void);
DynamicArray *createDynamicArray(void);
DynamicArray *createCapacityDynamicArray(uint capacity);
DynamicArray *dynamicCopy(DynamicArray *dest, DynamicArray *source);
DynamicArray *dynamicInsert(DynamicArray **arr, uint index, Variant *value);
DynamicArray *dynamicAppend(DynamicArray **arr, Variant *value);
Variant *     dynamicGet(DynamicArray *arr, uint index);

#endif
