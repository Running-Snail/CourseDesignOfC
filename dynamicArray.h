#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <inttypes.h>
#include <stdlib.h>

typedef union _value {
    uint8_t   int8;
    uint16_t  int16;
    uint32_t  int32;
    uint64_t  int64;
    float     fValue;
    double    dValue;
    char *    pStr;
    uint8_t * pInt8;
    uint16_t *pInt16;
    uint32_t *pInt32;
    uint64_t *pInt64;
    void *    pVoid;
} Value;

typedef struct _variant {
    uint8_t type;
    Value v;
} Variant;

typedef struct _dynamicArray {
    uint32_t arrayLen;
    uint32_t capacity;
    Variant *arr;
} DynamicArray;

Variant *     createVariant(void);
DynamicArray *createDynamicArray(void);
DynamicArray *createCapacityDynamicArray(uint32_t capacity);
DynamicArray *dynamicCopy(DynamicArray *dest, DynamicArray *source);
DynamicArray *dynamicInsert(DynamicArray **arr, uint32_t index, Variant *value);
Variant *     dynamicGet(DynamicArray *arr, uint32_t index);

#endif
