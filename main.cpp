#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int square(int no)
    {
        return no * no;
    }

    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> squaredArray;
        int negativePointer = -1;
        for (int no : nums)
        {
            if (no < 0)
                negativePointer++;
        }
        int positivePointer = negativePointer + 1;
        // int positiveNos = nums.size() - positivePointer;
        while (negativePointer >= 0 && positivePointer < nums.size())
        {
            if (abs(nums[negativePointer]) < nums[positivePointer])
            {
                squaredArray.push_back(square(nums[negativePointer--]));
            }
            else
            {
                squaredArray.push_back(square(nums[positivePointer++]));
            }
        }
        while (negativePointer >= 0)
        {
            squaredArray.push_back(square(nums[negativePointer--]));
        }
        while (positivePointer < nums.size())
        {
            squaredArray.push_back(square(nums[positivePointer++]));
        }
        return squaredArray;
    }
};

int main()
{
    cout << "Hello World" << endl;
    return 0;
}