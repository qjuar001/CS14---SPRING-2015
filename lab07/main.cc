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
//Lab:<07>
//================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <set> //self-balancing tree

//libraries for shuffling vector
#include <random>
#include <algorithm>
#include <iterator>

//library for timing
#include <ctime>

using namespace std;

//function to shuffle vector of strings
template< class RandomIt >
void random_shuffle( RandomIt first, RandomIt last )
{
    typename iterator_traits<RandomIt>::difference_type i, n;
    n = last - first;
    for (i = n-1; i > 0; --i) {
        using std::swap;
        swap(first[i], first[std::rand() % (i+1)]);
    }
}

void readfile(string file, vector<string>& v1)
{
    ifstream inFile;
    inFile.open(file.c_str());
    if(!inFile.is_open())
    {
        cout << "Error: Failed to open " << file << endl;
        exit(1);
    }
    
    string temp;
    while(inFile >> temp)
    {
        v1.push_back(temp);
    }
    inFile.close();
}

void OutPutFile(string file, vector<float> & v1, vector<float>& v2, 
vector<float> &v3, vector<float> &v4)
{
    ofstream OutFile;
    OutFile.open(file.c_str());
    if(!OutFile.is_open())
    {
        cout << "Error: cannot open data.txt" << endl;
        return;
    }
    int num = 5000;
    for(int i = 0; i < 10; i++)
    {
        OutFile << num << " " << v1.at(i)/10 << " " << v2.at(i)/10 << " "
         << v3.at(i)/10 << " " << v4.at(i)/10 << endl;
         num += 5000;
    }
    OutFile.close();
}

int main()
{
    //Read the file into a vector
    string fileName = "words.txt";
    vector<string> v1;
    readfile(fileName, v1);
    
    vector<float> setInsertAvg;
    vector<float> setFindAvg;
    vector<float> uSetInsertAvg;
    vector<float> uSetFindAvg;
    
    setInsertAvg.resize(10, 0);
    setFindAvg.resize(10, 0);
    uSetInsertAvg.resize(10, 0);
    uSetFindAvg.resize(10, 0);
    
    for(int x = 0; x < 10; x++)
    {
        int y = 0;
        //step 1.5 shuffle vector 
        random_device rd;
        mt19937 g(rd());
        shuffle(v1.begin(), v1.end(), g);
        
        //step 2 Now, for a given number n, we can see how long it 
        //takes to insert the first n words into a tree (set)
        set<string> mySet; 
        
        //loop will fill up set multimple times
        for(int i = 5000; i <= 50000; i = i + 5000)
        {
            int setStartTime = clock(); //start time before insert begins
            
            //insert words into set
            for(int j = 0; j < i; ++j)
            {
                mySet.insert(v1.at(j));
            }
            int setEndTime = clock(); //end time after insert ends
            float tempTime = ((float)setEndTime - setStartTime)/CLOCKS_PER_SEC; //total time in seconds
            // setInsertTimes.push_back(tempTime); //gives average time for single insert
            
            setInsertAvg.at(y) += (tempTime/i);
            
            //find in set
            set<string>::iterator it; //temp iterator for use in find()
            setStartTime = clock(); //reset start clock
            for(int j = 0; j < i; ++j)
            {
                it = mySet.find(v1.at(j));
            }
            setEndTime = clock(); //reset end time
            tempTime = ((float)setEndTime - setStartTime)/CLOCKS_PER_SEC; //reset tempTime 
            // setFindTimes.push_back(tempTime/i); //add time to findTimes vector
            mySet.clear(); //clear set for next loop
            
            setFindAvg.at(y) += (tempTime/i);
            y++;
        }
        
        y = 0;
        //step 3 Now do it all for unordered sets 
        unordered_set<string> myUSet; 
        //loop will fill up set multimple times
        for(int i = 5000; i <= 50000; i = i + 5000)
        {
            int uSetStartTime = clock(); //start time before insert begins
            
            //insert words into set
            for(int j = 0; j < i; ++j)
            {
                myUSet.insert(v1.at(j));
            }
            int uSetEndTime = clock(); //end time after insert ends
            float tempTime = ((float)uSetEndTime - uSetStartTime)/CLOCKS_PER_SEC; //total time in seconds
            // uSetInsertTimes.push_back(tempTime/i); //gives average time for single insert
            
            uSetInsertAvg.at(y) += (tempTime/i);
            
            //find in set
            unordered_set<string>::iterator it; //temp iterator for use in find()
            uSetStartTime = clock(); //reset start clock
            for(int j = 0; j < i; ++j)
            {
                it = myUSet.find(v1.at(j));
            }
            uSetEndTime = clock(); //reset end time
            tempTime = ((float)uSetEndTime - uSetStartTime)/CLOCKS_PER_SEC; //reset tempTime 
            // uSetFindTimes.push_back(tempTime/i); //add time to findTimes vector
            myUSet.clear(); //clear set for next loop
            
            uSetFindAvg.at(y) += (tempTime/i);
            y++;
        }
    }
    
    cout << "Set that uses a Self Sorting BST" << endl;
    cout << "Insert" << endl;
    for(unsigned i = 0; i < setInsertAvg.size(); i++)
    {
        cout << setInsertAvg.at(i) << " seconds" << endl;
    }
    cout << endl;
    
    cout << "Find" << endl;
    for(unsigned i = 0; i < setFindAvg.size(); i++)
    {
        cout << setFindAvg.at(i) << " seconds" << endl;
    }
    cout << endl;
    
    cout << "Unsorted Set that uses hash tables" << endl;
    cout << "Insert" << endl;
    for(unsigned i = 0; i < uSetInsertAvg.size(); i++)
    {
        cout << uSetInsertAvg.at(i) << " seconds" << endl;
    }
    cout << endl;
    
    cout << "Find" << endl;
    for(unsigned i = 0; i < uSetFindAvg.size(); i++)
    {
        cout << uSetFindAvg.at(i) << " seconds" << endl;
    }
    cout << endl;
    
    string OutFile = "data.txt";
    
    OutPutFile(OutFile, setInsertAvg,uSetInsertAvg,setFindAvg,uSetFindAvg);
    
    return 0;
}