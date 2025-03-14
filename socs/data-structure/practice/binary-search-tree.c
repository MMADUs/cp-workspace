#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node {
    int key;
    char value[50];
    struct tree_node *left;
    struct tree_node *right;
} node;

typedef struct binary_search_tree {
    node *root;
} BST;

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

node *insertNode(node *root, const int key, char *value) {
    if (root == NULL) {
        return newNode(key, value);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key, value);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, value);
    } else {
        strcpy(root->value, value);
    }
    return root;
}

void push(BST *tree, const int key, char *value) {
    if (tree != NULL) {
        tree->root = insertNode(tree->root, key, value);
    }
}

node *successor(const node *root) {
    node *curr = root->right;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

node *predecessor(const node *root) {
    node *curr = root->left;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr;
}

node* deleteNode(node* root, const int key) {
    if (root == NULL) {
        printf("root is empty\n");
        return NULL;
    }
    if(key < root -> key) {
        root -> left = deleteNode(root -> left, key);
    } else if(key > root -> key) {
        root -> right = deleteNode(root -> right, key);
    } else {
        if(root -> left == NULL && root -> right == NULL) {
            free(root);
            root = NULL;
        } else if(root -> left == NULL || root -> right == NULL) {
            node *temp;
            if(root -> left == NULL) {
                temp = root -> right;
            } else {
                temp = root -> left;
            }
            *root = *temp;
            free(temp);
        } else {
            // const node *curr = successor(root);
            const node *curr = predecessor(root);
            root -> key = curr -> key;
            strcpy(root -> value, curr -> value);
            root -> left = deleteNode(root -> left, curr -> key);
        }
    }
    return root;
}

void pop(BST *tree, const int key) {
    if (tree != NULL) {
        tree->root = deleteNode(tree->root, key);
    }
}

void prefix(node* root) {
    if (root != NULL) {
        printf("key: %d value: %s\n", root->key, root->value);
        prefix(root->left);
        prefix(root->right);
    }
}

void infix(node* root) {
    if (root != NULL) {
        infix(root->left);
        printf("key: %d value: %s\n", root->key, root->value);
        infix(root->right);
    }
}

void postfix(node* root) {
    if (root != NULL) {
        postfix(root->left);
        postfix(root->right);
        printf("key: %d value: %s\n", root->key, root->value);
    }
}

int main() {
    BST *tree = newBST();
    push(tree, 1, "hello");
    push(tree, 2, "world");
    push(tree, 3, "hello");
    push(tree, 4, "hello");
    push(tree, 5, "hello");
    pop(tree, 4);
    infix(tree->root);
    free(tree);
    return 0;
}