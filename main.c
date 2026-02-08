#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

typedef struct node* NodePtr;

/* Insert at end */
NodePtr insert(NodePtr head, int id, char *name) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    NodePtr temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Print list */
void printList(NodePtr head) {
    while (head) {
        printf("%d %s\n", head->id, head->name);
        head = head->next;
    }
}

/* Free list */
void freeList(NodePtr head) {
    NodePtr temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    NodePtr head = NULL;

    /* argv starts from index 1, use pairs */
    for (int i = 1; i < argc; i += 2) {
        int id = atoi(argv[i]);
        char *name = argv[i + 1];
        head = insert(head, id, name);
    }

    printList(head);
    freeList(head);

    return 0;
}


