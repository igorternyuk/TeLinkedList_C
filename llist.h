#ifndef list_H
#define list_H

typedef struct Node Node;

struct  Node
{
    float data;
    Node *next;
    Node *prev;
};

typedef struct
{
    Node *head;
    Node *tail;
    int count;
} List;

List *list_create(void);
void list_destroy(List **l);
void list_insert_front(List *l, float val);
void list_insert_back(List *l, float val);
void list_insert_at(List *l, Node **dest, float val);
void list_insert_nth_from_head(List *l, int index, float val);
void list_insert_nth_from_tail(List *l, int index, float val);
void list_remove_at(List *l, Node **dest);
void list_remove_front(List *l);
void list_remove_back(List *l);
void list_remove_nth_from_head(List *l, int index);
void list_remove_nth_from_tail(List *l, int index);
int list_search_item(List *l, float val, Node **res);
List* list_merge_lists(List *l1, List *l2);
List* list_clone(const List *l);
void list_bubble_sort(List *l, int(*compare)(Node *a, Node*b));
void list_merge_sort(List *l, int(*compare)(Node *a, Node *b));
void list_quick_sort(List *l, int(*compare)(Node *a, Node *b));
void list_remove_dublicates(List *l, int(*compare)(Node *a, Node *b));
void list_print_list(const List *l);
void list_clear_list(List *l);
void list_swap_nodes(List *l, Node *a, Node *b);
void swap_nodes_(Node *a, Node *b);
Node* split_(Node *head);
Node* find_middle(Node *head);
Node* merge_sorted_(Node *first, Node *second, int(*compare)(Node *a, Node*b));
Node *merge_sort_(Node *head, int(*compare)(Node *a, Node *b));
Node* partition_(Node *left, Node *right, int(*compare)(Node *a, Node *b));
void swap_data(float *a, float *b);
void quick_sort_(Node *left, Node *right, int(*compare)(Node *a, Node *b));

#endif // list_H
