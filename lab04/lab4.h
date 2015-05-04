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
#include <vector>
#include <algorithm>

using namespace std;

struct numbers
{
    int m;
    int n;
};

//prioriy queue given by lab instructor
typedef pair<int,int> Entry;
class priority_queue 
{
    public:
        vector<Entry> entries;
        vector<int> sum;
        Entry& front() { return entries.back(); }
        void push( Entry e )
        {
            entries.push_back( e );//pushes a pair entry into the vector.
            for ( int i = entries.size()-1; i != 0; --i ) //
            {
                //Compares the sum of the two entries to see which is less.
                if ( entries[i].first + entries[i].second < 
                entries[i-1].first + entries[i-1].second ) break;
                swap(entries[i], entries[i-1]);
            }
        }
        // Print function that prints out the elements in queue in reverse.
        void print() const
        {
            //Starts from the end of the vector and prints to the front.
            for(unsigned i = entries.size()-1; i >= 0 ; i--)
            {
                cout << entries.at(i).first << " " << entries.at(i).second;
                cout << endl;
                if(i == 0) break;//Keepes from going out of bounds.
            }
        }
};

//Creates a tree and prints out the elements bounded by k in preOrder
void preOrder(int m, int n, list<numbers> &list, int k)
{
    numbers temp;
    temp.m = m;
    temp.n = n;
    if(m + n < k)
    {
        list.push_back(temp);
    }
    if(m + n >= k)
        return;
    preOrder(((2*m)-n),m,list,k);//Given algorithms
    preOrder(((2*m)+n),m,list,k);
    preOrder((m+(2*n)),n,list,k);
}

//Creates a tree and prints out the elements bounded by k in postOrder
void postOrder(int m, int n, list<numbers> &list, int k)
{
    numbers temp;
    temp.m = m;
    temp.n = n;
    if(m + n >= k)
    {
        // if(m + n <= k)
        // {
        //     list.push_back(temp);
        // }
        return;
    }
    postOrder(((2*m)-n),m,list,k);
    postOrder(((2*m)+n),m,list,k);
    postOrder((m+(2*n)),n,list,k);
    if(m+n < k)
    {
        list.push_back(temp);
    }
}

//Creates a pair and pushes it into a queue then prints out the queue in reverse
void inOrder(list<numbers> &List)
{
    Entry temp;
    priority_queue Q;
    list<numbers>::iterator i = List.begin();
    for(i = List.begin(); i != List.end(); i++)
    {
        temp.first = (*i).m; //Copy list into Entry then push into queue.
        temp.second = (*i).n;
        Q.push(temp);
    }
    Q.print();
}

//Helper print function that prints out the "tree"
void print(list<numbers> lst, const int k)
{
    list<numbers>::iterator i = lst.begin();
    for(i = lst.begin(); i != lst.end(); i++)
    {
        cout << (*i).m << " " << (*i).n << endl;
    }
}