//
// Created by llb on 2019/6/2.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#endif //DATA_STRUCTURE_QUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR -1

typedef int QElem;//队列中的元素
typedef struct qnode {//队列使用的链表
    QElem data;
    struct qnode *next;
} QNode, *QList;

typedef struct queue {//队列
    QNode *head;
    QNode *tail;
    int size;
} Queue;

/**
 * 打印链表
 * @param lList
 */
void printQList(QList qList) {
    if (qList == NULL) {
        printf("QList have not been inited !");
        return;
    }
    int index = 0;
    //打印最后一个元素之前的所有元素
    while (qList->next != NULL) {
        printf("\t\t\tqList==>index:%d , data:%d ,current:%p , next:%p \n", index, qList->data, qList,
               qList->next);
        index++;
        qList = qList->next;
    }
    //打印最后一个元素
    printf("\t\t\tqList==>index:%d , data:%d ,current:%p ,  next:%p \n", index, qList->data, qList,
           qList->next);
    return;
}

/**
 * 打印栈信息
 * @param stack
 */
void printQueue(Queue *queue) {
    if (queue == NULL) {
        printf("queue have not been inited ! ");
        return;
    }
    if (queue->head == NULL) {
        printf("\tqueue:: Size==> %d    ;  Head==> address:%p ;   Tail==> address:%p \n", queue->size,
               queue->head, queue->tail);
        return;
    }
    printf("\tqueue:: Size==> %d    ;  Head==> address:%p , data:%d , next:%p    ;   Tail==> address:%p , data:%d , next:%p \n",
           queue->size, queue->head, queue->head->data, queue->head->next, queue->tail, queue->tail->data,
           queue->tail->next);
    printQList(queue->head);
}

/**
 * 获取一个初始化的空队列
 * @return
 */
Queue *initQueue() {
    printf("************************(%s)==>START**********************************\n", "*initQueue");
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    printQueue(queue);
    printf("************************(%s)==>end**********************************\n\n\n", "*initQueue");
    return queue;
};

/**
 * 添加元素
 * @param queue
 * @param qElem
 * @return
 */
int add(Queue *queue, QElem qElem) {
    printf("************************(%s)==>START**********************************\n", "add");
    if (queue == NULL) {
        printf("Queue is not inited !");
        return ERROR;
    }
    QNode *qNode = (QNode *) malloc(sizeof(QNode));
    qNode->data = qElem;
    qNode->next = NULL;
    QList qList = queue->head;
    if (qList == NULL) {
        queue->head = qNode;
        queue->tail = qNode;
    } else {
        queue->tail->next = qNode;
        queue->tail = qNode;
    }
    queue->size++;
    printQueue(queue);
    printf("************************(%s)==>END**********************************\n\n\n", "add");
    return OK;
}

/**
 * 从队列头部取出一个元素
 * @param queue
 * @return
 */
QElem take(Queue *queue) {
    printf("************************(%s)==>START**********************************\n", "take");
    if (queue == NULL) {
        printf("Queue is not inited !");
        return ERROR;
    }
    QNode *head = queue->head;
    QElem data = head->data;
    queue->head=head->next;
    free(head);
    queue->size--;
    printQueue(queue);
    printf("************************(%s)==>END**********************************\n\n\n", "take");
    return data;
}
