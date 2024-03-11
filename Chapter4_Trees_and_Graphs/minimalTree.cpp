#include <iostream>
#include <vector>

using namespace std;

class BinaryTree
{
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    void insertMiddleElements(TreeNode *&nodeptr, vector<int> &arr, int start, int end)
    {
        if (start > end)
            return;

        int middle = (start + end) / 2;

        TreeNode *newNode = new TreeNode;
        newNode->val = arr[middle];
        newNode->left = nullptr;
        newNode->right = nullptr;

        nodeptr = newNode;
        insertMiddleElements(newNode->left, arr, start, middle - 1);
        insertMiddleElements(newNode->right, arr, middle + 1, end);
    }

    void displayNode(TreeNode *nodeptr)
    {
        if (nodeptr)
        {
            displayNode(nodeptr->left);
            
            displayNode(nodeptr->right);
            cout << nodeptr->val << " ";
        }
    }

public:
    BinaryTree(){
        root = nullptr;
    }


    void createMinimalTree(vector<int> &arr)
    {
        insertMiddleElements(root, arr, 0, arr.size() - 1);
    }

    void display()
    {
        displayNode(root);
    }
};

int main()
{
    BinaryTree tree;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    tree.createMinimalTree(arr);
    tree.display();
    cout << endl;
}