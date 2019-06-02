//
// Created by llb on 2019/6/2.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#endif //DATA_STRUCTURE_STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR -1


typedef int Elem;//栈的元素
/**链表的实现**/
typedef struct stacknode {
    Elem data;
    struct stacknode *per;
    struct stacknode *next;
} SLNode, *LList;
/**栈结构体*/
typedef struct stack {
    SLNode *base;//栈底节点
    SLNode *top;//栈顶节点
    int size;
} Stack;

/**
 * 打印链表
 * @param lList
 */
void printLList(LList lList) {
    if (lList == NULL) {
        printf("LList have not been inited !");
        return;
    }
    int index = 0;
    //打印最后一个元素之前的所有元素
    while (lList->next != NULL) {
        printf("\t\t\tLList==>index:%d , data:%d ,current:%p ,pre:%p , next:%p \n", index, lList->data, lList,
               lList->per, lList->next);
        index++;
        lList = lList->next;
    }
    //打印最后一个元素
    printf("\t\t\tLList==>index:%d , data:%d ,current:%p , pre:%p , next:%p \n", index, lList->data, lList, lList->per,
           lList->next);
    return;
}

/**
 * 打印栈信息
 * @param stack
 */
void printStack(Stack *stack) {
    if (stack == NULL) {
        printf("Stack have not been inited ! ");
        return;
    }
    if (stack->base == NULL) {
        printf("\tStack:: Size==> %d    ;  BaseNode==> address:%p ;   TopNode==> address:%p \n", stack->size,
               stack->base, stack->top);
        return;
    }
    printf("\tStack:: Size==> %d    ;  BaseNode==> address:%p , data:%d , next:%p    ;   TopNode==> address:%p , data:%d , next:%p \n",
           stack->size, stack->base, stack->base->data, stack->base->next, stack->top, stack->top->data,
           stack->top->next);
    printLList(stack->base);
}

/**
 * 初始化一个空栈
 * @return
 */
Stack *initStack() {
    printf("************************(%s)==>START**********************************\n", "*initStack");
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->size = 0;
    stack->base = NULL;
    stack->top = NULL;
    printStack(stack);
    printf("************************(%s)==>END**********************************\n\n\n", "*initStack");
    return stack;
}

/**
 *压入一个元素
 * @param stack
 * @param elem
 * @return
 */
int push(Stack *stack, Elem elem) {
    printf("************************(%s)==>START**********************************\n", "push");
    if (stack == NULL) {
        printf("stack is null !");
        return ERROR;
    }
    SLNode *sNode = (SLNode *) malloc(sizeof(SLNode));
    sNode->data = elem;
    sNode->next = NULL;
    sNode->per = NULL;
    if (stack->base == NULL) {
        stack->base = sNode;
        stack->top = sNode;
    } else {
        sNode->per = stack->top;
        stack->top->next = sNode;
        stack->top = sNode;
    }
    stack->size++;
    printStack(stack);
    printf("************************(%s)==>END**********************************\n\n\n", "push");
    return OK;
}

Elem pop(Stack *stack) {
    printf("************************(%s)==>START**********************************\n", "pop");
    if (stack == NULL) {
        printf("stack is null !");
        return ERROR;
    }
    if (stack->base == NULL) {
        printf("stack is empty ! address:", stack);
        return ERROR;
    }
    SLNode *currentTop = stack->top;
    Elem elem = currentTop->data;
    stack->top = stack->top->per;
    stack->top->next = NULL;
    free(currentTop);
    stack->size--;
    printStack(stack);
    printf("************************(%s)==>END**********************************\n\n\n", "pop");
    return elem;
}