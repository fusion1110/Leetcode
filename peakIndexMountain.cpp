#include <iostream>
#include <vector>
using namespace std;
//*O(n) time complexity ke liye linear search
//*O(logn) time complexity ke liye Binary search

int peakIndexInMountainArray(vector<int> &arr)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        mid = s + (e - s) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int main()
{

    return 0;
}

// The line ios_base::sync_with_stdio(false); and cin.tie(nullptr); is commonly used in C++ to optimize input and output operations, particularly when you're dealing with competitive programming or large amounts of data. Here's what each part does:
// 1. ios_base::sync_with_stdio(false);
// By default, C++ streams (cin, cout) are synchronized with the C standard streams (stdin, stdout). This synchronization allows you to use both printf/scanf (from C) and cin/cout (from C++) interchangeably. However, this synchronization adds some overhead.
// What it does: Disabling the synchronization between C and C++ standard streams by setting sync_with_stdio(false) allows faster input and output by preventing the internal flushing and synchronization processes.
// When to use it: This is useful when you're only using C++ I/O (cin, cout) and do not plan to use C-style I/O (scanf, printf), as it speeds up input/output operations.
// 2. cin.tie(nullptr);
// In C++, by default, cin is tied to cout, meaning that cout is automatically flushed (i.e., the output buffer is written to the console) every time cin is used. This ensures that any output is printed before waiting for input.
// What it does: Setting cin.tie(nullptr) unties cin from cout. This prevents the automatic flush of cout before every cin operation, which improves performance when you're alternating between input and output operations in large datasets.
// When to use it: In scenarios where you don’t need immediate output flushing between input and output operations, this can save time.