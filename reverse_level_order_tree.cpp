#include <iostream>


// C++ implementation to print odd number from bottom right
#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree Node has data, pointer 
   to left child and a pointer to right 
   child */
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct Node* newNode(int data) 
{ 
    struct Node* node = new Node(); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 
  
// Funtion to print odd numbers from bottom right   
// function takes root node as input 
void printNodeFromBottomRight(Node *root) 
{ 
    if (root != NULL)
    {
        queue<Node *> q; 
        q.push(root); 

        stack<Node*> s;
        s.push(root);
    
        // Current level 
        int level = 0; 
    
        // Maximum Nodes at same level 
        int max = INT_MIN; 
    
    
        while (1) 
        { 
            // Count Nodes in a level 
            int NodeCount = q.size(); 
    
            if (NodeCount == 0) 
                break; 
    
            // Pop complete current level 
            while (NodeCount > 0) 
            { 
                Node *Node = q.front(); 
                q.pop(); 
                if (Node->left != NULL) 
                {
                    q.push(Node->left);
                    s.push(Node->left);
                }
                    
                if (Node->right != NULL) 
                {
                    q.push(Node->right); 
                    s.push(Node->right);
                }
                NodeCount--;
                if(NodeCount == 0)
                {
                    s.push(NULL);

                } 
            } 
    
            // Increment for next level 
            level++; 
        } 

        int count = 2;

        while(!s.empty())
        {
            Node* val = s.top();
            s.pop();
            if(val)
            {
                if(count % 2 == 0)
                {
                    cout << val->data;
                
                }
                count++;
            }
            else
            {
                count = 2;
            }
        }
    } 
} 
  
// Driver program to test above 
int main() 
{ 
    cout << "Test case 1: " << endl;
    // binary tree formation 
    struct Node *root = newNode(2);      /*        2      */
    root->left        = newNode(1);      /*      /   \    */
    root->right       = newNode(3);      /*     1     3      */
    root->left->left  = newNode(4);      /*   /   \    \  */
    root->left->right = newNode(6);      /*  4     6    8 */
    root->right->right  = newNode(8);    /*       /       */
    root->left->right->left = newNode(5);/*      5        */
  
    printNodeFromBottomRight(root);

    cout << endl << endl;

    cout << "Test case 2: "<< endl;

    root = newNode(1);                      /*      1       */
    root->left = newNode(2);                /*    /    \       */
    root->right = newNode(3);               /*   2      3       */
    root->left->left = newNode(4);          /*  / \             */
    root->left->right = newNode(5);         /* 4   5             */

    printNodeFromBottomRight(root);

    return 0; 
} 