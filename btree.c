#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_DEGREE 2


struct BTreeNode {
    bool leaf;
    int n;
    int keys[2 * MIN_DEGREE - 1];
    struct BTreeNode *child[2 * MIN_DEGREE];
};


struct BTreeNode *createNode(bool leaf) {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->leaf = leaf;
    newNode->n = 0;
    return newNode;
}


void insertNode(struct BTreeNode *node, int key) {
    int i = node->n;

    if (node->leaf) {
        while (i > 0 && key < node->keys[i - 1]) {
            node->keys[i] = node->keys[i - 1];
            i--;
        }
        node->keys[i] = key;
        node->n++;
    } else {
        while (i > 0 && key < node->keys[i - 1])
            i--;

        if (node->child[i]->n == (2 * MIN_DEGREE - 1)) {
            splitChild(node, i, node->child[i]);
            if (key > node->keys[i])
                i++;
        }
        insertNode(node->child[i], key);
    }
}


void splitChild(struct BTreeNode *parent, int index, struct BTreeNode *child) {
    struct BTreeNode *newNode = createNode(child->leaf);
    newNode->n = MIN_DEGREE - 1;

    for (int i = 0; i < MIN_DEGREE - 1; i++)
        newNode->keys[i] = child->keys[i + MIN_DEGREE];

    if (!child->leaf) {
        for (int i = 0; i < MIN_DEGREE; i++)
            newNode->child[i] = child->child[i + MIN_DEGREE];
    }

    child->n = MIN_DEGREE - 1;

    for (int i = parent->n; i > index; i--) {
        parent->child[i + 1] = parent->child[i];
        parent->keys[i] = parent->keys[i - 1];
    }

    parent->child[index + 1] = newNode;
    parent->keys[index] = child->keys[MIN_DEGREE - 1];
    parent->n++;
}


struct BTreeNode *createAndInsert(int keys[], int n) {
    struct BTreeNode *root = createNode(true);

    for (int i = 0; i < n; i++)
        insertNode(root, keys[i]);

    return root;
}


void inOrderTraversal(struct BTreeNode *root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf)
                inOrderTraversal(root->child[i]);
            printf("%c ", root->keys[i]);
        }
        if (!root->leaf)
            inOrderTraversal(root->child[i]);
    }
}

int main() {
    int keys[] = {'F', 'S', 'Q', 'K', 'C', 'L', 'H', 'T', 'V', 'W', 'M', 'R', 'N', 'P', 'A', 'B', 'X', 'Y', 'D', 'Z', 'E'};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct BTreeNode *root = createAndInsert(keys, n);

    printf("In-order traversal of the B-tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}

