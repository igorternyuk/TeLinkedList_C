#ifndef LLIST_H
#define LLIST_H

typedef struct List List;
typedef struct Node Node;

struct Node
{
    float val;
    Node *next;
    Node *prev;
};

struct List
{
    Node *head;
    Node *tail;
};

List *new_list(void);
void insert_value_front(List *l, float val);
void insert_value_back(List *l, float val);
void insert_value_at(List *l, Node **dest, float val);
void remove_value_at(List *l, Node **dest, float val);
void remove_front(List *l);
void remove_back(List *l);
int search_item(List *l, float val, Node **res);
int countItems(List *l);
void show_list(const List *l);
void clear_list(List *l);

#endif // LLIST_H
