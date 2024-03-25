#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int val;
    struct node * next;
}node_t;

void print(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d, ", current->val);
        current = current->next;
    }
    printf("\n");
}

void add_first(node_t **head, int value) {

    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    new_node->val = value;
    //zamienienie starego heada na nowy
    new_node->next = *head;
    *head = new_node;
}

void pop(node_t **head) {
    *head = (*head)->next;
}

int main(){

    node_t *head = NULL;

    add_first(&head, 10);
    add_first(&head, 100);
    add_first(&head,1);
    print(head);
    pop(&head);
    print(head);

    return 0;
}