/*
PROBLEM: Next Greater Element II (Circular Array)

Given a circular integer array nums, return an array
where each element contains the next greater element.
If no greater element exists, store -1.

Circular means:
- After the last index, we continue from index 0.
*/

/*
BRUTE FORCE APPROACH

INTUITION:
- For every element, look at the next elements one by one.
- Since the array is circular, use modulo (%) to wrap around.
- Stop when a greater element is found.
- If none found after checking n-1 elements, answer is -1.

TIME COMPLEXITY:
- O(n^2) because for each element we may scan the entire array.

SPACE COMPLEXITY:
- O(1) extra space (excluding output array).
*/

vector<int> nextGreaterElementsBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int idx = (i + j) % n; // circular traversal
            if (nums[idx] > nums[i]) {
                ans[i] = nums[idx];
                break;
            }
        }
    }
    return ans;
}

/*
OPTIMIZED APPROACH (MONOTONIC STACK)

INTUITION:
- Use a stack to keep indices of elements whose next greater
  element has not been found yet.
- Maintain the stack in decreasing order of values.
- Traverse the array twice to simulate circular behavior.
- When current element is greater than the element at stack top,
  it is the next greater element.

WHY TRAVERSE 2 * n TIMES?
- First pass: push elements into stack.
- Second pass: resolve pending elements due to circular nature.
- We only push indices during the first pass.

TIME COMPLEXITY:
- O(n) because each element is pushed and popped at most once.

SPACE COMPLEXITY:
- O(n) for the stack.
*/

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) {
        int idx = i % n;

        while (!st.empty() && nums[idx] > nums[st.top()]) {
            ans[st.top()] = nums[idx];
            st.pop();
        }

        if (i < n) {
            st.push(idx);
        }
    }
    return ans;
}

