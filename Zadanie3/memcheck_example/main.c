#include <stdio.h>
#include "Node.h"

int main(void)
{
    Node* head = NULL;
    head = add_node(&head, 4);
    add_node(&head, 10);
    add_node(&head, 15);
    add_node(&head, 23);
    add_node(&head, 92);

    print_list(head);

    clear_list(&head);

    print_list(head);

    head = add_node(&head, 2);
    add_node(&head, 5);

    print_list(head);

    clear_list(&head);
    clear_list(&head);
    
    return 0;
}