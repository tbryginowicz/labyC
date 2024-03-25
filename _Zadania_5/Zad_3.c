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
void remove_last(node_t **head){
    node_t *curr = *head;
    node_t *prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
}

int main(){

    node_t *head = NULL;

    add_first(&head, 10);
    add_first(&head, 100);
    add_first(&head,1);
    print(head);
    remove_last(&head);
    print(head);

    return 0;
}