#include <stdio.h>
#include "llist.h"

int main(void)
{
    char *fileName = "data.txt";
    FILE* file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("Input file error");
        return -1;
    }
    List *l = new_list();
    printf("Initial list size: %d\n", l->count);
    while(!feof(file))
    {
        float val;
        fscanf(file,"%f",&val);
        insert_back(l, val);
        insert_front(l, val);
    }
    Node* six = NULL;
    if(search_item(l, 6.0, &six) == 1)
    {
        printf("Element was found: %5.3f\n", six->val);
        insert_at(l, &six, 100.f);
    }
    else
    {
        printf("Element not found");
    }
    Node* three = NULL;
    if(search_item(l, 3.0, &three) == 1)
    {
        printf("Element was found: %5.3f\n", three->val);
        remove_at(l, &three, 100.f);
    }
    else
    {
        printf("Element not found");
    }

    fclose(file);
    print_list(l);
    printf("List size: %d\n", l->count);
    clear_list(l);
    print_list(l);
    insert_front(l, 5.0f);
    print_list(l);
    return 0;
}
