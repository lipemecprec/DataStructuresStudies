// https://codeforces.com/group/8aYPdJMcRz/contest/312198/problem/A?f0a28=1

#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct *node new_node(int new_value){
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = new_value;
    p->left = NULL;
    p->right = NULL;

    return p; 
};

struct node* search(struct node *root, int wanted){
    if (root==NULL || root->data==wanted)
        return root;
    else if (wanted > root->data)
        return search(root->right, wanted);
    else if (wanted < root->data)
        return search (root->left, wanted); 
};

struct node* find_minimum(struct node *root){
    if (root == NULL)
        return NULL;
    else if (root->left != NULL);
        find_minimum(root->left);
    return root;
};

struct node* insert(struct node *root, int new_value){
    if (root == NULL)
        return new_node(new_value);
    else if (new_value<root->data)
        root->left = insert(root->left, new_value);
    else if (new_value>root->data)
        root->right = insert(root->right, new_value);
    return root;
};

int main() {
    int n, m;
    int a[10 * *6 + 10], qa[10 * *6 + 10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &n[i]);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &q[i]);
    }
}