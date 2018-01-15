#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

List *list_create()
{
    List *L;
    L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->tail = L->head;
    L->count = 0;
    return L;
}

void list_clear_list(List *l)
{
    if(l == NULL || (l->head) == NULL || l->head->next == NULL) return;
    while(l->count > 0)
        list_remove_back(l);
}

void list_print_list(const List *l)
{
    if(l == NULL) return;
    Node *it;
    printf("--------------------------\n");
    for(it = l->head; it != NULL; it = it->next)
    {
        printf("%8.3f ", it->data);
    }
    printf("\n");
    printf("Size: %d\n", l->count);
    printf("--------------------------\n");
}

void list_insert_front(List *l, float val)
{
    if(l == NULL) return;
    if(l->head == NULL)
    {
        //printf("List is empty. We insert first element: %5.3f\n", val);
        l->head = (Node*)malloc(sizeof(Node));
        l->head->data = val;
        l->head->next = NULL;
        l->head->prev = NULL;
        l->tail = l->head;
    }
    else
    {
        //printf("List is not empty. We insert next element: %5.3f\n", val);
        l->head->prev = (Node*)malloc(sizeof(Node));
        l->head->prev->data = val;
        l->head->prev->prev = NULL;
        Node *oldHead = l->head;
        l->head = l->head->prev;
        l->head->next = oldHead;
    }
    ++l->count;
}

void list_insert_back(List *l, float val)
{
    if(l == NULL) return;
    if(l->head == NULL)
    {
        //printf("List is empty. We insert first element: %5.3f\n", val);
        l->head = (Node*)malloc(sizeof(Node));
        l->head->data = val;
        l->head->next = NULL;
        l->head->prev = NULL;
        l->tail = l->head;
    }
    else
    {
        //printf("List is not empty. We insert next element: %5.3f\n", val);
        l->tail->next = (Node*)malloc(sizeof(Node));
        l->tail->next->data = val;
        l->tail->next->next = NULL;
        Node * oldTail = l->tail;
        l->tail = l->tail->next;
        l->tail->prev = oldTail;
    }
    ++l->count;
}

void list_insert_at(List *l, Node **dest, float val)
{
    if(l == NULL || l->head == NULL || *dest == NULL) return;

    Node *it = l->head;
    while (it != *dest)
        it = it->next;
    printf("New element insertion\n");
    Node *newElement = (Node*)malloc(sizeof(Node));
    newElement->data = val;
    newElement->next = it->next;
    newElement->prev = it;
    it->next = newElement;
    newElement->next->prev = newElement;
    ++l->count;
}

void list_remove_at(List *l, Node **dest)
{
    if(l == NULL || l->head == NULL || *dest == NULL)
        return;
    Node *it = l->head;
    while (it != *dest)
        it = it->next;
    if(it->next)
    {
        it->prev->next = it->next;
        it->next->prev = it->prev;
        free(it);
        --l->count;
    }
}

void list_remove_front(List *l)
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

void list_remove_back(List *l)
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

