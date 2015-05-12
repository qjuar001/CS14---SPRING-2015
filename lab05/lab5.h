//Course: CS 14 Spring 2015
//
//First name: <Queston>
//Last name: <Juarez>
//Course username: <qjuar001>
//Email address: <qjuar001@ucr.edu>
//
//Lecture section: <002>
//Lab section: <23>
//TA:<Dingwen>
//
//Lab:<05>
//=================================================================

#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
#define nil 0

bool temp = false;

// #define Value int // restore for testing.
template < typename Value >
class BST 
{
    class Node 
    { // binary tree node
        public:
            Node* left;
            Node* right;
            Value value;
            bool selected = false;
            
            Node( const Value v = Value() )
            : left(nil), right(nil), value(v)
            { }
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            
            int traverse(Node* n) //Helper to traverse the node and get size.
            {
                if(n == nil) return 0;
                int counter = 0;
                counter++;
                if(isLeaf())
                {
                    return counter;
                }
                
                return counter+= traverse(n->left) + traverse(n->right);
                
            }
            int helpHeight(Node* n)//Helper for height function
            {
                
                if(!n) return 0;
                int leftHeight = helpHeight(n->left);
                int rightHeight = helpHeight(n->right);
                return (leftHeight > rightHeight) ? leftHeight+1 :rightHeight+1;
            }
            int height() 
            {
                // returns the height of the subtree rooted at this node
                // FILL IN
                return helpHeight(this);
            }
            int size() 
            {
                // returns the size of the subtree rooted at this node,
                return traverse(this);
            }

    }; // Node

    // const Node* nil; // later nil will point to a sentinel node.
    Node* root;
    int count;
    int coverCount = 0;
    public:
    
    BST() : root(nil) {count = 0;}
    
    int traverse(Node* n) //Helper to traverse the node and get size.
    {
        if(n == nil) return 0;
        int counter = 0;
        counter++;
        if(n->isLeaf())
        {
            return counter;
        }
        
        return counter+= traverse(n->left) + traverse(n->right);
        
    }
            
    int size() 
    {
        // size of the overall tree.
        count = traverse(root);
        return count;
    }
    
    bool empty() { return size() == 0; }
    
    void print_node( const Node* n ) 
    {
        // Print the node’s value.
        cout << n->value << endl;
    }
    
    bool searchHelp(const Node* n, Value x)//helper for the search function
    {
        if(n == nil) return false;
        if(n->value == x)
        {
            return true;
        }
        if(n->right == nil && n->left == nil)
        {
            return false;
        }
        return  (searchHelp(n->left, x) || searchHelp(n->right, x));
    }
    
    bool search ( Value x ) 
    {
        // search for a Value in the BST and return true iff it was found.
        return searchHelp(root, x);
    }
    
    void helpPreorder(Node* n)const
    {
        if(n)
        {
            cout << n->content() << endl;
            helpPreorder(n->left);
            helpPreorder(n->right);
        }
    }
    void preorder()const 
    {
        // Traverse and print the tree one Value per line in preorder.
        // FILL IN
        helpPreorder(root);
    }
    
    void helpPostorder(Node* n)const
    {
        if(n)
        {
            helpPreorder(n->left);
            helpPreorder(n->right);
            cout << n->content() << endl;
        }
    }
    
    void postorder()const 
    {
        // Traverse and print the tree one Value per line in postorder.
        // FILL IN
        helpPostorder(root);
    }
    
    void helpInorder(Node* n)const
    {
        if(n)
        {
            helpPreorder(n->left);
            cout << n->content() << endl;
            helpPreorder(n->right);
        }
    }    
    
    void inorder()const 
    {
        // Traverse and print the tree one Value per line in inorder.
        // FILL IN
        helpInorder(root);
    }
    
    void helpOperator(Node* n, list<Node*>& temp, int x)
    {
        if(n)
        {
            temp.push_back(n);
            helpOperator(n->left,temp, x--);
            helpOperator(n->right,temp, x--);
        }
    }
    
    Value& operator[] (int n) 
    {
        // returns reference to the value field of the n-th Node.
        list<Node*> temp;
        helpOperator(root, temp, n);
        for(int i = 0; i < n; i++)
        {
            temp.pop_front();
        }
        Value* curr = &(temp.front()->value);
        return *curr;
    }
    
    void insert( Value X ) { root = insert( X, root ); }
    
    Node* insert( Value X, Node* T ) 
    {
        // The normal binary-tree insertion procedure ...
        if ( T == nil ) 
        {
            T = new Node( X ); // the only place that T gets updated.
        }
        else if ( X < T->value ) 
        {
            T->left = insert( X, T->left );
        } 
        else if ( X > T->value ) 
        {
            T->right = insert( X, T->right );
        }
        else 
        {
            T->value = X;
        }
        // later, rebalancing code will be installed here
        return T;
    }
    
