#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <inttypes.h>
#include <stdlib.h>

//通用类型联合
typedef union _value {
    int8_t    int8;   //整型
    int16_t   int16;
    int32_t   int32;
    uint64_t  int64;
    float     fValue; //浮点型
    double    dValue;
    char     *pStr;   //字符指针
    int8_t   *pInt8;  //整型数组指针
    int16_t  *pInt16;
    int32_t  *pInt32;
    uint64_t *pInt64;
    void     *pVoid;  //无类型指针
} Value;

//通用类型结构体
typedef struct _variant {
    int   type; //标记类型
    Value v;    //存储实际的数据
} Variant;

//动态数组类型
typedef struct _dynamicArray {
    int      arrayLen; //动态数组有效长度
    int      capacity; //动态数组容量
    Variant *arr;      //动态数组数据
} DynamicArray;

//创建通用类型
Variant *     createVariant(void);
//动态数组相关
DynamicArray *createDynamicArray(void);
DynamicArray *createCapacityDynamicArray(int capacity);
DynamicArray *dynamicCopy(DynamicArray *dest, DynamicArray *source);
DynamicArray *dynamicDeepCopy(DynamicArray **dest, DynamicArray *src);
DynamicArray *dynamicInsert(DynamicArray **arr, int index, Variant *value);
DynamicArray *dynamicAppend(DynamicArray **arr, Variant *value);
Variant      *dynamicGet(DynamicArray *arr, int index);

#endif
