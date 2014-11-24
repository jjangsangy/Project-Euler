/**
  * Singly Linked List
  * Abstract DataType
  *
  * Author: Sang Han
  *   Year: 2014
  *
  * Abstract DataType specification for implementing singly linked
  * list data structure.
  *
  * When using user defined structs, it's important that
  * to also implement function that can compare between two struct pointers
  * returning the standard value for equality.
  *
  **/

#ifndef LIST_H
#define LIST_H

// Structures
typedef struct _node {
    void *data;
    struct _node *next;
} Node;

typedef struct _list {
    Node *head;
    Node *tail;
    Node *current;
} List;

// Function Prototypes
void initialize_list(List *list);
void add_head(List);
void add_tail(List *list, void *data);
void delete(List *list, Node *node);
Node *get_node(List *list);

#endif
