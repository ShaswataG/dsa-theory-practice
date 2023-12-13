#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int* a;
    int size, front, rear;  
};

void initQueue(struct Queue* q) {
    printf("Enter size of queue : ");
    scanf("%d", &q->size);
    q->a = (int*) malloc(q->size*sizeof(int));
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, int key) {
    if((q->rear+1)%q->size == q->front) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear+1)%q->size;
    q->a[q->rear] = key;
}

int dequeue(struct Queue* q) {
    if (q->front == q->rear) return -1;
    int x = q->a[(q->front+1)%q->size];
    q->front = (q->front+1)%q->size;
    return x;
}

int frontElement(struct Queue q) {
    if (q.front == q.rear) return -1;
    return q.a[(q.front+1)%q.size];
}

int isEmpty(struct Queue q) {
    if (q.front == q.rear) return 1;
    return 0;
}

int isFull(struct Queue q) {
    if ((q.rear+1)%q.size == q.front) return 1;
    return 0;
}

void display(struct Queue q) {
    if (q.front == q.rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements are : ");
    for (int i = (q.front+1)%q.size; i <= q.rear; i = (i+1)%q.size) {
        printf("%d ", q.a[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    int choice, x;
    while (1) {
        printf("\n\nMENU\nPress 1 to enqueue.\nPress 2 to dequeue.\nPress 3 to view front element.\nPress 4 to display queue.\nPress 5 to check if queue is empty.\nPress 6 to check if queue is full.\nPress 7 to exit.\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to enqueue : ");
                scanf("%d", &x);
                enqueue(&q, x);
                break;
            case 2:
                x = dequeue(&q);
                if (x == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("%d is dequeued\n", x);
                }
                break;
            case 3:
                x = frontElement(q);
                if (x == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("%d is at the front of queue\n", x);
                }
                break;
            case 4:
                display(q);
                break;
            case 5:
                x = isEmpty(q);
                if (x == 1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 6:
                x = isFull(q);
                if (x == 1) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 7:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Warning : Invalid Choice\n");
        }
    }
    return 0;
}