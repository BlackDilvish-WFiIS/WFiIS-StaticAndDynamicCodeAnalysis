#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

Node* add_node(Node** head, int newElementValue)
{
    Node* element = (Node*)malloc(sizeof(Node) * 1);
    
    element->value = newElementValue;
    element->next = NULL;

    Node* lastElement = *head==NULL? NULL : *head;

    while(NULL != lastElement->next)
    {
        lastElement = lastElement->next;
    }

    lastElement->next = element;

    return element;
}

void clear_list(Node** head)
{
    Node* element = *head;

    do
    {
        Node* elementToDelete = element;
        element = element->next;
        free(elementToDelete);
    } while(NULL != element);

    *head = NULL; 
}

void print_list(Node* head)
{
    Node* currentNode = head;

    printf("[");

    while(NULL != currentNode->next)
    {
        printf("%d, ", currentNode->value);
        currentNode = currentNode->next;
    }

    printf("]\n");
}