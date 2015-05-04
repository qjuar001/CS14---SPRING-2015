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
//lab:<04>
//
//I hereby certify that the code in this file
//is ENTIRELY my own original work.
//=================================================================

#include <iostream>
#include <list>
#include <stdlib.h>
#include "lab4.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Usage: ./a.out intNumber" << endl;
        exit(-1);
    }
    int k = strtol(argv[1], NULL, 0);
    
    //Create a list of Struct numbers.
    list<numbers> test1;
    
    //Call preorder to create a tree starting with 2,1
    preOrder(2, 1, test1, k);
    //Call preorder to create a tree with another node starting at 3,1
    preOrder(3, 1, test1, k);
    cout << "pre-order" << endl;
    print(test1,k);
    
    //Create a second list of type numbers
    list<numbers> test2;
    
    //call postOrder on second list with 1,2
    postOrder(2, 1, test2, k);
    
    //call postorder on second list with 3,1
    postOrder(3, 1, test2, k);
    cout << "post-order" << endl;
    print(test2,k);
    cout << "in-order" << endl;
    //print out the first list in order.
    inOrder(test1);
    
    return 0;
}