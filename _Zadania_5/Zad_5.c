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
void remove_by_value(node_t **head, int value){
    node_t *curr = *head;
    node_t *prev = NULL;
    while (curr->next != NULL) {
        if(prev == NULL && curr->val == value){
            *head = (*head)->next;
            return;
        }
        prev = curr;
        curr = curr->next;
        if (curr->val == value){
            prev->next = prev->next->next;
        }
    }
}

int main(){

    node_t *head = NULL;

    add_first(&head,9);
    add_first(&head,8);
    add_first(&head,7);
    add_first(&head,6);
    add_first(&head,5);
    add_first(&head,4);
    add_first(&head,3);
    add_first(&head,2);
    add_first(&head,1);
    add_first(&head,0);
    print(head);
    remove_by_value(&head, 0);
    print(head);
    remove_by_value(&head, 1);
    print(head);
    remove_by_value(&head, 4);
    print(head);
    remove_by_value(&head, 9);
    print(head);
    return 0;
}