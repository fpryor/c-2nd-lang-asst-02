#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node* next;
    struct Node* last;
};

void list_push(struct Node** head_ptr, int new_number) {

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->number = new_number;
    new_node->next = (*head_ptr);
    new_node->last = NULL;

    if ((*head_ptr) != NULL)
        (*head_ptr)->last = new_node;

    (*head_ptr) = new_node;
}


void list_append(struct Node** head_ptr, int new_number) {

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = *head_ptr;

    new_node->number = new_number;
    new_node->next = NULL;

    if (*head_ptr == NULL) {
        new_node->last = NULL;
        *head_ptr = new_node;
        return;
    }

    while (tail->next != NULL)
        tail = tail->next;

    tail->next = new_node;
    new_node->last = tail;
}

void insert_after(struct Node* last_node, int new_number) {
    if (last_node == NULL) {
        printf("last node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->number = new_number;
    new_node->next = last_node->next;
    last_node->next = new_node;
    new_node->last = last_node;

    if (new_node->next != NULL)
        new_node->next->last = new_node;
}

void delete_node(struct Node** head_ptr, int index) {
    if (*head_ptr == NULL)
        return;

    struct Node* temp = *head_ptr;

    if (index == 0) {
        *head_ptr = temp->next;
        free(temp);
        return;
    }

    for (int i=0; temp!= NULL && i<index-1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct Node *next = temp->next->next;

    free(temp->next);

    temp->next = next;

}

void print_list(struct Node* node) {
    struct Node* tail;
    printf("\nupdated list: \n");
    while (node != NULL) {
        printf("%d ", node->number);
        tail = node;
        node = node->next;
    }
}

int main() {

    struct Node * head = NULL;

    printf("Running Linked List\n");

    for (int i = 1; i < 4; i++) {
        list_append(&head, i);
    }
    print_list(head);

    insert_after(head->next, 4);
    print_list(head);

    list_push(&head, 0);
    print_list(head);

    insert_after(head->next, 1);
    print_list(head);

    list_push(&head, 2);
    print_list(head);

    insert_after(head->next, 7);
    print_list(head);

    insert_after(head->next->next, 8);
    print_list(head);

    delete_node(&head, 2);
    print_list(head);

    for (int i = 1; i < 5; i++) {
        delete_node(&head, i);
    }
    print_list(head);

    return 0;
}