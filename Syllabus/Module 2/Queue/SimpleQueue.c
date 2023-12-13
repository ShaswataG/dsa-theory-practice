#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int* a;
    int size, front, rear;
};

void initQueue(struct Queue* q) {
    printf("Enter size of queue : ");
    scanf("%d", &q->size);
    q->front = q->rear = -1;
    q->a = (int*) malloc(q->size*sizeof(int));
}

void enqueue(struct Queue* q, int key) {
    if (q->rear == q->size-1) {
        printf("Queue is full.\n");
        return;
    }
    q->rear++;
    q->a[q->rear] = key;
}

int dequeue(struct Queue* q) {
    if (q->rear == q->front) {
        return -1;
    }
    int x = q->a[q->front+1];
    q->a[q->front++];
    return x;
}

int frontElement(struct Queue q) {
    if (q.rear == q.front) return -1;
    return q.a[q.front+1];
}

int isEmpty(struct Queue q) {
    if (q.rear == q.front) return 1;
    return 0;
}

int isFull(struct Queue q) {
    if (q.rear == q.size-1) return 1;
    return 0;
}

int main() {
    int choice, x;
    struct Queue q;
    initQueue(&q);
    while (1) {
        printf("\n\nMENU\nPress 1 to enqueue.\nPress 2 to dequeue.\nPress 3 to view front element.\nPress 4 to check if queue is empty.\nPress 5 to check if queue is full.\nPress 6 to exit.\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter elemenet to enqueue : ");
                scanf("%d", &x);
                enqueue(&q, x);
                break;
            case 2:
                x = dequeue(&q);
                if (x == -1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("%d is dequeued.\n", x);
                }
                break;
            case 3:
                x = frontElement(q);
                if (x == -1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Element at front is %d\n", x);
                }
                break;
            case 4:
                x = isEmpty(q);
                if (x == 1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 5:
                x = isFull(q);
                if (x == 1) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Warning : Invalid choice");
        }
    }
    return 0;
}