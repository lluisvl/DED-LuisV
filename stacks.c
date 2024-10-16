#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
    int info;
    struct stack_node *prev;
} stack_node;

/* STACK GLOBAL */
stack_node *stack_top = NULL;
int count = 0;

void push(int data) {
    stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
    if (new_node == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }
    new_node->info = data;
    new_node->prev = stack_top; 
    stack_top = new_node;
    count++;
}

// Para esta version de stack de enteros, regresa -1 si no hay
// nada que hacer pop
int pop() {
    if (stack_top == NULL) {
        printf("\nStack Underflow\n");
        return -1;
    }
    int data = stack_top->info;
    stack_node *temp = stack_top;
    stack_top = stack_top->prev;
    free(temp);
    count--;
    return data;
}

// Muestra los elementos actuales del stack
void display() {
    stack_node *nptr = stack_top;
    if (nptr == NULL) {
        printf("\nStack Underflow\n");
        return;
    }
    printf("The stack is:\n");
    while (nptr != NULL) {
        printf("%d--->", nptr->info);
        nptr = nptr->prev;
    }
    printf("NULL\n\n");
}

int main() {
    int choice, value, ret;
    printf("\nSTACK:\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\n\tChoice : ");
        ret = scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\tEnter the value to insert: ");
                ret = scanf("%d", &value);
                push(value);
                break;
            case 2:
                printf("Popped element is : %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
}
