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
#include <utility>

using namespace std;

//The proof for the second part is down below this function.
template<typename L>
void selectionsort(L &l)
{
    int numswaps = 0;
    //Check to see if the container entered is empty.
    if(l.begin() == l.end())
    {
        cout << "Error: Container is Empty" << endl;
        return;
    }
    
    //Create a bool to help prevent unneccessary swaps
    bool swapNeeded = false;
    
    //Create three iterators to help traverse and sort the container.
    typename L::iterator i = l.begin();
    typename L::iterator j;
    typename L::iterator min = i;
    
    //First loop that holds the min value
    for(i = l.begin(); i != l.end(); i++)
    {
        swapNeeded = false;
        min = i;
        //Second loop compares each element to find the minimum.
        for(j = i; j != l.end(); j++)
        {
            if(*j < *min)
            {
                min = j;
                swapNeeded = true;
            }
        }
        //If i is the smallest element then don't swap.
        if(swapNeeded)
        {
            swap(*i,*min);
            numswaps+=3;
        }
    }
    cout << "0 copies and " << numswaps << " moves." << endl;
}

//No the algorithim is not stable.

// Suppose the array is
// 5 2 3  8 4 5 6 
// Let's distinguish the two 5's as 5(a) and 5(b) .

// So our array is:
// 5(a)  3 4  5(b) 2 6 8 

// After iteration 1:
// 2 will be swapped with the element in 1st position:

// So our array becomes:
// 2 3 4 5(b) 5(a) 6 8

// Since now our array is in sorted order and we clearly see that 5(a) comes 
// before 5(b) in initial array but not in the sorted array.

// So we can clearly see that selection sort is not stable.

// The below algorithim shows the proof with the last output in my main function
//The function only compares the first element of the pairs and ignores
//the second elements in order to visually see the defect.

void selectionsortProof(list<pair<int, char> > &l)
{
    //Check to see if the container entered is empty.
    if(l.begin() == l.end())
    {
        cout << "Error: Container is Empty" << endl;
        return;
    }
    
    //Create a bool to help prevent unneccessary swaps
    bool swapNeeded = false;
    
    //Create three iterators to help traverse and sort the container.
    typename list<pair<int, char> >::iterator i = l.begin();
    typename list<pair<int, char> >::iterator j;
    typename list<pair<int, char> >::iterator min = i;
    
    //First loop that holds the min value
    for(i = l.begin(); i != l.end(); i++)
    {
        swapNeeded = false;
        min = i;
        //Second loop compares each element to find the minimum.
        for(j = i; j != l.end(); j++)
        {
            if(j->first < min->first)
            {
                min = j;
                swapNeeded = true;
            }
        }
        //If i is the smallest element then don't swap.
        if(swapNeeded)
            swap(*i,*min);
    }
}