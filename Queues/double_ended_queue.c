/*deque meaning double ended queue 
insertion and deletion can occur at both the front and back
meaning it can act as both LIFO and FIFO
*/

#include <stdio.h>
#define MAX 5

typedef struct q {
    int data[MAX];
    int front;
    int rear;
} Deque;

void initialise(Deque *q) {
    q->front = q->rear = -1;
}

int isEmpty(Deque *q) {
    return q->front == -1;
}

int isFull(Deque *q) {
    return ((q->front == 0 && q->rear == MAX - 1) || (q->front == q->rear + 1));
}

void pushFront(Deque *q, int value) {
    if (isFull(q) == 1) {
        printf("Queue is full!\n");
        return;
    }

    if (q->front == -1) {
        q->front = q->rear = 0;
    }
    else if (q->front == 0) {
        q->front = MAX - 1;
    }
    else {
        q->front = q->front - 1;
    }

    q->data[q->front] = value;
    printf("%d element inserted\n", value);
}

void pushRear(Deque *q, int value) {
    if (isFull(q) == 1) {
        printf("Queue is full!\n");
        return;
    }

    if (q->rear == -1) {
        q->front = q->rear = 0;
    }
    else if (q->rear == MAX - 1) {
        q->rear = 0;
    }
    else {
        q->rear = q->rear + 1;
    }

    q->data[q->rear] = value;
    printf("%d element inserted\n", value);
}

void popFront(Deque *q) {
    if (isEmpty(q) == 1) {
        printf("Queue underflow!\n");
        return;
    }

    int val = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else if (q->front == MAX - 1) {
        q->front = 0;
    }
    else {
        q->front = q->front + 1;
    }

    printf("%d element popped\n", val);
}

void popRear(Deque *q) {
    if (isEmpty(q) == 1) {
        printf("Queue underflow!\n");
        return;
    }

    int val = q->data[q->rear];
    if (q->rear == q->front) {
        q->front = q->rear = -1;
    }
    else if (q->rear == 0) {
        q->rear = MAX - 1;
    }
    else {
        q->rear = q->rear - 1;
    }

    printf("%d element popped\n", val);
}

void display(Deque *q) {
    if (isEmpty(q) == 1) {
        printf("Empty queue!\n");
        return;
    }

    printf("Deque elements: ");
    int front = q->front;
    while (1) {
        printf("%d ", q->data[front]);
        if (front == q->rear) { break; }
        front = (front + 1) % MAX;
    }
    printf("\n");
}

int main() {

    Deque q;
    initialise(&q);

    pushRear(&q, 15);
    pushRear(&q, 17);
    pushFront(&q, 3);
    pushFront(&q, 8);
    pushRear(&q, 23);
    display(&q);

    popRear(&q);
    display(&q);
    popFront(&q);
    display(&q);

    pushFront(&q, 33);
    display(&q);

    popRear(&q);
    display(&q);

    return 0;
}
