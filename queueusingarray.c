#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front, rear, capacity;  
    int *queue;
};

struct Queue* createQueue(int capacity){
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q-> front = 0;
    q-> rear = -1;
    q-> capacity = capacity;
    q-> queue = (int*) malloc(sizeof(int)* q->capacity);
    return q;
};

// to check if queue is empty
int isEmpty(struct Queue* q){
    return (q-> rear == -1);
}
// to check if queue is full
int isFull(struct Queue* q){
    return (q-> rear == q-> capacity -1);
}
// to push into the queue
void push(struct Queue* q, int newData){
    if(isFull(q)){
        printf("Buffer Overflow: \n");
        return ;
    }
    else{
        q->rear++;
        q->queue[q->rear] = newData;
        printf("added %d to the queue \n",newData);
    }
}
// to pop from the queue
int pop(struct Queue* q){
    if(isEmpty(q)){
        printf("Buffer Underflow \n");
        return -1;
    }
    else{
    int poppedElement = q->queue[q->front];
    // shifting of elements to maintain queue order.
    for(int i = 0; i < q-> rear; i++){
        q->queue[i] = q->queue[i + 1];
    }
    // decrementing rear by 1
    q-> rear --;
    return poppedElement;
    }   
}
// to check the front element in the queue
void front(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty \n");
        return ;
    }
    printf("Front element is: %d\n",q->queue[q->front]);
}




int main(){
    struct Queue *q = createQueue(5);
    printf("is queue empty?: %d\n", isEmpty(q));
    push(q,4);
    push(q,5);
    push(q,6);
    push(q,7);
    push(q,8);
    push(q,9); // buffer overflow occurs here 
    printf("popped element is: %d\n",pop(q));
    printf("popped element is: %d\n",pop(q));
    printf("popped element is: %d\n",pop(q));
    printf("popped element is: %d\n",pop(q));
    printf("popped element is: %d\n",pop(q));
    printf("popped element is: %d\n",pop(q)); // buffer underflow

    if(isEmpty(q)){
        printf("q is empty \n");
    }
    else{
        printf("q's front: %d\n",q->queue[q->front]);
        printf("q's rear: %d\n",q->queue[q->rear]);
    }

    

    return 0;
}