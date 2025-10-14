/*
The input consists of the following choices:
If the choice is 1, 1 X → Insert book ID X at the front.
If the choice is 2, 2 X → Insert book ID X at the end.
If the choice is 3, 3 P X → Insert book ID X at position P.
If the choice is 4, 4 → Delete the first book ID.
If the choice is 5, 5 → Delete the last book ID.
If the choice is 6, 6 P → Delete the book ID at position P.
If the choice is 7, 7 X → Search for book ID X.
If the choice is 8, 8 → Traverse the linked list and print the book IDs in order.
If the choice is 9, 9 → Exit the program.
If the choice is greater than 9, print "Wrong choice".
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

Node* create(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    return newNode;
}

void insertAtFront(Node** head, int val) {
    Node* newNode = create(val);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(Node** head, int val) {
    Node* newNode = create(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node** head, int val, int pos) {
    Node* newNode = create(val);
    if (pos == 1) {
        insertAtFront(head, val);
        return;
    }
    Node* temp = *head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Node Inserted\n");
}

void deleteFirst(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    free(temp);
}

void deletePosition(Node** head, int pos) {
    if (pos == 1) {
        deleteFirst(head);
        return;
    }
    
    Node* temp = *head;
    int count = 1;
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void search(Node** head, int key) {
    if (*head == NULL) {
        printf("The element %d is not found in the list\n", key);
        return;
    }
    
    Node* temp = *head;
    int count = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("The element %d is at index %d in the list\n", key, count);
            break;
        }
        count++;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("The element %d is not found in the list\n", key);
    }
}

void traverse(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = *head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    
    Node* head = NULL;
    int flag = 0;
    while (flag == 0) {
        int choice; scanf("%d", &choice);
        switch(choice) {
            case 1:
                int val; scanf("%d", &val);
                insertAtFront(&head, val);
                break;
            case 2:
                int v; scanf("%d", &v);
                insertAtEnd(&head, v);
                break;
            case 3:
                int pos, key; scanf("%d%d", &pos, &key);
                insertAtPosition(&head, key, pos);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                int p; scanf("%d", &p);
                deletePosition(&head, p);
                break;
            case 7:
                int search_key; scanf("%d", &search_key);
                search(&head, search_key);
                break;
            case 8:
                traverse(&head);
                break;
            case 9:
                flag = 1;
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    
    return 0;
}
