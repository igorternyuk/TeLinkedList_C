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
    while(!feof(file))
    {
        float val;
        fscanf(file,"%f",&val);
        insert_value_back(l, val);
        insert_value_front(l, val);
    }
    Node* six = NULL;
    if(search_item(l, 6.0, &six) == 1)
    {
        printf("Element was found: %5.3f\n", six->val);
        insert_value_at(l, &six, 100.f);
    }
    else
    {
        printf("Element not found");
    }
    Node* three = NULL;
    if(search_item(l, 3.0, &three) == 1)
    {
        printf("Element was found: %5.3f\n", three->val);
        remove_value_at(l, &three, 100.f);
    }
    else
    {
        printf("Element not found");
    }

    fclose(file);
    show_list(l);
    printf("List size: %d\n", countItems(l));
    clear_list(l);
    return 0;
}
