#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* previous;
}Node;

typedef struct list {
    int len;
    struct node* head;
}List;

List* new_list(){
    List* newlist = malloc(sizeof(List));
    newlist -> len = 0;
    newlist -> head = NULL;
    return newlist;
}

void add(List* L, int data) {
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    n->previous = NULL;

    if (L->len != 0){
        Node* h;
        h= L->head;
        if(h->next !=NULL){
            n->next = h->next;
            h->next->previous=n;
        }
        h->next = n;
        n->previous = h;
    }else {
        L->head=n;
    }
    L->len++;
}

Node* pop(List* L, int data){
    Node* n = L->head;
    remove_data(L, data);
    return n;
}

void push(List* L, int data){
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->previous = NULL;
    n->next = NULL;
    if (L->head==NULL){
        L->head = n;
    }else{
        n->next=L->head;
        L->head=n;
    }
}

void remove_data(List* L, int data){
    Node* n =  L->head;
    if (n->data==data){
        L->head = n->next;
        free(n);
    }
    else{
        n=n->next;
        while (n != NULL){
            if (n->data == data){
                if (n->next != NULL){
                    n->next->previous=n->previous;
                    n->previous->next=n->next;
                }else{
                    n->previous->next=NULL;
                }
                free(n);
                L->len--;
                break;
            }
            n=n->next;
        }
    }
}

void free_list(List* L){
    Node* current_node = L->head;
    while (current_node != NULL) {
        Node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(L);
}

void print_list(List* L){
    Node* n = L->head;
    while (n!=NULL){
        printf("%d->", n->data);
        n= n->next;
    }
    printf("\n");
}
