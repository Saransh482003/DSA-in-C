#include <stdio.h>
#include <stdlib.h>

struct LinkedNode
{
    int data;
    struct LinkedNode *prev;
    struct LinkedNode *next;
};
int insert(int data, struct LinkedNode *node);
int insertInto(int data, int index, struct LinkedNode *node);
struct LinkedNode * getNode(struct LinkedNode *node, int index);
struct LinkedNode * getNext(struct LinkedNode *node);

int insert(int data, struct LinkedNode *node) {
    if (node -> next != NULL) {
        return insert(data, getNext(node));
    }
    struct LinkedNode *nextNode = (struct LinkedNode *) malloc(sizeof(struct LinkedNode));
    if (nextNode == NULL) {
        return -1;
    }
    node -> next = nextNode;
    nextNode -> data = data;
    nextNode -> next = NULL;
    
    return 0;
}
int insertInto(int data, int index, struct LinkedNode *node) {
    struct LinkedNode *nexter = getNode(node, index);
    if (nexter == NULL) {
        return -1;
    }
    nexter -> prev -> next = (struct LinkedNode *) malloc(sizeof(struct LinkedNode));
    nexter -> prev = nexter -> prev -> next;
    nexter -> prev -> data = data;
    nexter -> prev -> next = nexter -> next;
    
    return 0;
}
struct LinkedNode * getNode(struct LinkedNode *node, int index) {
    if (index == 0){
        return node;
    };
    return getNode(node -> next, index-1);
}

struct LinkedNode * getNext(struct LinkedNode *node) {
    return node -> next;
}

int main() {
    struct LinkedNode head;
    head.data = 1;
    head.next = NULL;
    insert(2, &head);
    insert(3, &head);
    insert(4, &head);
    insertInto(5, 2, &head);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", getNode(&head, i) -> data);
    }
    
    return 0;
}