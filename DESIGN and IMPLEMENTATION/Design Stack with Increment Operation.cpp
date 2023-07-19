/*
Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.
*/

class CustomStack {
    int cap;
    vector<int> arr;
public:
    CustomStack(int maxSize) {
       cap=maxSize;
    }
    
    void push(int x) {
        if(arr.size()<cap)
            arr.push_back(x);
        
    }
    
    int pop() {
        if(arr.size()==0)
            return -1;
        else{
            int res=arr.back();
            arr.pop_back();
            return res;
        }
        
    }
    
    void increment(int k, int val) {
      int x=k;
        if(arr.size()<k){
            x=arr.size();
        }
        for(int i=0;i<x;i++){
            arr[i]+=val;
        }
    }
};