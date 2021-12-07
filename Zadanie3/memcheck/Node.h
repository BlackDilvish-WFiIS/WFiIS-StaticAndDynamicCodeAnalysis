#ifndef NODE_H
#define NODE_H

typedef struct ListElement
{
    int value;
    struct ListElement* next;
} Node;

Node* add_node(Node** head, int newElementValue);
void clear_list(Node** head);
void print_list(Node* head);

#endif