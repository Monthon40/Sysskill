#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void insert(Node **tree, int val) {
    if(*tree == NULL){
        Node * ttt = malloc(sizeof(Node));
        ttt->store = val;
        ttt->rootLeft = NULL;
        ttt->rootRight = NULL;
        *tree = ttt;

        return;
    }else{
        if(val > (*tree)->store){

            insert(&((*tree)->rootRight), val);
        }
        else{
            insert(&((*tree)->rootLeft), val);
        }
    }
}

void delete(Node *tree) {
    if (tree == NULL){
        return;
    }

    delete(tree->rootLeft);
    delete(tree->rootRight);
    free(tree);
}

void print2(Node *var, int asb)
{
    if (var == NULL){
        return;
    }
    int j = 0;
    while (j < asb){
        printf("  ");
        j++;
    }

    printf("|-%d\n", var->store);

    if (var->rootLeft != NULL){print2(var->rootLeft, asb + 1);}
    if (var->rootRight != NULL){print2(var->rootRight, asb + 1);}
}

void print(Node *tree) {
    if (tree == NULL){return;}

    printf("%d\n",tree->store);
    if (tree->rootLeft != NULL){
        print2(tree->rootLeft, 0);
    }
    if (tree->rootRight != NULL){
        print2(tree->rootRight, 0);
    }
}

Node *lookup(Node ** tree, int val) {
    if(*tree == NULL){return 0;}
    else{
        if(val == (*tree)->store){
            return tree;
        }
        if(val > (*tree)->store){
            return lookup(&((*tree)->rootRight), val);
        }else{
            return lookup(&((*tree)->rootLeft), val);
        }
    }
}


/***** Expected output: *****
7
|-2
  |-1
  |-4
|-10
  |-15
    |-12
      |-11
Found
Not Found
 *****************************/
int main(int argc, char **argv)
{
    Node *root = NULL;
    Node *target = NULL;

    // add nodes
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 15);
    insert(&root, 12);
    insert(&root, 11);

    // Lets see how the tree looks
    print(root);

    // Check if 4 in the tree
    target = lookup(&root, 4);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Check if 44 in the tree
    target = lookup(&root, 44);
    if (target) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    // Now let's free up the space
    delete(root);
}