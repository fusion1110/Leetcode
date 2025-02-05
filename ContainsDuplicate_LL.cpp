#include <bits/stdc++.h>
using namespace std;

//* Floyd's algo
//* basically treating the numbers as pointers in a linked list
int findDuplicate(vector<int> &nums)
{
    int slow = 0, fast = 0;
    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];

        if (slow == fast)
            break;
    }

    int slow2 = 0;
    while (true)
    {
        slow = nums[slow];
        slow2 = nums[slow2];

        if (slow == slow2)
            return slow;
    }
}
int main()
{

    return 0;
}