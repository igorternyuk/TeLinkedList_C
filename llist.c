#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

List *new_list()
{
    List *L;
    L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->tail = L->head;
    return L;
}

void clear_list(List *l)
{
    if((l->head) == NULL || l->head->next == NULL)
    {
        return;
    }
    Node *it = l->head, *tail, *prev;
    while(it != NULL)
    {
        prev = tail;
        tail = it;
        it = it->next;
    }

    free(tail);
    prev->next = NULL;
    clear_list(l);
}

void show_list(const List *l)
{
    Node *it;
    for(it = l->head; it != NULL; it = it->next)
    {
        printf("%8.3f\n", it->val);
    }
}

void insert_value_front(List *l, float val)
{
    if(l->head == NULL)
    {
        //printf("List is empty. We insert first element: %5.3f\n", val);
        l->head = (Node*)malloc(sizeof(Node));
        l->head->val = val;
        l->head->next = NULL;
        l->head->prev = NULL;
        l->tail = l->head;
    }
    else
    {
        //printf("List is not empty. We insert next element: %5.3f\n", val);
        l->head->prev = (Node*)malloc(sizeof(Node));
        l->head->prev->val = val;
        l->head->prev->prev = NULL;
        Node *oldHead = l->head;
        l->head = l->head->prev;
        l->head->next = oldHead;
    }
    return 0;
}

void insert_value_back(List *l, float val)
{
    if(l->head == NULL)
    {
        //printf("List is empty. We insert first element: %5.3f\n", val);
        l->head = (Node*)malloc(sizeof(Node));
        l->head->val = val;
        l->head->next = NULL;
        l->head->prev = NULL;
        l->tail = l->head;
    }
    else
    {
        //printf("List is not empty. We insert next element: %5.3f\n", val);
        l->tail->next = (Node*)malloc(sizeof(Node));
        l->tail->next->val = val;
        l->tail->next->next = NULL;
        Node * oldTail = l->tail;
        l->tail = l->tail->next;
        l->tail->prev = oldTail;
    }
}

void insert_value_at(List *l, Node **dest, float val)
{
    if(l->head == NULL || *dest == NULL)
    {
        return;
    }
    Node *it = l->head;
    while (it != NULL) {
        if(it == *dest)
        {
            printf("New element insertion\n");
            Node *newElement = (Node*)malloc(sizeof(Node));
            newElement->val = val;
            newElement->next = it->next;
            newElement->prev = it;
            it->next = newElement;
            newElement->next->prev = newElement;
        }
        it = it->next;
    }
}

void remove_value_at(List *l, Node **dest, float val)
{
    if(l->head == NULL || *dest == NULL)
    {
        return;
    }
    Node *it = l->head;
    while (it != NULL) {
        if(it == *dest)
        {
            Node* delElement = it;
            it->prev->next = it->next;
            it->next->prev = it->prev;
            free(it);
            break;
        }
        it = it->next;
    }
}

void remove_front(List *l)
{
    Node* head = l->head;
    free(head);
    l->head = l->head->next;
    l->head->prev = NULL;
}

void remove_back(List *l)
{
    Node *tail = l->tail;
    free(tail);
    l->tail = l->tail->prev;
    l->tail->next = NULL;
}

int search_item(List *l, float val, Node **res)
{
    if(l->head == NULL)
    {
        return 0;
    }
    Node* it = l->head;
    while(it != NULL)
    {
        if(it->val == val)
        {
            *res = it;
            return 1;
        }
        else
        {
            it = it->next;
        }
    }
    return 0;
}

int countItems(List *l)
{
    if(l->head == NULL)
    {
        return 0;
    }
    int counter = 0;
    Node* it = l->head;
    while(it != NULL){
        it = it->next;
        ++counter;
    }
    return counter;
}
