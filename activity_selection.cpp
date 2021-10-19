// activity selection using greedy approach: for unweighted version
// activity selection using dp approach : for weighted version

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

struct selec
{
    int start, finish;
};

void selecActi(vector<selec> const &vec)
{
    // k for index of last acti. selected
    int k = 0;
    // set to store selected activity index
    set<int> out;
    // 0 as first activity
    out.insert(0);
    // start from 2nd activity
    for(int i = 1;i<vec.size();i++)
    {
        // if start time of ith acti. is >= finish time of last acti. ,include in list
        if(vec[i].start >= vec[k].finish)
        {
            out.insert(i);
            // increment k 
            k = i;
        }
    }
    for(int i : out)
    {
        cout<<"{"<<vec[i].start<<","<<vec[i].finish<<"}"<<"\n";
    }
}

int main()
{
    // start and finish time
    vector<selec> activity = 
    {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

// sorting a/c to their finish time
    sort(activity.begin(), activity.end(), [](auto const &lhs, auto const &rhs){
        return lhs.finish < rhs.finish;
    });

    selecActi(activity);
    return 0;
}
