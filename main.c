#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "llist.h"

int compare(Node *a, Node *b)
{
    if(a == NULL || b == NULL) return -1;
    if(a->data == b->data) return 0;
    return a->data < b->data ? -1 : +1;
}

int main(void)
{
    char *fileName = "data.txt";
    FILE* file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("Input file error");
        return -1;
    }
    List *l = list_create();
    printf("Initial list size: %d\n", l->count);
    while(!feof(file))
    {
        float val;
        fscanf(file,"%f",&val);
        list_insert_back(l, val);
        //list_insert_front(l, val);
    }

    Node* six = NULL;
    if(list_search_item(l, 6.0, &six) == 1)
    {
        printf("Element was found: %5.3f\n", six->data);
        list_insert_at(l, &six, 100.f);
    }
    else
    {
        printf("Element not found");
    }
    Node* three = NULL;
    if(list_search_item(l, 3.0, &three) == 1)
    {
        printf("Element was found: %5.3f\n", three->data);
        list_remove_at(l, &three);
    }
    else
    {
        printf("Element not found");
    }

    fclose(file);
    list_print_list(l);
    list_bubble_sort(l, &compare);
    printf("*******Bubble sort********");
    list_print_list(l);
    list_insert_nth_from_head(l,5,404);
    list_print_list(l);
    list_insert_nth_from_tail(l,4,777);
    list_print_list(l);
    list_remove_nth_from_tail(l,2);
    list_print_list(l);
    printf("\n**********\n");
    printf("List size: %d\n", l->count);
    List *l2 = list_create();
    list_insert_back(l2, 7.0f);
    list_insert_back(l2, 6.0f);
    list_insert_back(l2, 14.0f);

    list_print_list(l2);
    List *res = list_merge_lists(l, l2);
    list_print_list(res);
    list_clear_list(l);
    list_clear_list(l2);
    list_clear_list(res);
    printf("------Clone----------");
    List *l3 = list_create();
    list_insert_back(l3,1);
    list_insert_back(l3,2);
    list_insert_back(l3,3);
    list_print_list(l3);
    List *l3clone = list_clone(l3);
    list_print_list(l3clone);
    list_clear_list(l3);
    list_clear_list(l3clone);
    printf("\n*******Merge sorting***********\n");
    srand(time(NULL));
    List *l4 = list_create();
    for(size_t i = 0; i < 120; ++i)
    {
        list_insert_back(l4, rand() % 100);
    }
    list_print_list(l4);
    list_merge_sort(l4,&compare);
    list_print_list(l4);
    list_clear_list(l4);
    printf("\n*******Quick sorting***********\n");
    List *l5 = list_create();
    for(size_t i = 0; i < 200; ++i)
    {
        list_insert_back(l5, rand() % 500);
    }
    list_print_list(l5);
    list_quick_sort(l5, &compare);
    list_print_list(l5);
    list_clear_list(l5);

    List *l6 = list_create();
    list_insert_back(l6, 1);
    list_insert_back(l6, 1);
    list_insert_back(l6, 1);
    list_insert_back(l6, 2);
    list_insert_back(l6, 2);
    list_insert_back(l6, 3);
    list_insert_back(l6, 3);
    list_insert_back(l6, 3);
    list_insert_back(l6, 3);
    list_insert_back(l6, 3);
    list_insert_back(l6, 4);
    list_insert_back(l6, 4);
    list_insert_back(l6, 4);
    list_insert_back(l6, 5);
    list_insert_back(l6, 7);
    list_insert_back(l6, 8);
    list_insert_back(l6, 8);
    list_insert_back(l6, 8);
    list_print_list(l6);
    list_remove_dublicates(l6, &compare);
    list_print_list(l6);
    list_clear_list(l6);
    return 0;
}
