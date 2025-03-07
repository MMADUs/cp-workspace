#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    char value[50];
    struct node *left;
    struct node *right;
}node;

typedef struct binary_search_tree {
    node *root;
}BST;

BST *newBST() {
    BST *tree = (BST *)malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

node *newNode(const int key, const char *value) {
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    strcpy(n->value, value);
    n->left = NULL;
    n->right = NULL;
    return n;
}

node *insertNode(node *tree, const int key, char *value) {
    if (tree == NULL) {
        return newNode(key, value);
    }
    if (key < tree->key) {
        tree->left = insertNode(tree->left, key, value);
    } else if (key > tree->key) {
        tree->right = insertNode(tree->right, key, value);
    } else {
        strcpy(tree->value, value);
    }
    return tree;
}

void insert(BST *bst, const int key, char *value) {
    if (bst != NULL) {
        bst->root = insertNode(bst->root, key, value);
    }
}

node* deleteNode(node* tree, const int key) {
    if (tree == NULL) {
        printf("tree is empty\n");
        return NULL;
    }
    if(key < tree -> key) {
        tree -> left = deleteNode(tree -> left, key);
    } else if(key > tree -> key) {
        tree -> right = deleteNode(tree -> right, key);
    } else {
        if(tree -> left == NULL && tree -> right == NULL) {
            free(tree);
            tree = NULL;
        } else if(tree -> left == NULL || tree -> right == NULL) {
            node *temp;
            if(tree -> left == NULL) {
                temp = tree -> right;
            } else {
                temp = tree -> left;
            }
            *tree = *temp;
            free(temp);
        } else {
            node *temp = tree -> left;
            while(temp -> right != NULL) {
                temp = temp -> right;
            }
            tree -> key = temp -> key;
            strcpy(tree -> value, temp -> value);
            tree -> left = deleteNode(tree -> left, temp -> key);
        }
    }
    return tree;
}

void delete(BST *bst, const int key) {
    if (bst != NULL) {
        bst->root = deleteNode(bst->root, key);
    }
}

void printOrdered(node* tree) {
    if (tree != NULL) {
        printOrdered(tree->left);
        printf("key: %d value: %s\n", tree->key, tree->value);
        printOrdered(tree->right);
    }
}

void display(const BST* tree) {
    if (tree == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printOrdered(tree->root);
}

int main() {
    BST *tree = newBST();
    insert(tree, 1, "hello");
    insert(tree, 2, "world");
    insert(tree, 3, "hello");
    insert(tree, 4, "hello");
    insert(tree, 5, "hello");
    delete(tree, 4);
    display(tree);
    free(tree);
    return 0;
}