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
    int count;
};

List *new_list(void);
void insert_front(List *l, float val);
void insert_back(List *l, float val);
void insert_at(List *l, Node **dest, float val);
void remove_at(List *l, Node **dest, float val);
void remove_front(List *l);
void remove_back(List *l);
int search_item(List *l, float val, Node **res);
void print_list(const List *l);
void clear_list(List *l);

#endif // LLIST_H
