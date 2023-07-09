//bst 
#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};

struct BST* createNode(int value) {
    struct BST* newNode = (struct BST*)malloc(sizeof(struct BST));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BST* Insert(struct BST* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value > root->data) {
        root->right = Insert(root->right, value);
    } else if (value <= root->data) {
        root->left = Insert(root->left, value);
    }
    return root;
}

void Inorder(struct BST* root) {
    if (root == NULL) {
        return;
    }
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void search(struct BST* root, int key) {
    if (root == NULL) {
        printf("Value not found\n");
        return;
    } else if (root->data == key) {
        printf("Value found\n");
        return;
    }
    if (root->data < key) {
        search(root->right, key);
    } else {
        search(root->left, key);
    }
}
int height(struct BST* node) {
    if (node == NULL) {
        return 0;
    } else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight) {
            return (lheight + 1);
        } else {
            return (rheight + 1);
        }
    }
}
struct BST* minElement(struct BST* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    } else {
        return minElement(root->left);
    }
}

struct BST* maxElement(struct BST* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    } else {
        return maxElement(root->right);
    }
}

struct BST* deleteNode(struct BST* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct BST* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct BST* temp = root->left;
            free(root);
            return temp;
        }
        
        struct BST* temp = minElement(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct BST* b = createNode(50);
    struct BST* root = NULL;

    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);

    Inorder(root);
    printf("\n");

    search(root, 63);

    int x = height(root);
    printf("Height = %d\n", x);

    struct BST* minNode = minElement(root);
    printf("Min value = %d\n", minNode->data);

    struct BST* maxNode = maxElement(root);
    printf("Max value = %d\n", maxNode->data);

    root = deleteNode(root, 80);
    Inorder(root);
    printf("\n");

    return 0;
}
