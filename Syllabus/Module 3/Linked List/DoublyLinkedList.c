#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* prev,* next;
};

void insertBegin(struct Node** head, struct Node** last, int key) {
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->data = key;
    t->prev = *last;
    t->next = NULL;
    if (!*head) {
        *head = t;
    } else {
        t->next = *head;
        *head = t;
    }
    *last = t;
}

void insertEnd(struct Node** head, struct Node** last, int key) {
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->data = key;
    t->prev = *last;
    t->next = NULL;
    if (!*head) {
        *head = t;
    } else {
        struct Node* p = *head;
        struct Node* q = NULL;
        while (p) {
            q = p;
            p = p->next;
        }
        q->next = t;
    }
    *last = t;
}

int deleteAfterPosition(struct Node** head, int pos) {
    struct Node* p = *head;
    int x = -1;
    if (!*head) {
        return x;
    } else {
        if (pos == 0) {
            (*head)->next->prev = NULL;
            x = (*head)->data;
            *head = (*head)->next;
        }
        for (int i = 0; p && i <= pos-1; i++) {
            p = p->next;
        }
        if (p) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
    }
}

int main() {
    struct Node* head1, * last1;
    head1 = last1 = NULL;
    insertEnd(&head1, &last1, 3);
    return 0;
}