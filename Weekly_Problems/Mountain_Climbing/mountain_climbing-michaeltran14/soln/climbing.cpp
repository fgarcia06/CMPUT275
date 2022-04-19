/*----------------------------------------------------------------------------------------------------
  Name: Michael Tran
  SID: 1662870
  CCID: mtran7
  CMPUT 275, Winter 2022

  Weekly Exercise #7: Mountain Climbing
----------------------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

typedef unsigned int uint;

/*----------------------------------------------------------------------------------------------------
    Description: 
        Function calculate the minimum burst needed to climb the mountain in the most intervals possible.

    Arguments:
        heights (const uint*): pointer pointing to a dynamically allocated array filled with ascending order of ledges.
        length (uint): the length of the array
    
    Returns: 
        Returns the max difference between two consecutive ledges.
----------------------------------------------------------------------------------------------------*/
uint greatest(const uint *heights, uint length){
    uint diff = 0, new_diff = 0;

    for (int i = length-1; i >= 0; i--){
         new_diff = heights[i] - heights[i-1];
            if (new_diff > diff) diff = new_diff;
    }

    return diff;
}

/*----------------------------------------------------------------------------------------------------
    Description: 
        GIven a specific burst value, find the amount of time it takes to travel up the mountain

    Arguments:
        heights (const uint*): pointer pointing to a dynamically allocated array filled with ascending order of ledges.
        length (uint): the length of the array
        burst (uint): the maximum distance you can travel before you need to rest
        rest (uint): time it takes per rest
    
    Returns: 
        Returns the time it takes to get to the peak of the mountain
----------------------------------------------------------------------------------------------------*/

//given a burst, calculate the amount of time it takes to clear the mountain, checking if the burst is enough to skip to next ledge
uint checktime(uint burst, const uint *heights, uint rest, uint length){
    uint time = 0, height = 0, rest_count = 0, bst = burst, index = 0, max = heights[length-1];

    while (height < max){
        if (burst > max){ //if our burst gets us above the max ledge
            height = max; //we're at the peak ledge

            break;
        }

        if (heights[index] > burst){
            height = heights[index-1]; //go to the previous ledge

            burst = height + bst; //burst goes to our ledge height + our initial burst value
        
            rest_count++;
        }

        if (heights[index] == burst){
            if (index == length-1){
                height = heights[index]; //we're at the peak ledge

            } else {

                height = heights[index]; 
                burst = height + bst;
                rest_count++; 

            }
        }
        index++;
    }

    time = height + rest*rest_count;
    return time;
}

/*----------------------------------------------------------------------------------------------------
    Description: 
        Binary search to find value where bursts at the minimum

    Arguments:
        heights (const uint*): pointer pointing to a dynamically allocated array filled with ascending order of ledges.
        length (uint): the length of the array
        rest (uint): time per rest
        limit (uint): largest possible time for mountain traversal
    
    Returns: 
        Returns minimum burst value for given limit
----------------------------------------------------------------------------------------------------*/

uint climbing(const uint *heights, uint length, uint rest, uint limit) {
    uint high = heights[length-1], low = greatest(heights, length)-1, burst = 0;

    while (low + 1 < high){
        burst = (high+low)/2;
        
        if (checktime(burst, heights, rest, length) <= limit){
            high = burst;
        } else {
            low = burst;
        }
    }

    return high;
}

int main(){
    uint length, rest, limit;

    cin >> length >> rest >> limit;

    uint *heights = new uint[length];


    for (uint i = 0; i < length; i++){
        cin >> heights[i];
    }

    cout << climbing(heights, length, rest, limit) << endl;

    return 0;
}
