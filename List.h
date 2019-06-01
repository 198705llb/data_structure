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

typedef int Datatype;

typedef struct {
    Datatype *data;
    int length;
    int size;
} List;

/**
 * 初始化列表
 * @param L
 */
int initList(List *L) {
    printf("************************%s==>START**********************************\n", "initList");
    L->data = (Datatype *) malloc(sizeof(Datatype) * LIST_SIZE);
    if (L->data == NULL) {
        return ERROR;
    }
    L->length = 0;
    L->size = LIST_SIZE;
    printf("initList List succeed .length:%d , size:%d , address:%p \n", L->length, L->size, &L);
    printf("************************%s==>END**********************************\n\n\n\n", "initList");
    return OK;
}

/**
 * 销毁列表
 * @param L
 * @return
 */
int destroyList(List *L) {
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
int listInsert(List *L, int i, Datatype data) {
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
int listDelete(List *L,int i,Datatype *data){

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






