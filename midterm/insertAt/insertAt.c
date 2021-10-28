#include<stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* next;
};

// Size of linked list
int size = 0;

// function to create and return a Node
struct Node* getNode(int data)
{
    // allocating space
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node()));

    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAt(struct Node** ttt, int index, int data)
{
    if (index < 0 || index > size)
        printf("Wrong Index!");
    else {
        index = index + 1;
        while (index--) {
            if (index == 0) {
                struct Node* aa = getNode(data);
                aa->next = *ttt;
                *ttt = aa;
            }
            else
                ttt = &(*ttt)->next;
        }
        size++;
    }
}

// This function prints contents
// of the linked list
void printList(struct Node* head)
{
    while (head != NULL) {
        printf( " %d ", head -> data);
        head = head->next;
    }
    printf("\n");
}

// Driver Code
int main()
{
    // Creating the list 3->5->8->10
    struct Node* head = NULL;
    head = getNode(3);
    head->next = getNode(5);
    head->next->next = getNode(8);
    head->next->next->next = getNode(10);

    size = 4;

    printf("Linked list before insertion: ");
    printList(head);

    insertAt(&head, 2, 23);
    printList(head);

    int data = 12, pos = 3;
    insertAt(&head, pos, data);
//    printf("Linked list after insertion of 12 at position 3: ");
    printList(head);

    // front of the linked list
    data = 1, pos = 0;
    insertAt(&head, pos, data);
//    printf("Linked list after insertion of 1 at position 1: ");
    printList(head);

    // insertion at end of the linked list
    data = 15, pos = 5;
    insertAt(&head, pos, data);
//    printf("Linked list after insertion of 15 at position 7: ");
    printList(head);

    insertAt(&head, 9, 11);
    printList(head);

    return 0;
}