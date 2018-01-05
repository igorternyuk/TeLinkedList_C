#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

List *new_list()
{
    List *L;
    L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->tail = L->head;
    L->count = 0;
    return L;
}

void clear_list(List *l)
{    
    if(l == NULL || (l->head) == NULL || l->head->next == NULL) return;
    while(l->count > 0)
        remove_back(l);
}

void print_list(const List *l)
{
    if(l == NULL) return;
    Node *it;
    printf("--------------------------\n");
    for(it = l->head; it != NULL; it = it->next)
    {
        printf("%8.3f ", it->val);
    }
    printf("\n");
    printf("--------------------------\n");
}

void insert_front(List *l, float val)
{
    if(l == NULL) return;
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
    ++l->count;
}

void insert_back(List *l, float val)
{
    if(l == NULL) return;
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
    ++l->count;
}

void insert_at(List *l, Node **dest, float val)
{
    if(l == NULL || l->head == NULL || *dest == NULL) return;

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
            ++l->count;
            break;
        }
        it = it->next;
    }
}

void remove_at(List *l, Node **dest, float val)
{
    if(l == NULL || l->head == NULL || *dest == NULL) return;

    Node *it = l->head;
    while (it != NULL) {
        if(it == *dest)
        {
            Node* delElement = it;
            it->prev->next = it->next;
            it->next->prev = it->prev;
            free(it);
            --l->count;
            break;
        }
        it = it->next;
    }
}

void remove_front(List *l)
{
    if(l == NULL || l->count == 0)
        return;

    if(l->count == 1)
    {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
        l->count = 0;
    }
    else
    {
        Node* head = l->head;
        l->head = l->head->next;
        l->head->prev = NULL;
        free(head);
    }
    --l->count;
}

void remove_back(List *l)
{
    if(l == NULL || l->count == 0)
        return;
    if(l->count == 1)
    {
        free(l->tail);
        l->head = NULL;
        l->tail = NULL;
        l->count = 0;
    }
    else
    {
        Node *tail = l->tail;
        l->tail = l->tail->prev;
        l->tail->next = NULL;
        free(tail);
    }
    --l->count;
}

int search_item(List *l, float val, Node **res)
{
    if(l == NULL || l->head == NULL) return 0;

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
