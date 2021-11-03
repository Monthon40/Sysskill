#include<stdio.h>
#include<stdlib.h>
#include"list.h"
// Feels free to include anything here if you need to
#include <string.h>


Node *front = NULL;
int search(int num)
{
    Node *current = front;
    // while the current node is not null loop throught all of the node
    while (current != NULL) {
        if (current->value == num) {
            printf("Found %d\n", num);
            return num;
        }
        current = current->next;
    }
    // the last node is null and cannot find num
    printf("Cannot Find %d\n", num);
    return num;
}

void insert(int num)
{
    Node *temp;
    temp->value = num;
    temp->next = NULL;

    //If front is null or larger set temp as front
    if (front == NULL || num <= front->value) {
        temp->next = front;
        front = temp;
        return;
    }


    Node *current = front;
    while ( current->next != NULL) {
        // if num is larger than current node compare it to next one
        if (num > current->next->value) {
            current = current->next;
            continue;
        }
        // insert num
        temp->next = current->next;
        current->next = temp;
        return;
    }
    // if num is the largest set temp as the last node
    current->next = temp;
    return;
}
int delete(int num)
{
    //IMPLEMENT
    if (front == NULL ) {
        return 0;
    }

    //delete num and reassign front
    if (front->value == num) {
        Node temp;
        free(front);
        front = temp;
        return 1;
    }

    //delete num and reassign the current node to next
    Node *current = front;
    while (current->next != NULL) {
        if ( current->next->value == num ) {
            Node* temp = current->next->next;
            free(current->next);
            current->next = temp;
            return 1;
        }
        current = current->next;
    }
    //If num is the biggest delete it
    if (current->next == NULL && current->value == num){
        free(current->value)
        return 1;
    }
    return 0;
}

void print()
{
    Node *current = front;
    // print current and next node until it is null
    while (current != NULL){
        printf("%d, ", current->value);
        current = current->next;
    }
}

int main()
{
    int len;
    scanf("%d\n", len);

    for (int i=0; i<len; i++) {
        char command[];
        int val;
        scanf("%c %d\n", &command, &val);

        // comapare the command operation
        if (strcmp(command, "I")==0) {
            insert(val);
        }
        else if (strcmp(command,"D")==0) {
            delete(val);
        }
        else if (strcmp(command, "S")==0) {
            search(val);
        }
        else if (strcmp(command, "P")==0) {
            print();
        }
    }
}

