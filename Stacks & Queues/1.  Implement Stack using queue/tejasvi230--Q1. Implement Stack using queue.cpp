class MyStack {
public:
    // Single queue used to simulate stack behavior
    queue<int> q;

    // Constructor
    MyStack() {}

    // Push element x onto stack
    void push(int x) {
        // Step 1: Push the new element into the queue
        q.push(x);

        // Step 2: Rotate the queue so that the new element
        // comes to the front (LIFO behavior)
        // Size changes dynamically, so we rotate (size - 1) times
        for (int i = 1; i < q.size(); i++) {
            q.push(q.front()); // move front element to back
            q.pop();           // remove front
        }
    }

    // Removes and returns the top element of the stack
    int pop() {
        // Front of the queue represents the top of the stack
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    // Returns the top element without removing it
    int top() {
        return q.front();
    }

    // Checks whether the stack is empty
    bool empty() {
        return q.empty();
    }
};
