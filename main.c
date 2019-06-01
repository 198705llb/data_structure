#include <stdio.h>
#include "List.h"

int main() {
    printf("Hello, World!\n");
    List list;
    initList(&list);
    listInsert(&list, 1, 2);
    listInsert(&list, 3, 4);
    listInsert(&list, 5, 3);
    Datatype data;
    listDelete(&list, 2, &data);
    printf("###########%d\n", data);
    destroyList(&list);
    list.size = 100;
    return 0;
}