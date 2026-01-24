//Overall SC : O(n)
//TC's mentioned against the functions

/*
Approach:
1. stacks have insertion and deletion from the same end, 
whereas queues have them at different ends.
2. if we assume the front end of the queue as the top of the stack (tos), deletion (pop) operation would act in a similar way.
3. for the insertion to happen on tos, first let us push it to the rear, then to maintain order all previous elements to it will be popped and pushed behind it until it becomes the new front. (rotation)
4. that way, top of stack corresponds to the front of the queue, and emptiness can be easily checked by the empty() function
*/

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {}

    void push(int x) //TC = O(n) extra SC = O(1) 
    {
        q.push(x); //first push to the rear
        int n = q.size();
        
        //push all the previous elements to the back of the newly inserted element to make it the new front
        for (int i = 0; i < n - 1; ++i) 
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() //TC = O(1) extra SC = O(1)
    {
        //deletion happening from the front (tos)
        int top = q.front();
        q.pop();
        return top;
    }

    int top() //TC = O(1) extra SC = O(1)
    {
        return q.front();
    }

    bool empty() //TC = O(1) extra SC = O(1)
    {
        return q.empty();
    }
};
