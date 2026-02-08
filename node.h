#ifndef NODE_H
#define NODE_H

struct node {
    int id;
    char name[50];
    struct node *next;
};

#endif


