#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_linkedlist(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);

int main(){
    int option;

    do{
        printf("\n***Main Menu***");
        printf("\n1: Create a list");
        printf("\n2: Display the list");
        printf("\n3: Insert at beginning");
        printf("\n4: Insert at end");
        printf("\n5: Delete from beginning");
        printf("\n6: Delete from end");
        printf("\n7: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1: start = create_linkedlist(start);
                    printf("Linked list created\n");
                    break;
            case 2: start = display(start);
                    break;
            case 3: start = insert_beg(start);
                    break;
            case 4: start = insert_end(start);
                    break;
            case 5: start = delete_beg(start);
                    break;
            case 6: start = delete_end(start);
                    break;
        }

    }while(option != 7);

    return 0;
}

struct node *create_linkedlist(struct node *start){
    struct node *new_node, *ptr;
    int n;

    printf("Enter -1 to stop\n");
    printf("Enter data: ");
    scanf("%d", &n);

    while(n != -1){
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = n;
        new_node->next = NULL;

        if(start == NULL){
            start = new_node;
        }
        else{
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
        }

        printf("Enter data: ");
        scanf("%d", &n);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr = start;

    if(ptr == NULL){
        printf("List is empty\n");
        return start;
    }

    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");

    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node;
    int n;

    printf("Enter data: ");
    scanf("%d", &n);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->next = start;
    start = new_node;

    return start;
}

struct node *insert_end(struct node *start){
    struct node *new_node, *ptr;
    int n;

    printf("Enter data: ");
    scanf("%d", &n);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->next = NULL;

    if(start == NULL){
        start = new_node;
        return start;
    }

    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_node;

    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr;

    if(start == NULL){
        printf("List is empty\n");
        return start;
    }

    ptr = start;
    start = start->next;
    free(ptr);

    return start;
}

struct node *delete_end(struct node *start){
    struct node *ptr, *preptr;

    if(start == NULL){
        printf("List is empty\n");
        return start;
    }

    if(start->next == NULL){
        free(start);
        return NULL;
    }

    ptr = start;
    while(ptr->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);

    return start;
}