    void remove( Value X ) { root = remove( X, root ); }
    
    Node* remove( Value X, Node*& T )  
    {
        // The normal binary-tree removal procedure ...
        // Weiss’s code is faster but way more intricate.
        if ( T != nil ) 
        {
            if ( X > T->value ) 
            {
                T->right = remove( X, T->right );
            } 
            else if ( X < T->value ) 
            {
                T->left = remove( X, T->left );
            } 
            else
            { // X == T->value
                if ( T->right != nil ) 
                {
                    Node* x = T->right;
                    while ( x->left != nil ) x = x->left;
                    T->value = x->value; // successor’s value
                    T->right = remove( T->value, T->right );
                } 
                else if ( T->left != nil ) 
                {
                    Node* x = T->left;
                    while ( x->right != nil ) x = x->right;
                    T->value = x->value; // predecessor’s value
                    T->left = remove( T->value, T->left );
                }
                else
                { // *T is external
                    delete T;
                    T = nil; // the only updating of T
                }
            }
        }
        // later, rebalancing code will be installed here
        return T;
    }
    
    //__________________________________________________________________________
    //Lab 5 functions are declared below this line.
    
    //Finds the smallest cover of tree thats not part of root.
    void minCover()
    {
        minCoverHelp(root->left); // Call on the left side
        minCoverHelp(root->right);// Call on right side.
    }
    
    //Helper function that helps determine the smallest cover.
    void minCoverHelp(Node* curr)
    {
        if(curr == nil) return; // If NULL then returns
        minCoverHelp(curr->left);//Moves Node to the left.
        if(!curr->isLeaf())//If the node is not a leaf then select it
        {                   // and increase coverCount.
            curr->selected = true;
            coverCount++;
        }
        minCoverHelp(curr->right);// Move node to the right.
    }
    
    // Displays the cover in-order.
    void displayMinCover()
    {
        displayMinCoverHelp(root); // Calls helper function.
        cout << endl;
        cout << coverCount << endl;// Outputs total amount.
    }
    
    //Helper function that outputs in-order
    void displayMinCoverHelp(Node* n)
    {
        if(n)
        {
            displayMinCoverHelp(n->left);
            if(n->selected == true)// If selected is true then print.
            {
                cout << n->content() << " ";
            }
            displayMinCoverHelp(n->right);
        }
    }
    
    //Determines if a path can add up to number entered in.
    void findSumPath(int sum)
    {
        temp = false;
        int arr[1000];//Allocates array of size 1000.
        findSumPath(root, sum, arr); //Calls helper
        if(temp == false)//If Sum was not found then print 0.
            cout << 0;
        cout << endl;
    }
    
    void findSumPath(Node* n, int sum, int buffer[])
    {
        int tempSum = 0;
        static int iterations = 0;// Keeps track of position in array.
        if(n)
        {
            buffer[iterations] = n->value;// Assigns node value into array.
            iterations++;// increases the position.
            findSumPath(n->left, sum, buffer);// moves node to the left.
            for(int i = 0; i < iterations; i++)
            {
                tempSum += buffer[i]; //Determines the sum of nodes in array.
            }
            if(tempSum == sum)// If equal then print
            {
                temp = true;
                for(int i = iterations-1; i >= 0; i--)
                {
                    cout << buffer[i] << " ";
                }
            }
            tempSum = 0; // Reset sum of array.
            findSumPath(n->right, sum, buffer); //Moce node to the right
            iterations--;// Take away position when returning from recursion.
        }
    }
    
    //Determines the sum of all vertically aligned nodes.
    void vertSum()
    {
        if(root == nil)//If root is node then return 0 and return.
        {
            cout << 0 << endl;
            return;
        }
        map<int, int> tempMap; //Create a map to hold values.
        
        vertSum(root, 0, tempMap); //Call helper function.
        
        //Iterates through the map and prints out the sums.
        for(auto it = tempMap.begin(); it != tempMap.end(); it++)
        {
            cout << it->second << " ";
        }
        cout << endl;
    }
    

    void vertSum(Node* node, int hd, std::map<int, int>&m)
    {
        if(node==nil)//If node is 0 then return.
    	return;
    	m[hd]+=node->value; //Takes node value and adds it to hd
    	vertSum(node->left,hd-1,m);//moves node to left and subtracts 1 from hd.
    	vertSum(node->right,hd+1,m);//moves node to right and adds 1 to hd.
    }
    
}; // BST

#endif
