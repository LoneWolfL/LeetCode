///LeetCode 1. Two Sum C++
///write by LoneWolfL in 16.07.28
/**
test:
9
2 7 11 15
6
3 3 2
**/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res(2);//as return.
        map<int,int> indices;
        for (int i=0;i<nums.size();i++)
        {
            if (indices.count(target-nums[i])!=0)
            {
                res[0]=indices[target-nums[i]];
                res[1]=i;
                break;
            }
            indices.insert(make_pair(nums[i],i));
        }
        return res;
    }
};

int main()
{
    Solution TwoSum;
    vector<int> Nums;
    vector<int> ret;
    int Target;
    cin>>Target;
    int tmp;
    while (cin>>tmp) Nums.push_back(tmp);
    ret=TwoSum.twoSum(Nums,Target);
    for (size_t i=0;i<ret.size();i++)
        cout<<ret[i]<<' ';
}
