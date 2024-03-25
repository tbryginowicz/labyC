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
void add_on_index(node_t **head, int index, int value){
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->val = value;
    if(index == 0){
        new_node->val = value;
        //zamienienie starego heada na nowy
        new_node->next = *head;
        *head = new_node;
        return;
    }
    node_t *curr = *head;
    int i = 0;
    while (curr->next != NULL && i < index - 1) {
        curr = curr->next;
        i++;
    }
    node_t *temp = curr;
    new_node->next = temp->next;
    curr->next = new_node;
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
    add_on_index(&head, 0, 101);
    print(head);
    add_on_index(&head, 4, 101);
    print(head);
    add_on_index(&head, 7, 101);
    print(head);
    add_on_index(&head, 11, 101);
    print(head);
    return 0;
}