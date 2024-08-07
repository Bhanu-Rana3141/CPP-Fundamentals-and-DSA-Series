#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

//  TC - O(N) && SC - O(N)

void createMapping(vector<int>& inorder, int n, map<int,int>& elementToIndex) {

    for(int i=0; i<n; i++) {
        elementToIndex[inorder[i]] = i;
    }
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int n, int& index, int inorderStart, int inorderEnd, map<int,int>& elementToindex) {

    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = preorder[index];
    index++;
    Node* root = new Node(element);
    int position = elementToindex[element];

    root -> left = buildTree(preorder, inorder, n, index, inorderStart, position - 1, elementToindex);
    root -> right = buildTree(preorder, inorder, n, index, position + 1, inorderEnd, elementToindex);

    return root;
}

void preorderTraversal(Node* root) {

    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int preOrderIndex = 0;
    int n = inorder.size();
    int inorderStart = 0;
    int inorderEnd = n-1;   

    map<int, int> elementToindex;
    createMapping(inorder, n, elementToindex);

    Node* root = buildTree(preorder, inorder, n, preOrderIndex, inorderStart, inorderEnd, elementToindex);

    preorderTraversal(root);
    
    return 0;
}