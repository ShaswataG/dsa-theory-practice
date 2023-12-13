#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int* a, size, front, rear;
};

void initQueue(struct Queue* q) {
    printf("Enter size of Double Ended Queue : ");
    scanf("%d", &q->size);
    q->a = (int*) malloc(q->size*sizeof(int));
    q->front = q->rear = -1;
}

void enqueueFront(struct Queue* q, int key) {
    if (q->front == -1) {
        printf("Can't enqueue from front\n");
        return;
    }
    q->a[q->front] = key;
    q->front--;
}

void enqueueRear(struct Queue* q, int key) {
    if (q->rear == q->size-1) {
        printf("Can't enqueue from rear\n");
        return;
    }
    q->rear++;
    q->a[q->rear] = key;
}

int dequeueFront(struct Queue* q) {
    if (q->front == q->rear) return -1;
    int x = q->a[q->front+1];
    q->front++;
    return x;
}

int dequeueRear(struct Queue* q) {
    if (q->rear == q->front) {
        return -1;
    }
    int x = q->a[q->rear];
    q->rear--;
    return x;
}

void display(struct Queue q) {
    if (q.front == q.rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements are : ");
    for (int i = q.front+1; i<= q.rear; i++) {
        printf("%d ", q.a[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    int choice, x;
    while (1) {
        printf("\n\nMENU\nPress 1 to enqueue.\nPress 2 to dequeue.\nPress 3 to display.\nPress 4 to exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nMENU/ENQUEUE/\n    Press 1 to enqueue from front.\n    Press 2 to enqueue from rear.\n    Press 3 to back.\n    Press 4 to exit.\n    Enter choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("        \nMENU/ENQUEUE/FRONT/\n");
                printf("        Enter element to enqueue : ");
                scanf("%d", &x);
                enqueueFront(&q, x);
                break;
            case 2:
                printf("        \nMENU/ENQUEUE/FRONT/\n");
                printf("        Enter element to enqueue : ");
                scanf("%d", &x);
                enqueueRear(&q, x);
                break;
            case 3:
                printf("        Directing to MENU...\n");
                break;
            case 4:
                printf("        Exiting the program.\n");
                exit(0);
            default:
                printf("        Invalid choice");
                break;
            }
            break;
        case 2:
            printf("\nMENU/DEQUEUE/\n    Press 1 to dequeue from front.\n    Press 2 to dequeue from rear.\n    Press 3 to back.\n    Press 4 to exit.\n    Enter choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                x = dequeueFront(&q);
                if (x == -1) {
                    printf("        Can't dequeue from front\n");
                } else {
                    printf("        %d is dequeued from front\n", x);
                }
                break;
            case 2:
                x = dequeueRear(&q);
                if (x == -1) {
                    printf("        Can't dequeue from rear\n");
                } else {
                    printf("        %d is dequeued from rear\n", x);
                }
                break;
            case 3:
                printf("        Directing to MENU...\n");
                break;
            case 4:
                printf("        Exiting the program.\n");
                exit(0);
            default:
                printf("        Invalid choice");
                break;
            }
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("Exiting the program\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}