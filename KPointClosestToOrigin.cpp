#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    //* lambda function
    auto comp = [](const vector<int> &a, const vector<int> &b)
    { return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1]; };

    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

    for (auto pt : points)
    {
        minHeap.push({pt[0], pt[1]});
    }

    //pushing top K elements into an array
    vector<vector<int>> res;
    for (int i = 0; i < k; ++i)
    {
        res.push_back(minHeap.top());
        minHeap.pop();
    }

    return res;
}

int main()
{
    // Sample input
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}, {1, 1}};
    int k = 2; // Number of closest points to find

    // Calling the function
    vector<vector<int>> result = kClosest(points, k);

    // Output the results
    cout << "The " << k << " closest points to the origin are:\n";
    for (auto &point : result)
    {
        cout << "(" << point[0] << ", " << point[1] << ")\n";
    }

    return 0;
}