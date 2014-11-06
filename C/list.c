/**
  * Singly Linked List
  * Implementation
  *
  * Author: Sang Han
  *   Year: 2014
  *
  * Implements a dynamic singly linked list data structure and
  * operations. Characteristics of singly linked vs double
  * is we can assume previous link is never null since we cannot
  * traverse backwards.
  *
  **/

#include "list.h"

void initialize_list(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void add_head(List)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    if (list->head == NULL) {
        list->tail = node;
        node->next = NULL;
    } else {
        node->next = list->head;
    }
}

void add_tail(List *list, void *data)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

Node *get_node(List *list)
{
    Node *node = list->head;
    while (node != NULL) {
        if (compare(node->data, data) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void delete(List *list, Node *node) {

    if (node == list->head) NULL) {
        if (list->head->next == NULL) {
            list->head = list->tail = NULL;
        } else {
            list->head = list->head->next;
        }

    } else {
        Node *tmp = list->head;
        while (tmp != NULL && tmp->next != node) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            tmp->next = node->next;
        }
    }
    free(node);
}
