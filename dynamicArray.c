/**
 * @version 1.0.0
 * @author  冀子豪
 */
#include "dynamicArray.h"

/**
 * 创建通用类型
 * @return 返回创建的通用类型
 */
Variant *createVariant(void)
{
    Variant *v = (Variant *)malloc(sizeof(Variant));
    return v;
}

/**
 * 创建动态数组
 * @return 创建的动态数组
 */
DynamicArray *createDynamicArray()
{
    DynamicArray *d;
    d = (DynamicArray *)malloc(sizeof(DynamicArray));
    //初始化状态
    d->arrayLen = 0;
    //初始化容量为1
    d->capacity = 1;
    d->arr = (Variant *)malloc(sizeof(Variant));
    return d;
}

/**
 * 创建容量为capacity的动态数组
 * @param  capacity 容量
 * @return          创建的数组
 */
DynamicArray *createCapacityDynamicArray(int capacity)
{
    DynamicArray *d;
    d = (DynamicArray *)malloc(sizeof(DynamicArray));
    d->arrayLen = 0;
    //设置数组容量
    d->capacity = capacity;
    //分配指定大小的数组
    d->arr = (Variant *)malloc(sizeof(Variant)*capacity);
    return d;
}

/**
 * 复制动态数组
 * @param  dest   复制后的数组
 * @param  source 复制的源数组
 * @return        复制后的数组
 */
DynamicArray *dynamicCopy(DynamicArray *dest, DynamicArray *source)
{
    int i;
    if (!dest || !source)
        return NULL;

    //简单复制值
    for (i=0; i<source->arrayLen; i++) {
        *((dest->arr)+i) = *((source->arr)+i);
    }

    //复制长度
    dest->arrayLen = source->arrayLen;

    return dest;
}

/**
 * 深度复制,复制的同时分配空间
 * @param  dest 复制后的数组
 * @param  src  复制的源数组
 * @return      复制后的数组
 */
DynamicArray *dynamicDeepCopy(DynamicArray **dest, DynamicArray *src)
{
    int i;

    if (!src || !dest)
        return NULL;

    //分配数组空间
    if (!(*dest))
        *dest = createCapacityDynamicArray(src->capacity);

    //插入元素
    for (i=0; i<src->arrayLen; i++) {
        dynamicInsert(dest, i, dynamicGet(src, i));
    }

    return *dest;
}

/**
 * 向动态数组中插入元素
 * @param  arr   要插入元素的数组
 * @param  index 要插入的下标位置
 * @param  value 要插入的元素
 * @return       插入元素后的数组
 */
DynamicArray *dynamicInsert(DynamicArray **arr, int index, Variant *value)
{
    DynamicArray *newArr;
    if (!arr)
        return NULL;

    //插入的下标超出长度范围了
    if (index >= (*arr)->capacity) {
        //分配两倍空间的数组
        newArr = createCapacityDynamicArray(index*2);
        dynamicCopy(newArr, *arr);
        *arr = newArr;
    }

    *(((*arr)->arr)+index) = *value;
    //不要忘记了更新数组长度
    (*arr)->arrayLen = index+1;

    return *arr;
}

/**
 * 向动态数组尾部加入内容
 * @param  arr   要操作的动态数组
 * @param  value 要追加的值
 * @return       返回追加值后的动态数组指针
 */
DynamicArray *dynamicAppend(DynamicArray **arr, Variant *value)
{
    if (!arr)
        return NULL;
    return dynamicInsert(arr, (*arr)->arrayLen, value);
}

/**
 * 获取动态数组中的内容
 * @param  arr   要操作的数组
 * @param  index 要获取值的下标值
 * @return       返回获取的值
 */
Variant *dynamicGet(DynamicArray *arr, int index)
{
    if (!arr || index >= arr->arrayLen)
        return NULL;

    return arr->arr+index;
}
