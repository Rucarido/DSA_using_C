#include <stdio.h>
#define MAX 5

typedef struct q {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initialise(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, int value) {
    if (isFull(q) == 1) {
        printf("Queue is full!\n");
        return;
    }

    (q->front == -1) ? (q->front = 0) : q->front;
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;

    printf("%d element is inserted\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q) == 1) {
        printf("Queue underflow!\n");
        return -1;
    }

    int val = q->data[q->front];
    //If only one element
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % MAX;
    }

    return val;
}

void display(Queue *q) {
    if (q->front == -1) {
        printf("Empty queue!\n");
        return;
    }

    printf("Queue elements: ");
    int front = q->front;
    while (front != q->rear) {
        printf("%d ", q->data[front]);
        front = (front + 1) % MAX;
    }
    printf("%d\n", q->data[q->rear]); //print last element
}

int main() {

    Queue q;
    initialise(&q);

    enqueue(&q, 15);
    enqueue(&q, 21);
    enqueue(&q, 7);
    enqueue(&q, 42);
    enqueue(&q, 50);
    
    display(&q);
    printf("%d element removed from queue\n", dequeue(&q));
    printf("%d element removed from queue\n", dequeue(&q));
    display(&q);

    enqueue(&q, 37);
    display(&q);

    return 0;
}
