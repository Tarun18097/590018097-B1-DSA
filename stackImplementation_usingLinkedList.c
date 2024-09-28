#include<stdlib.h>
#include<stdio.h>
// structure for nodes 
struct Node{
    int data;
    struct Node* next;
};
// structure for stack
struct Stack{
    struct Node* top;
};

// function to initialize stack
struct Stack* initializeStack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack-> top = NULL; // stack is empty
    return stack;
}

void push(struct Stack* stack, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode-> data = data;
    newNode-> next = stack->top; // link new node to current top node
    stack->top = newNode; // make new node the top of stack
}

int pop(struct Stack* stack){
    if(stack-> top == NULL){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        int poppedElement = stack->top->data;
        struct Node* temp = stack-> top;
        stack-> top = stack-> top-> next;
        free(temp);
        return poppedElement;
    }
    return -1;
}

int peek(struct Stack* stack){
    if(stack-> top == NULL){
        printf("stack is empty \n");
        return -1;
    }
    else{
        return stack-> top-> data;
    }
}

int isEmpty(struct Stack* stack){
    return stack->top == NULL;
}


int main(){
    struct Stack* stack = initializeStack();
    
    printf("Is stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    printf("Top element is: %d\n", peek(stack));
    
    printf("Popped element: %d\n", pop(stack));
    printf("Top element after pop: %d\n", peek(stack));
    
    printf("Is stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");

    return 0;
}

