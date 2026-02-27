#include <iostream>
using namespace std;

class Bag {
    //private variables
    int *items;
    int len;
    int capacity;
    int find(int n) const;
public:
    //default constructor
    Bag() {
        len = 0;
        capacity = 10;
        items = new int[capacity];
    }
    //destructor
    ~Bag() {
        delete[] items;
    }
    //copy constructor
    Bag(const Bag &b) {
        len = b.len;
        capacity = b.capacity;
        items = new int[capacity];
        for (int i = 0; i < len; i++) {
            items[i] = b.items[i];
        }
    }
    //assignment operator
    Bag &operator=(const Bag &b);
    //adds n if not already present and space exists
    void add(int n);
    //prints the contents
    void show() const;
    //returns true if it's in the bag
    bool contains(int n) const;
};
//finds a character, if not present return -1
int Bag::find(const int n) const {
    for (int i = 0; i < len; i++) {
        if (items[i] == n) {
            return i;
        }
    }
    return -1;
}

//assignment operator function
Bag & Bag::operator=(const Bag &b) {
    //self assignment protection
    if (this == &b) {
        return *this;
    }
    //deletes old contents
    delete[] items;
    //assigns new variables based on the parameter one
    len = b.len;
    capacity = b.capacity;
    items = new int[capacity];
    for (int i = 0; i < len; i++) {
        items[i] = b.items[i];
    }
    return *this;
}
//add into the bag
void Bag::add(int n) {
    //if its already present, do nothing
    if (find(n) != -1) {
        return;
    }
    //check whether it is bigger than capacity
    if (len >= capacity) {
        cout << "No more space!" << '\n';
        return;
    }
    items[len] = n;
    len++;
}
//prints the contents
void Bag::show() const {
    for (int i = 0; i < len; i++) {
        cout << items[i] << " ";
    }
}
//check whether n is contained within the bag
bool Bag::contains(const int n) const {
    if (len == 0) {
        cout << "Empty Bag" << endl;
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (items[i] == n) {
            return true;
        }
    }
    return false;
}

int main() {
    Bag b1;
    b1.add(10);
    b1.add(20);
    b1.add(30);

    Bag b2 = b1;   // copy constructor
    b2.add(40);    // should NOT appear in b1

    b1.show();     // { 10 20 30 }
    b2.show();     // { 10 20 30 40 }

    b1 = b2;       // operator=
    b1.show();     // { 10 20 30 40 }

    b1 = b1;       // self-assignment - should not crash
    b1.show();     // { 10 20 30 40 }

    return 0;
}
