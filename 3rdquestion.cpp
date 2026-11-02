#include <iostream>
#include <vector>

using namespace std;

class O1Dictionary {
private:
    int capacity;
    int currentSize;
    vector<int> A;
    vector<int> pos;

public:
    O1Dictionary(int n) {
        capacity = n;
        currentSize = 0;
        A.resize(n + 1);
        pos.assign(n + 1, 0);
    }

    bool search(int x) {
        if (x < 1 || x > capacity) return false;
        int idx = pos[x];
        return (idx >= 1 && idx <= currentSize && A[idx] == x);
    }

    void insert(int x) {
        if (x < 1 || x > capacity) return;
        if (search(x)) return;
        
        currentSize++;
        A[currentSize] = x;
        pos[x] = currentSize;
    }

    void remove(int x) {
        if (!search(x)) return;
        
        int idx = pos[x];
        int lastElement = A[currentSize];
        
        A[idx] = lastElement;
        pos[lastElement] = idx;
        
        pos[x] = 0;
        currentSize--;
    }
};

int main() {
    int n = 10;
    O1Dictionary dict(n);

    dict.insert(5);
    dict.insert(2);
    dict.insert(8);

    cout << "Search 5: " << (dict.search(5) ? "True" : "False") << endl;
    cout << "Search 3: " << (dict.search(3) ? "True" : "False") << endl;

    dict.remove(5);
    cout << "Search 5 after deletion: " << (dict.search(5) ? "True" : "False") << endl;

    return 0;
}
