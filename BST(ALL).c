#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node*, int);
struct Node* search(struct Node*, int);
struct Node* Delete (struct Node*, int);
int main()
{
    int n, key;
    struct Node *root = NULL;
    int choice, count = 1;
    printf("1. Insert Operation\n");
    printf("2. Search Operation\n");
    printf("3. Pre-order Traversal Operation\n");
    printf("4. In-order Traversal Operation\n");
    printf("5. Post-order Traversal Operation\n");
    printf("6. Deletion Operation\n");
    printf("7. Smallest Element Searching Operation\n");
    printf("8. Largest Element Searching Operation\n");
    printf("9. Exit\n");

    while(count==1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter elements: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &key);
                root = insert(root, key);
            }
            break;

        case 2:
            printf("\nEnter key to search: ");
            scanf("%d", &key);
            if (search(root, key))
                printf("\nKey found in the tree.\n");
            else
                printf("\nKey not found in the tree.\n");
            break;

        case 3:
            printf("\nPre-order Traversal: ");
            preOrderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("\nIn-order Traversal: ");
            inOrderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf("\nPost-order Traversal: ");
            postOrderTraversal(root);
            printf("\n");
            break;

        case 6:
            printf("\nEnter key to delete: ");
            scanf("%d", &key);
            root = Delete(root, key);
            break;

        case 7:
            printf("Largest element in BST: %d",searchmax(root));
            break;

        case 8:
            printf("Smallest element in BST: %d",searchmin(root));
            break;

        case 9:
            printf("The program is ended!!",count++);
            break;
        default:
            printf("Error!! The option is not found!!\n\n");
        }
    }
    return 0;
}

// Function to create a new node
struct Node* createNode(int key)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key
struct Node* insert(struct Node* root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Function to search for a key in BST
struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Function to perform pre-order traversal
void preOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform in-order traversal
void inOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal
void postOrderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to search largest element
int searchmax(struct Node* root)
{
// Base Cases: right subtree is null
    while (root->right != NULL)
        root = root->right;
    return root->data;

}

// Function to search smallest element returns -> the value
int searchmin(struct Node* root)
{
// Base Cases: left subtree is null
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Function to search largest element returns -> the root
struct Node* findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct Node* Delete (struct Node * root, int data)
{
    if(root == NULL)
    {
        printf("\nKey %d is not in the tree ",data);
        return root;
    }
    if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    else
    {
        // case 1: no child
        if (root ->left == NULL && root->right == NULL)
        {
            printf("\nKey %d has been deleted successfully ",root->data);
            free(root);
            root = NULL;
            return root;
        }

        // case 2: one child
        else if (root ->left == NULL )
        {
            struct Node *temp = root;
            root = root->right;
            printf("\nKey %d has been deleted successfully ",temp->data);
            free(temp);
            return root;
        }
        else if (root ->right == NULL )
        {
            struct Node *temp = root;
            root = root->left;
            printf("\nKey %d has been deleted successfully ",temp->data);
            free(temp);
            return root;
        }
        else if(root ->left != NULL && root ->right != NULL)
        {
            // case 3: two children -> left subtree
            printf("\nKey %d has been deleted successfully ",root->data);
            struct Node *temp = findMax(root->left);
            root->data = temp->data;
            root->left = Delete (root->left, temp->data);
            return root;
        }
    }

        return root;
}
<!DOCTYPE html>
<html>
<body>
<h2>Project Done by &copy; Nushrat Jaben Aurnima. All Rights Reserved .</h2>
</body>
</html>

