No the algorithim is not stable.

Explanation:

Suppose the array is
5 2 3  8 4 5 6 
Let's distinguish the two 5's as 5(a) and 5(b) .

So our array is:
5(a)  3 4  5(b) 2 6 8 

After iteration 1:
2 will be swapped with the element in 1st position:

So our array becomes:
2 3 4 5(b) 5(a) 6 8

Since now our array is in sorted order and we clearly see that 5(a) comes 
before 5(b) in initial array but not in the sorted array.

So we can clearly see that selection sort is not stable.

The below algorithim shows the proof with the last output in my main function
The function only compares the first element of the pairs and ignores
the second elements in order to visually see the defect.

Below is the code that I used to prove that the algorithm is not stable.
I also included it in my selctionsort.h file and created an output in the main
To also show that it is not stable.

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

//Main function
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