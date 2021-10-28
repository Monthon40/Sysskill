#include<stdio.h>
#include<stdlib.h>
struct node_name{
    int my_data;
    struct node_name *next;
};
typedef struct node_name Node;
Node *front;
//Delete the first occurence of my data
void delete(int data){
    Node *temp;
    Node *previous;
    if(front == NULL) return;
    else
    {
        for(temp = front; temp->my_data != data && temp->next!=NULL; temp = temp->next);
        if(temp->my_data == data)
        {
            previous->next = temp->next;
            free(temp);
        }
    }
    return;
}
//Insert a new node at the end
void insert(int data){
    Node *temp;
    Node *temp2;
    for(temp = front; temp->next != NULL; temp = temp->next);
    temp2 = malloc(sizeof(Node));
    temp2->my_data = data;
    temp2->next = NULL;
    temp->next = temp2;
}

struct Node* getNode(int data)
{
    Node* newNode = (struct Node*) malloc(sizeof(Node()));
    newNode->my_data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAt(int index, int data)
{
    Node **ttt;
    int size = 0;
    if (index < 0 || index > size)
        printf("Wrong Index!");
    else {
        index = index + 1;
        while (index--) {
            if (index == 0) {
                Node* temp = getNode(data);
                temp->next = *ttt;
                *ttt = temp;
            }
            else
                ttt = &(*ttt)->next;
        }
        size++;
    }
}



//Just print the linked list, but make this sorted
void print(){
    Node *temp;
    printf("{");
//TODO: IMPLEMENT THIS for part C
    printf("}\n");
}