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
//Lab:<06>
//================================================================

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include "selectionsort.h"

using namespace std;

int main()
{
     //list 
    cout << "test of selectionsort() on list" << endl;
    list<int> l{-1,100,64,11,0,1};
    cout << "pre: ";
    for(list<int>::iterator lit = l.begin(); lit != l.end(); ++lit){
        cout << *lit << " ";
    }
    cout << endl;
    selectionsort(l);
    cout << "post: ";
    for(list<int>::iterator lit = l.begin(); lit != l.end(); ++lit){
        cout << *lit << " ";
    }
    cout << endl << endl;
    
    //vector
    cout << "test of selectionsort() on vector" << endl;
    vector<int> v;
    v.push_back(-1);
    v.push_back(100);
    v.push_back(64);
    v.push_back(11);
    v.push_back(0);
    v.push_back(1);
    cout << "pre: ";
    for(unsigned int i = 0; i < v.size(); ++i){
        cout << v.at(i) << " ";
    }
    cout << endl;
    selectionsort(v);
    cout << "post: ";
    for(unsigned int i = 0; i < v.size(); ++i){
        cout << v.at(i) << " ";
    }
    cout << endl << endl;
    
    //deque
    cout << "test of selectionsort() on deque" << endl;
    deque<int> d;
    d.push_back(-1);
    d.push_back(100);
    d.push_back(64);
    d.push_back(11);
    d.push_back(0);
    d.push_back(1);
    cout << "pre: ";
    for(deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit){
        cout << *dit << " ";
    }
    cout << endl;
    selectionsort(d);
    cout << "post: ";
    for(deque<int>::iterator dit = d.begin(); dit != d.end(); ++dit){
        cout << *dit << " ";
    }
    cout << endl << endl;
    
    //vector
    cout << "test of selectionsort() on vector of pairs" << endl;
    vector<pair<int,int>> v2 = {
      {1, 2},
      {3,  -1},
      {-1, 3},
      {0,  0},
      { 2, 3},
      { 1,  2},
      { 1, -2},
      { 8,  10}
    };
    
    cout << "pre: ";
    for(unsigned int i = 0; i < v2.size(); ++i){
        cout << "(" << v2.at(i).first << ", " << v2.at(i).second << ") ";
    }
    cout << endl;
    selectionsort(v2);
    cout << "post: ";
    for(unsigned int i = 0; i < v2.size(); ++i){
        cout << "(" << v2.at(i).first << ", " << v2.at(i).second << ") ";
    }
    cout << endl << endl;
    
     //unordered map
    cout << "test of selectionsort() on vector of unsordered list" << endl;
    list<pair<int, int> > l2 ={
      {10, 2},
      {-3,  -1},
      {-8, 0},
      {1,  1},
      { 1, 1},
      { 0,  0},
      { 10, 2},
      { 5,  5},
      {5, -5},
      {0, 0},
      {10, 2},
    };
    
    cout << "pre: ";
    for(auto it = l2.begin(); it != l2.end(); ++it){
        cout << "(" << it->first << " , " << it->second << ") ";
    }
    cout << endl;
    selectionsort(l2);
    cout << "post: ";
    for(auto it = l2.begin(); it != l2.end(); ++it){
        cout << "(" << it->first << " , " << it->second << ") ";
    }
    cout << endl << endl;
    
    
    cout << "test of selectionsort() on vector of pairs" << endl;
    vector<pair<int,int>> v3 = {
      {-1, 3},
      {0,  0},
      {1, -2},
      {1,  2},
      { 1, 2},
      { 2,  3},
      { 3, -1},
      { 8,  10}
    };
    
    cout << "pre: ";
    for(unsigned int i = 0; i < v3.size(); ++i){
        cout << "(" << v3.at(i).first << ", " << v3.at(i).second << ") ";
    }
    cout << endl;
    selectionsort(v3);
    cout << "post: ";
    for(unsigned int i = 0; i < v3.size(); ++i){
        cout << "(" << v3.at(i).first << ", " << v3.at(i).second << ") ";
    }
    cout << endl << endl;
    
    
    //Test if algorithm is stable
    cout << "test to see if selection sort is stable." << endl;
    list<pair<int, char> > l4 ={
      {5, 'a'},
      {3, 'a'},
      {8,  'a'},
      {4, 'a'},
      {5,  'b'},
      {2, 'a'},
      {6, 'a'},
    };
    
    cout << "pre: ";
    for(auto it = l4.begin(); it != l4.end(); ++it){
        cout << "(" << it->first << " , " << it->second << ") ";
    }
    cout << endl;
    selectionsortProof(l4);
    cout << "post: ";
    for(auto it = l4.begin(); it != l4.end(); ++it){
        cout << "(" << it->first << " , " << it->second << ") ";
    }
    cout << endl;
    cout << "After analyzing the above outputs it becomes clear that the "
    << "algorithm is not stable because the 5's ended up in reverse order."
    << "{5,b} is supposed to come after {5,a}" << endl;
             
    return 0;
}