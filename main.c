#include <stdio.h>
#include "ArrayList.h"

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


int main() {
   testList();
    return 0;
}

