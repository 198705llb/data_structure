//
// Created by llb on 2019/6/1.
//

#ifndef DATA_STRUCTURE_LINKEDLIST_H
#define DATA_STRUCTURE_LINKEDLIST_H

#endif //DATA_STRUCTURE_LINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR -1

typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
} LNode, *LinkList;


/**
 * 打印链表的全部元素
 * @param linkList
 */
void printList(LinkList linkList) {
    if (linkList == NULL) {
        printf("LinkList have not been inited !");
        return;
    }
    int index = 0;
    //打印最后一个元素之前的所有元素
    while (linkList->next != NULL) {
        printf("\t==>index:%d , data:%d , next:%p \n", index, linkList->data, linkList->next);
        index++;
        linkList = linkList->next;
    }
    //打印最后一个元素
    printf("\t==>index:%d , data:%d , next:%p \n", index, linkList->data, linkList->next);
    return;
}

/**
 * 初始化列表
 * @param L
 * @param data
 * @return
 */
LinkList initLinkList(ElemType data) {
    printf("************************%s==>START**********************************\n", "initLinkList");
    if (data == NULL) {//没有元素初始化是没有意义的
        printf("data can not be null!");
        return NULL;
    }
    LinkList L = (LNode *) malloc(sizeof(LNode));
    L->data = data;
    L->next = NULL;
    printf("LinkList is inited ! address:%p\n", L);
    printList(L);
    printf("************************%s==>END**********************************\n\n\n\n", "initLinkList");
    return L;
}

/**
 * 在尾部插入元素
 * @param L
 * @param data
 * @return
 */
int insertLinkList(LinkList linkList, ElemType data) {
    printf("************************%s==>START**********************************\n", "insertLinkList");
    if (linkList == NULL) {
        printf("LinkList has not been inited ! please init it frist ! address:%p\n", linkList);
        return ERROR;
    }
    LinkList O = linkList;
    LNode *newnode = (LNode *) malloc(sizeof(LNode));
    newnode->data = data;
    newnode->next = NULL;

    while (linkList->next) {
        linkList = linkList->next;
    }
    linkList->next = newnode;
    printList(O);
    printf("************************%s==>END**********************************\n\n\n\n", "insertLinkList");
    return OK;
}




