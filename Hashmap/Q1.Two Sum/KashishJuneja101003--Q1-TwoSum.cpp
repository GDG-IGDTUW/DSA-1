#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;                // Vector to store the result
    unordered_map<int, int> hash;      // Hash map to store numbers and their indices.
    
    // Iterate through the input array.
    for (int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];           // Current number.
        int second = target - first;   // The number needed to reach the target.
        
        // Check if the complementary number (second) exists in the hash map.
        if (hash.find(second) != hash.end())
        {
            result.push_back(i);        // Push the current index.
            result.push_back(hash[second]); // Push the index of the complementary number.
            break;                      // Break as we found the pair.
        }
        else
        {
            hash[first] = i;            // Store the current number and its index.
        }
    }
    return result;                      // Return the result.
}

int main()
{
    // Example input array and target.
    vector<int> nums = {2, 7, 11, 15}; 
    int target = 9;

    // Call the twoSum function.
    vector<int> indices = twoSum(nums, target);

    // Check if indices are found and print them.
    if (!indices.empty())
    {
        cout << "Target = "<<target<<" can be achieved by adding 2 numbers present at Indices: " << indices[0] << " and " << indices[1] << endl;
    }
    else
    {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
