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

#include <iostream>
#include "lab5.h"

using namespace std;

int main()
{
    //Create list and add values
    BST<int> test1;
    test1.insert(50);
    test1.insert(60);
    test1.insert(20);
    test1.insert(70);
    test1.insert(10);
    test1.insert(40);
    test1.insert(35);
    test1.insert(45);
    
    cout << "Part 1" << endl;
    test1.minCover();
    test1.displayMinCover();
    cout << "Part 2" << endl;
    test1.findSumPath(80);
    test1.findSumPath(145);
    test1.findSumPath(200);
    cout << "Part 3" << endl;
    test1.vertSum();
    
    return 0;
}