int list_search_item(List *l, float val, Node **res)
{
    if(l == NULL || l->head == NULL) return 0;

    Node* it = l->head;
    while(it != NULL)
    {
        if(it->data == val)
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

List *list_merge_lists(List *l1, List *l2){

    if(l1 != NULL)
    {
        if(l2 == NULL)
            return l1;
        else
        {
            List * list = list_create();
            Node *it1 = l1->head;
            while(it1 != NULL)
            {
                list_insert_back(list, it1->data);
                it1 = it1->next;
            }

            Node *it2 = l2->head;
            while(it2 != NULL)
            {
                list_insert_back(list, it2->data);
                it2 = it2->next;
            }
            return list;
        }
    }
    else
    {
        if(l1 == NULL)
            return l2;
        else
            return NULL;
    }
}

void list_insert_nth_from_head(List *l, int index, float val)
{
    if(l == NULL || index > l->count) return;
    if(index == 0)
        list_insert_front(l, val);
    else
    {
        Node *current = l->head;
        for(int i = 0; i < index - 1; ++i)
            current = current->next;
        list_insert_at(l, &current, val);
    }
}

void list_insert_nth_from_tail(List *l, int index, float val)
{
    if(l == NULL || index > l->count) return;
    if(index == l->count)
        list_insert_back(l, val);
    else
    {
        Node *current = l->tail;
        for(int i = 0; i < index; ++i)
            current = current->prev;
        list_insert_at(l, &current, val);
    }
}

void list_remove_nth_from_head(List *l, int index)
{
    if(l == NULL || index > l->count) return;
    if(index == 0)
        list_remove_front(l);
    else
    {
        Node *current = l->head;
        for(int i = 0; i < index - 1; ++i)
            current = current->next;
        list_remove_at(l, &current);
    }
}

void list_remove_nth_from_tail(List *l, int index)
{
    if(l == NULL || index > l->count) return;
    if(index == l->count)
        list_remove_back(l);
    else
    {
        Node *current = l->tail;
        for(int i = 0; i < index; ++i)
            current = current->prev;
        list_remove_at(l, &current);
    }
}

void list_remove_dublicates(List *l, int(*compare)(Node *a, Node *b))
{
    if(!l || !l->head) return;
    Node *curr = l->head;
    while(curr->next)
    {
        if(compare(curr, curr->next) == 0)
        {
            Node *next_next = curr->next->next;
            list_remove_at(l, &(curr->next));
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }
    }
}

List *list_clone(const List *l)
{
    if(l == NULL) return NULL;
    List *new_list = list_create();
    Node *current = l->head;
    if(current != NULL)
    {
        while(current != NULL)
        {
            list_insert_back(new_list, current->data);
            current = current->next;
        }
    }
    return new_list;
}

void list_swap_nodes(List *l, Node *a, Node *b)
{
    if(l == NULL || l->count == 0 || a == b) return;
    swap_nodes_(a, b);
    if(a == l->head)
        l->head = b;
    else if(b == l->head)
        l->head = a;
    if(a == l->tail)
        l->tail = b;
    else if(b == l->tail)
        l->tail = a;
}

void list_bubble_sort(List *l, int(*compare)(Node *a, Node *b))
{
    Node *curr = NULL;
    Node *next = NULL;
    Node *end = l->tail->next;
    bool isSorted = false;
    while(!isSorted /*end != l->head->next*/)
    {
        isSorted = true;
        curr = l->head;
        next = curr->next;

        while (curr != end)
        {
            if(compare(curr, next) > 0)
            {
                list_swap_nodes(l, curr, next);
                isSorted = false;
            }
            else
                curr = curr->next;
            next = curr->next;
            if(next == end)
                end = curr;
        }
    }
}

void list_merge_sort(List *l, int(*compare)(Node *a, Node *b))
{
    if(!l || l->count == 0 || l->count == 1) return;
    l->head = merge_sort_(l->head, compare);
    Node *walk = l->head;
    while(walk->next != NULL)
        walk = walk->next;
    l->tail = walk;
}

void list_quick_sort(List *l, int(*compare)(Node *a, Node *b))
{
    if(!l || l->count == 0 || l->count == 1) return;
    quick_sort_(l->head, l->tail, compare);
}

Node* merge_sort_(Node *head, int(*compare)(Node *a, Node *b))
{
    if(!head || !head->next) return head;
    Node* mid = split_(head);
    head = merge_sort_(head, compare);
    mid = merge_sort_(mid, compare);
    return merge_sorted_(head, mid, compare);
}

Node* split_(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while(fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* mid = slow->next;
    slow->next = NULL;
    return mid;
}

Node* merge_sorted_(Node *first, Node *second, int(*compare)(Node *a, Node*b))
{
    if(!first) return second;
    if(!second) return first;
    if(compare(first, second) < 0)
    {
        first->next = merge_sorted_(first->next, second, compare);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge_sorted_(first, second->next, compare);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

void swap_nodes_(Node *a, Node *b)
{
    if(a->next == b) //Adjacent nodes
    {
        a->next = b->next;
        b->prev = a->prev;
        b->next = a;
        a->prev = b;
        if(a->next != NULL)
            a->next->prev = a;
        if(b->prev != NULL)
            b->prev->next = b;
    }
    else
    {
        Node *a_next = a->next;
        Node *a_prev = a->prev;
        a->next = b->next;
        a->prev = b->prev;
        b->next = a_next;
        b->prev = a_prev;

        if(b->next != NULL)
            b->next->prev = b;
        if(b->prev != NULL)
            b->prev->next = b;

        if(a->next != NULL)
            a->next->prev = a;
        if(a->prev != NULL)
            a->prev->next = a;
    }
}

Node *partition_(Node *left, Node *right, int(*compare)(Node *a, Node *b))
{
    Node *pivot = right;
    Node *i = left->prev;

    for(Node *j = left; j != right; j = j->next)
    {
        if(compare(j, pivot) < 0)
        {
            i = (i == NULL)? left: i->next;
            swap_data(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? left: i->next;
    swap_data(&(i->data), &(right->data));
    return i;
}

void quick_sort_(Node *left, Node *right, int(*compare)(Node *a, Node *b))
{
    if(!left || !right || left == right || left == right->next) return;
    Node *pivot = partition_(left, right, compare);
    quick_sort_(left, pivot->prev, compare);
    quick_sort_(pivot->next, right, compare);
}

void swap_data(float *a, float *b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

