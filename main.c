#include <stdio.h>
#include "ArrayList.h"
#include "LinkedList.h"

/**
 * 测试List
 * @return
 */
int testList(){
    ArrayList list;
    initList(&list);
    listInsert(&list, 1, 2);
    listInsert(&list, 3, 4);
    listInsert(&list, 5, 3);

    Datatype dataForDelete;
    listDelete(&list, 2, &dataForDelete);
    printf("\tdataForDelete:%d\n", dataForDelete);

    Datatype dataForGetEnum;
    getElem(&list,1,&dataForGetEnum);
    printf("\tdataForGetEnum:%d\n", dataForGetEnum);
    destroyList(&list);
    list.size = 100;
}

int testLinkedList(){
    printf("size of LNode:%d , size of LinkList:%d\n", sizeof(LNode), sizeof(LinkList));
    ElemType dataForInit = 10;
    LinkList linkList = initLinkList(dataForInit);

    ElemType dataForInsert = 11;
    insertLinkList(linkList,dataForInsert);
    ElemType dataForInsert2 = 12;
    insertLinkList(linkList,dataForInsert2);
}


int main() {
//   testList();
    testLinkedList();
    return 0;
}

