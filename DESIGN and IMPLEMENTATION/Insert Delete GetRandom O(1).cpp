/*

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

*/

class RandomizedSet {
public:
    map<int,int> map1;
    vector<int> stk;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(map1.find(val) == map1.end()){
            stk.push_back(val);
            map1[val] = stk.size()-1;
            return(true);
        }
        else{return(false);}
    }
    
    bool remove(int val) {
        if(map1.size() == 0 || map1.find(val) == map1.end()){return(false);}
        else{
        map1[stk.back()] = map1[val];
        swap(stk.back() , stk[map1[val]]);
        stk.pop_back();
        map1.erase(val);   
        return(true);}
    }
    
    int getRandom() {
        return(stk[rand()%map1.size()]);
    }
};