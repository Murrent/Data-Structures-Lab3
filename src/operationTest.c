// Martin Vickgren, Samson Tesfalem

#include <stdio.h>
#include "binarytree/binarytree.h"
#include "load_files/load_file.h"

int main(int argc, char *argv[]) {
    const char *fName = argv[1];

    int *a = load_file(fName);

    int size = a[0];
    Tree *tree = createTree();
    for (int i = 1; i <= size; i++) {
        insert(tree, createNode(a[i]));
    }
    printf("Tree in order:\n");
    printInOrder(tree->root);

    printf("\n");
    printf("Predecessor to 44 %d\n",
           predecessor(search(tree->root, 44)) ? predecessor(search(tree->root, 44))->key : 0);
    printf("Successor to 44 %d\n", successor(search(tree->root, 44)) ? successor(search(tree->root, 44))->key : 0);

    printf("\nBefore deleting predecessor and successor of 44: \n");
    printf("Depth: %d\n", treeDepth(tree));
    printf("Size: %d\n", treeSize(tree));

    delete(tree, predecessor(search(tree->root, 44)));
    delete(tree, successor(search(tree->root, 44)));

    printf("\nAfter deleteing predecessor and successor of 44:\n");
    printf("Predecessor to 44 %d\n",
           predecessor(search(tree->root, 44)) ? predecessor(search(tree->root, 44))->key : 0);
    printf("Successor to 44 %d\n\n", successor(search(tree->root, 44)) ? successor(search(tree->root, 44))->key : 0);

    printf("Tree in order:\n");
    printInOrder(tree->root);
    printf("Depth: %d\n", treeDepth(tree));
    printf("Size: %d\n", treeSize(tree));

    deleteTree(tree);
    return 0;
}
