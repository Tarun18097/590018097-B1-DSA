#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int top;
    int size;
    int *arr;
} Stack; // using typedef to create the shorthand for struct Stack


// function to create stack
Stack* createStack(int size){
    Stack* stack = (Stack*) malloc (sizeof(Stack));
    stack-> size = size;
    stack-> top = -1;
    stack-> arr = (int*) malloc(stack->size * sizeof(int));
    return stack;
}

// check if stack is full
int isFull(Stack* stack){
    if(stack-> top == stack-> size -1){
        return 1;
    }
    else{
        return 0;
    }
}

// check if stack is empty
int isEmpty(Stack* stack){
    if(stack-> top < 0){
        return 1;
    }
    else{
        return 0;
    }
}

// function for inserting element 
void push(Stack* stack, int data){
    if(isFull(stack)){
        printf("Stack overflow \n");
        return ;
    }
    else{
        stack-> top++;
        stack-> arr[stack->top] = data;
    }

}

// function to pop an element from stack
int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow \n");
        return -1;
    }
    else{
        int poppedElement = stack-> arr[stack-> top];
        stack-> top--;
        return poppedElement;
    }
    return -1;
}

int peek(Stack* stack){
    if(stack-> top < 0){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return stack->arr[stack-> top];
    }
}

int main(){
    Stack* st = createStack(5);
    // check if stack is empty
    if(isEmpty(st)){
        printf("Stack is empty \n");
    }
    else{
        printf("stack is not empty \n");
    }
    // pushing elements in stack
    push(st,1);
    printf("%d is pushed into stack \n",peek(st));
    push(st,2);
    printf("%d is pushed into stack \n",peek(st));
    push(st,3);
    push(st,4);
    printf("%d is pushed into stack \n",peek(st));
    push(st,5);
    printf("%d is pushed into stack \n",peek(st));
    push(st,6); // this element was not pushed as stack was full. 
    printf("top element of stack: %d \n", peek(st));

    // deleting elements
    int poppedElement = pop(st);
    printf("%d is popped from stack \n",poppedElement);
    poppedElement = pop(st);
    printf("%d is popped from stack \n",poppedElement);
    poppedElement = pop(st);
    printf("%d is popped from stack \n",poppedElement);
    poppedElement = pop(st);
    printf("%d is popped from stack \n",poppedElement);
    poppedElement = pop(st);
    printf("%d is popped from stack \n",poppedElement);
    pop(st);


    printf("top element: %i \n", peek(st));

    return 0;
}