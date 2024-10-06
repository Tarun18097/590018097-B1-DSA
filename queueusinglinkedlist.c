#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
   struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

// create a new node
struct Node* createNode(int newData){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node-> data = newData;
    node-> next = NULL;
    return node;
}

void createQueue(struct Queue* q){
    q-> front = NULL;
    q-> rear = NULL;
}

int isEmpty(struct Queue* q){
    return (q->front == NULL);
}

void enque(struct Queue* q, int newData){
    // create a new node
    struct Node* newNode = createNode(newData);
    if(q-> front == NULL){
        // first element.
        q->front = q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("added element in queue: %d\n", newData);
}

int deque(struct Queue* q){
    int poppedElement = -1;
    if(q-> front == NULL){
        printf("Buffer underflow\n");
    }
    else{
        struct Node* temp = q->front;
        poppedElement = temp->data;
        q->front = q->front->next;
        free(temp);

        if(q->front == NULL){
            q-> rear = NULL;
        }
    }
    return poppedElement;
}

int peek(struct Queue* q){
    if(isEmpty(q)){
        printf("Stack is empty \n");
    }
    else{
        return q->front->data;
    }
    return -1;
}

int main(){
    struct Queue q;
    createQueue(&q);
    printf("Is Queue empty?: %d\n", isEmpty(&q));
    enque(&q,5);
    enque(&q,6);
    enque(&q,7);
    printf("popped element is: %d\n",deque(&q));
    printf("popped element is: %d\n",deque(&q));
    printf("popped element is: %d\n",deque(&q));
    printf("popped element is: %d\n",deque(&q)); // buffer underflow
    if(isEmpty(&q)){
        printf("queue is empty \n");
    }
    else{
        printf("stack's front: %d\n", peek(&q));
        printf("stack's rear %d\n",q.rear->data);
    }
    return 0;
}