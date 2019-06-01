//
// Created by llb on 2019/6/1.
//
#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H
#endif //DATA_STRUCTURE_LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define LIST_SIZE 100//列表的初始化长度
#define LIST_INCREMENT 10



/**日志级别**/
enum LOGLEVE{
    DEBUG=1,INFO
};

static enum LOGLEVE current_logleve=DEBUG;//0:打印全部日志,1:打印部分日志

typedef int Datatype;

//基于数组实现的列表(顺序存储结构)
typedef struct {
    Datatype *data;
    int length;
    int size;
} ArrayList;

/**
 * 初始化列表
 * @param L
 */
int initList(ArrayList *L) {
    printf("************************%s==>START**********************************\n", "initList");
    L->data = (Datatype *) malloc(sizeof(Datatype) * LIST_SIZE);
    if (L->data == NULL) {
        return ERROR;
    }
    L->length = 0;
    L->size = LIST_SIZE;
    printf("initList ArrayList succeed .length:%d , size:%d , address:%p \n", L->length, L->size, &L);
    printf("************************%s==>END**********************************\n\n\n\n", "initList");
    return OK;
}

/**
 * 销毁列表
 * @param L
 * @return
 */
int destroyList(ArrayList *L) {
    printf("************************%s==>START**********************************\n", "destroyList");
    while (!L->data) {
        free(L->data);
    }
    L->length = 0;
    L->size = 0;
    printf("destroyList succeed .length:%d , size:%d , address:%p \n", L->length, L->size, &L);
    printf("************************%s==>END**********************************\n\n\n\n", "destroyList");
    return OK;
}

/**
 * 列表插入元素
 * @param L
 * @param i
 * @param data
 * @return
 */
int listInsert(ArrayList *L, int i, Datatype data) {
    printf("************************%s==>START**********************************\n", "listInsert");
    if (i < 0 || i > (L->size - 1)) {
        printf("listInsert error i(%d),it must be 0~%d\n", i, L->size);
        return OVERFLOW;
    }
    if (i <= (L->length-1)) {
        L->data[i] = data;
    } else {//当i大于当前列表长度时将元素插入到列表最后
        i = L->length;
        L->data[i] = data;
        L->length++;
    }
    printf("listInsert succeed .length:%d , size:%d , address:%p \n", L->length, L->size, &L);
    for (int j = 0; j < L->length; ++j) {
        printf("\tdata[%d]==> value:%d , address:%p\n", j, L->data[j], &L->data[j]);
    }
    printf("************************%s==>END**********************************\n\n\n\n", "listInsert");
    return OK;
}

/**
 * 删除列表元素
 * @param L
 * @param i
 * @param data
 * @return
 */
int listDelete(ArrayList *L,int i,Datatype *data){

    printf("************************%s==>START**********************************\n", "listDelete");
    if (i < 0 || i > (L->size - 1)) {
        printf("listDelete error i(%d),it must be 0~%d\n", i, L->size);
        return OVERFLOW;
    }
    if(i>=L->length){
        printf("listDelete error i(%d),length(%d)out of menmery\n", i, L->length);
        return OVERFLOW;
    }
    *data = L->data[i];
    for (int k = i; k < L->length-1; ++k) {
        L->data[k]=data[k+1];
    }
    L->length--;
    printf("listDelete succeed .length:%d , size:%d , address:%p \n", L->length, L->size, &L);
    for (int j = 0; j < L->length; ++j) {
        printf("\tdata[%d]==> value:%d , address:%p\n", j, L->data[j], &L->data[j]);
    }
    printf("************************%s==>END**********************************\n\n\n\n", "listDelete");
return OK;
}

/**
 * 获取列表中的元素
 * @param L
 * @param i
 * @param data
 * @return
 */
int getElem(ArrayList *L,int i,Datatype *data){
    printf("************************%s==>START**********************************\n", "getElem");
    if (i < 0 || i > (L->size - 1)) {
        printf("listDelete error i(%d),it must be 0~%d\n", i, L->size);
        return OVERFLOW;
    }
    if(i>=L->length){
        printf("listDelete error i(%d),length(%d)out of menmery\n", i, L->length);
        return OVERFLOW;
    }
    *data = L->data[i];
    printf("getElem succeed .length:%d , size:%d , address:%p \n", L->length, L->size, &L);
    for (int j = 0; j < L->length; ++j) {
        printf("\tdata[%d]==> value:%d , address:%p\n", j, L->data[j], &L->data[j]);
    }
    printf("************************%s==>END**********************************\n\n\n\n", "getElem");
    return OK;
}






