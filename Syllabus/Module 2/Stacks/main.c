#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Stack {
    int* a;
    int top, size;
};

void initStack(struct Stack* s) {
    printf("Enter stack size : ");
    scanf("%d", &s->size);
    s->a = (int*) malloc(sizeof(int)*s->size);
    s->top = -1;
}

void push(struct Stack* s, int key) {
    if (s->top == s->size-1) {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->a[s->top] = key;
}

int pop(struct Stack* s) {
    if (s->top == -1) {
        return -1;
    }
    int x = s->a[s->top];
    s->top--;
    return x;
}

int top(struct Stack s) {
    if (s.top == -1) {
        return -1;
    }
    return s.a[s.top];
}

int isEmpty(struct Stack s) {
    if (s.top == -1) return 1;
    return 0;
}

int isFull(struct Stack s) {
    if (s.top == s.size-1) return 1;
    return 0;
}

int main() {
    int choice, x;
    struct Stack s;
    initStack(&s);
    while (1) {
        printf("\n\nMENU\nPress 1 to push.\nPress 2 to pop.\nPress 3 to view top element.\nPress 4 to check if stack is empty.\nPress 5 to check if stack is full.\nPress 6 to exit.\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be pushed : ");
            scanf("%d", &x);
            push(&s, x);
            break;
        case 2:
            x = pop(&s);
            if (x == -1) {
                printf("Stack underflow.\n");
            } else {
                printf("Element %d has been popped.\n", x);
            }
            break;
        case 3:
            x = top(s);
            if (x == -1) {
                printf("Stack underflow.\n");
            } else {
                printf("Element at top is %d\n", x);
            }
            break;
        case 4:
            x = isEmpty(s);
            if (x == 1) {
                printf("Stack is empty\n");
            } else {
                printf("Stack is not empty.\n");
            }
            break;
        case 5:
            x = isFull(s);
            if (x == 1) {
                printf("Stack is full.\n");
            } else {
                printf("Stack is not full.\n");
            }
            break;
        case 6:
            exit(0);
        default:
            printf("Warning : Invalid choice!\n");
            break;
        }
    }
    return 0;
}