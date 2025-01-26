#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>

using namespace std;

class LRUCache {
    private:
    int capacity;
    list<pair<int,int>> lru;
    unordered_map<int,list<pair<int,int>>::iterator> um;

    public:
    LRUCache(int capacity) {
         this->capacity = capacity;
    }

    int get(int key) {
        list<pair<int,int>>::iterator it;
        
        if (um.find(key) != um.end()) {
            list<pair<int,int>>::iterator it = um[key];
            int val = it->second;
            um.erase(key);
            lru.erase(it);
            lru.push_front({key,val});
            um[key] = lru.begin();
            return val;
        }
        else {
             return -1;
        }
    }

    void put(int key, int value) {
        
        if (um.find(key) != um.end()) {
            list<pair<int,int>>::iterator it = um[key];
            lru.erase(it);
            um.erase(key);
        }
        
        if (lru.size() >= capacity) {
            pair<int,int> elem = lru.back();
            int delete_key = elem.first;
            auto it = um[delete_key];
            um.erase(delete_key);
            lru.erase(it);
        }

        lru.push_front({key,value});
        um[key] = lru.begin();
        display();
    }

    void display() {
        cout << "Elements in LRU cache " << endl;
        for(auto elem:lru) {
            cout << "{" << elem.first << "," << elem.second << "}" << " ";
        }
        cout << endl;
    }

};


int main()
{
 
 LRUCache lRUCache(2);
 lRUCache.put(1,1);
 lRUCache.put(2,2);
 cout << "Get value " << lRUCache.get(1) << endl;    // return 1
 lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 cout << "Get value " <<  lRUCache.get(2)  << endl;    // returns -1 (not found)
 lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 cout << "Get value " <<  lRUCache.get(1)  << endl;    // return -1 (not found)
 cout << "Get value " <<  lRUCache.get(3)  << endl;    // return 3
 cout << "Get value " <<  lRUCache.get(4) << endl;   // return 4

}