#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    int count;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if(value==root->value){
    	root->count;
    
    	return root;
    	
	}
 

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    } else {
        root->count++;
    }

    return root;
}

struct Node* findMax(struct Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return findMax(root->right);
}

struct Node* deleteMax(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->right == NULL) {
        struct Node* leftSubtree = root->left;
        free(root);
        return leftSubtree;
    }

    root->right = deleteMax(root->right);
    return root;
}

int size(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->count+ size(root->left) + size(root->right);
}

void printInOrder(struct Node* root) {
	int i;
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    for ( i = 0; i < root->count; i++) {
        printf("%d ", root->value);
    }
    printInOrder(root->right);
}

int main() {
    int N,i, Q;
    scanf("%d", &N);

    struct Node* root = NULL;

    for ( i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d", &Q);

    for (i = 0; i < Q; i++) {
        int val;
        
		
        scanf("%d", &val);

        struct Node* maxNode = findMax(root);

        if (size(root)==0||val > maxNode->value ||val< maxNode->value) {
        	
			
		
		
	
		
        
        	
            root = insert(root, val);
        
        
        }

        printf("%d\n", size(root));
    }

    printInOrder(root);
    printf("\n");

    // Free allocated memory
    // Not shown in this simplified code

    return 0;
}

