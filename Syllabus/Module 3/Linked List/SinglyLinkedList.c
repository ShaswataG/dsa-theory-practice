#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int count(struct Node* p) {
    int cnt = 0;
    while (p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

void insertBegin(struct Node** head, int key) {
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;
    if (!*head) {
        *head = t;
    } else {
        t->next = *head;
        *head = t;
    }
}

void insertAfterPosition(struct Node** head, int pos, int key) {
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;
    struct Node* p = *head;
    if (pos < 0 && pos > count(p)) {
        printf("Invalid position\nPosition should be in the range [0, %d]\n", count(p));
        return;
    }
    if (pos == 0) {
        t->next = p;
        *head = t;
    } else {
        for (int i = 0; p && i < pos-1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void insertEnd(struct Node** head, int key) {
    struct Node* t = (struct Node*) malloc(sizeof(struct Node));
    t->data = key;
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
}

int deleteBegin(struct Node** head) {
    int x = -1;
    if (!*head) {
        x = (*head)->data;
        *head = (*head)->next;
    }
    return x;
}

int deleteEnd(struct Node** head) {
    struct Node* p = *head;
    struct Node* q = NULL;
    while (p && p->next) {
        q = p;
        p = p->next;
    }
    if (p) {
        if (q) q->next = p->next;
        else *head = p->next;
        int x = p->data;
        free(p);
    } else {
        printf("List empty\n");
        return -1;
    }
}

int deleteKey(struct Node** head, int key) {
    struct Node* p = *head;
    struct Node* q = NULL;
    while (p && p->data != key) {
        q = p;
        p = p->next;
    }
    if (p) {
        int x = p->data;
        q->next = p->next;
        free(p);
        return x;
    } else {
        return -1;
    }
}

void display(struct Node* head) {
    struct Node* p = head;
    if (!p) {
        printf("List empty");
        return;
    } else {
        printf("List : ");
        while (p) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

struct Node* search1(struct Node* p, int key) {
    while (p && p->data != key) {
        p = p->next;
    }
    return p;
}

struct Node* search2(struct Node* p, int key) {
    if (p->data == key) return p;
    else if (!p) return NULL;
    else return search2(p->next, key);
}

int main() {
    int choice, x, y;
    struct Node* head = NULL;
    struct Node* t = NULL;
    while (1) {
        printf("\n\nMENU\nPress 1 to insert\nPress 2 to delete\nPress 3 to display\nPress 4 to search\nPress 5 to exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("INSERT\nPress 1 to insert at the beginning\nPress 2 to insert after a position\nPress 3 to insert at end\n");
                printf("Enter choice : ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter value to be inserted at the beginning: ");
                    scanf("%d", &x);
                    insertBegin(&head, x);
                    break;
                case 2:
                    printf("Enter position after which you want to insert : ");
                    scanf("%d", &y);
                    printf("Enter value to be inserted : ");
                    scanf("%d", &x);
                    insertAfterPosition(&head, y, x);
                    break;
                case 3:
                    printf("Enter value to be inserted at the end : ");
                    scanf("%d", &x);
                    insertEnd(&head, x);
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
                }
                break;
            case 2:
                printf("Press 1 to delete at the beginning\nPress 2 to delete a value\nPress 3 to delete at the end\n");
                printf("Enter choice : ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    x = deleteBegin(&head);
                    if (x == -1) {
                        printf("List empty\n");
                    } else {
                        printf("%d deleted from list\n", x);
                    }
                    break;
                case 2:
                    printf("Enter value to be deleted : ");
                    scanf("%d", &x);
                    y = deleteKey(&head, x);
                    if (y == -1) {
                        printf("Couldn't find %d in the list\n", x);
                    } else {
                        printf("%d deleted from list\n", y);
                    }
                    break;
                case 3:
                    x = deleteEnd(&head);
                    if (x == -1) {
                        printf("List empty\n");
                    } else {
                        printf("%d deleted from list\n", x);
                    }
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
                }
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter value to search : ");
                scanf("%d", &x);
                t = search1(head, x);
                if (!t) {
                    printf("Couldn't find %d in the list\n", x);
                } else {
                    printf("%d found at %p", x, t);
                }
                break;
            case 5:
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}