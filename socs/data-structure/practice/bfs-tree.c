#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    char value[50];
    struct Node *left;
    struct Node *right;
}Node;

// new tree node
Node* newNode(const int key, char value[]) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    strcpy(node->value, value);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// insert node to tree
Node* insert(Node* tree, const int key, char value[]) {
    Node *temp = newNode(key, value);
    if (tree == NULL) {
        return temp;
    }
    if(key <= tree -> key) {
        tree -> left = insert(tree -> left, key, value);
    } else if(key >= tree -> key) {
        tree -> right = insert(tree -> right, key, value);
    }
    return tree;
}

// delete node in tree
Node* delete(Node* tree, const int key) {
    if (tree == NULL) {
        return NULL;
    }
    if(key < tree -> key) {
        tree -> left = delete(tree -> left, key);
    } else if(key > tree -> key) {
        tree -> right = delete(tree -> right, key);
    } else {
        if(tree -> left == NULL && tree -> right == NULL) {
            free(tree);
            tree = NULL;
        } else if(tree -> left == NULL || tree -> right == NULL) {
            Node *temp;
            if(tree -> left == NULL) {
                temp = tree -> right;
            } else {
                temp = tree -> left;
            }
            *tree = *temp;
            free(tree);
            tree = NULL;
        } else {
            const Node *temp = tree -> left;
            while(temp -> right != NULL) {
                temp = temp -> right;
            }
            tree -> key = temp -> key;
            tree -> left = delete(tree -> left, temp -> key);
        }
    }
    return tree;
}

void printOrdered(Node* tree) {
    if (tree != NULL) {
        printOrdered(tree -> left);
        printf("key: %d value: %s\n", tree -> key, tree -> value);
        printOrdered(tree -> right);
    }
}

int main() {
    // init first node on top
    Node *tree = NULL;
    tree = insert(tree, 1, "hello");
    // insert the rest
    insert(tree, 2, "world");
    insert(tree, 3, "hello");
    insert(tree, 4, "hello");
    insert(tree, 5, "hello");
    // delete
    delete(tree, 4);
    // print all in order
    printOrdered(tree);
    return 0;
}