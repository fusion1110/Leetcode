#include <iostream>
#include <vector>
using namespace std;

vector<int> stableMountains(vector<int> &height, int threshold)
{
    vector<int> index;
    for (int i = 1; i < height.size(); i++)
    {
        if (height[i-1] > threshold)
        {
            index.push_back(i);
        }
    }
    return index;
}

int main()
{
    vector<int> height = {10,1,10,1,10};
    vector<int> result = stableMountains(height, 10);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}