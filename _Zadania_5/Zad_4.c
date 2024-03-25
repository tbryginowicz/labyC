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
void remove_by_index(node_t **head, int index){
    if(index == 0){
        *head = (*head)->next;
        return;
    }
    node_t *curr = *head;
    int i = 0;
    while (curr->next != NULL && i < index - 1) {
        curr = curr->next;
        i++;
    }
    curr->next = curr->next->next;
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
    remove_by_index(&head, 0);
    print(head);
    remove_by_index(&head, 1);
    print(head);
    remove_by_index(&head, 4);
    print(head);

    return 0;
}