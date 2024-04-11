#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct node {
    int data;
    struct node* next;
    struct node* previous;
} Node;

typedef struct list {
    int len;
    struct node* head;
} List;

List* new_list();
void add(List* L, int data);
Node* pop(List* L, int data);
void push(List* L, int data);
void remove_data(List* L, int data);
void free_list(List* L);
void print_list(List* L);

#endif /* LINKEDLIST_H_ */
