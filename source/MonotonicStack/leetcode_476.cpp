//
// Created by aowei on 25-6-30.
//
#include<iostream>
#include <vector>
#include <map>
#include <stack>

using std::vector;
using std::map;
using std::stack;

// 方法一：暴力解法，双循环，O(n**2)
vector<int> nextGreaterElement_1(const vector<int>& nums1, const vector<int>& nums2)
{
    vector<int> res(nums1.size(), 0);
    for (auto i = 0; i < nums1.size(); ++i)
    {
        bool f = false;
        int m = 0;
        for (m = 0; m < nums2.size(); ++m)
        {
            if (nums1[i] != nums2[m]) continue;
            break;
        }
        for (; m < nums2.size(); ++m)
        {
            if (nums2[m] > nums1[i])
            {
                res[i] = nums2[m];
                f = true;
                break;
            }
        }
        if (!f)
        {
            res[i] = -1;
        }
    }
    return res;
}

// 方法二：单调栈

vector<int> nextGreaterElement_2(const vector<int>& nums1, const vector<int>& nums2)
{
    vector<int> res(nums1.size(), 0);
    stack<int> s;
    map<int, int> mp;

    for (auto i = 0; i < nums2.size(); ++i)
    {
        if (s.empty()) s.push(nums2[i]);
        else if (s.top() >= nums2[i]) s.push(nums2[i]);
        else
        {
            while (!s.empty() && s.top() < nums2[i])
            {
                mp[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
    }
    for (auto i = 0; i < nums1.size(); ++i)
    {
        if (mp.find(nums1[i]) != mp.end())
        {
            res[i] = mp[nums1[i]];
        }
        else
        {
            res[i] = -1;
        }
    }
    return res;
}

int main()
{
    const vector<int> nums1 = {2, 4};
    const vector<int> nums2 = {1, 2, 3, 4};
    vector<int> res1 = nextGreaterElement_1(nums1, nums2);
    vector<int> res2 = nextGreaterElement_2(nums1, nums2);
    std::cout << "123" << std::endl;
}
