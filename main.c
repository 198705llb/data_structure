#include <stdio.h>
#include "ArrayList.h"
#include "LinkedList.h"
#include "Stack.h"

/**
 * 测试List
 * @return
 */
int testList() {
    ArrayList list;
    initList(&list);
    listInsert(&list, 1, 2);
    listInsert(&list, 3, 4);
    listInsert(&list, 5, 3);

    Datatype dataForDelete;
    listDelete(&list, 2, &dataForDelete);
    printf("\tdataForDelete:%d\n", dataForDelete);

    Datatype dataForGetEnum;
    getElem(&list, 1, &dataForGetEnum);
    printf("\tdataForGetEnum:%d\n", dataForGetEnum);
    destroyList(&list);
    list.size = 100;
}

int testLinkedList() {
    printf("size of LNode:%d , size of LinkList:%d\n", sizeof(LNode), sizeof(LinkList));
    ElemType dataForInit = 1;
    LinkList linkList = initLinkList(dataForInit);

    ElemType dataForInsert = 2;
    insertLinkList(linkList, dataForInsert);
    ElemType dataForInsert2 = 3;
    insertLinkList(linkList, dataForInsert2);
    ElemType dataForInsertHead = 4;
    linkList = insertLinkListHead(linkList, dataForInsertHead);
    printList(linkList);
    ElemType dataForInsertIndex = 5;
    linkList = insertLinkListIndex(linkList, 1, dataForInsertIndex);
    printList(linkList);
    printf("\t===>getElemLinkList:%d\n", getElemLinkList(linkList, 0));
    linkList = destroyLinkList(linkList);
    printList(linkList);
}

void testStack() {
    Stack *stack = initStack();
    push(stack,0);
    push(stack,1);
    push(stack,2);
    pop(stack);
}

int main() {
//   testList();
//    testLinkedList();
    testStack();
    return 0;
}

