#include <stdio.h>
#include <stdlib.h>

// Estructura para crear un nodo del stack
typedef struct stack_node {
    char info;
    struct stack_node *prev;
} stack_node;

// Puntero global para el tope del stack
stack_node *stack_top = NULL;

// Operación Push() para añadir elementos al stack
void push(char data) {
    stack_node *new_node = (stack_node *)malloc(sizeof(stack_node));
    if (new_node == NULL) {
        printf("error al asignar la memoria\n");
        return;
    }
    new_node->info = data;
    new_node->prev = stack_top;
    stack_top = new_node;
}

// Para esta versión de stack de caracteres, regresa -1 si no hay nada que hacer pop
char pop() {
    if (stack_top == NULL) {
        return '\0';
    }
    char popped_value = stack_top->info;
    stack_node *temp = stack_top;
    stack_top = stack_top->prev;
    free(temp);
    return popped_value;
}

void isvalidformula(char *f) {
    stack_top = NULL;
    
    for (int i = 0; f[i] != '\0'; i++) {
        if (f[i] == '(') {
            push(f[i]);
        } else if (f[i] == ')') {
            if (pop() == '\0') {
                printf("La formula \"%s\" no esta bien hecha\n", f);
                return;
            }
        }
    }
    if (stack_top != NULL) {
        printf("La formula \"%s\" no esta bien hecha\n", f);
    } else {
        printf("La frmula \"%s\" esta bien hecha\n", f);
    }
}

int main() {
    char formula1[30] = "aa()bb((c))(ddd((rr((a)a)))";
    char formula2[30] = "((a+b)-(z*d))";
    
    isvalidformula(formula1);
    isvalidformula(formula2);
    
    return 0;
}