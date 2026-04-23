#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
    // Default constructor
    Evil() : st(0), ed(0), val(0) {
        int size = ed - st + 1;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
        } else {
            data = nullptr;
        }
    }
    
    // Parameterized constructor
    Evil(int s, int e, int v) : st(s), ed(e), val(v) {
        int size = ed - st + 1;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
        } else {
            data = nullptr;
        }
    }
    
    // Copy constructor (needed for proper deep copy)
    Evil(const Evil& other) : st(other.st), ed(other.ed), val(other.val) {
        int size = ed - st + 1;
        if (size > 0) {
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    
    // Assignment operator overload
    Evil& operator=(const Evil& other) {
        if (this != &other) {
            // Delete old data
            if (data != nullptr) {
                delete[] data;
            }
            
            // Copy values
            st = other.st;
            ed = other.ed;
            val = other.val;
            
            // Allocate and copy new data
            int size = ed - st + 1;
            if (size > 0) {
                data = new int[size];
                for (int i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }
    
    // Subscript operator overload
    int& operator[](int i) {
        if (i >= st && i <= ed) {
            return data[i - st];
        } else {
            return data[0]; // Return first element if out of range
        }
    }
    
    // Prefix ++ overload
    Evil& operator++() {
        val++;
        return *this;
    }
    
    // Postfix ++ overload
    Evil operator++(int) {
        Evil temp(*this);
        val++;
        return temp;
    }
    
    // Output operator overload
    friend ostream& operator<<(ostream& os, const Evil& e) {
        os << e.val << " ";
        for (int i = 0; i < e.ed - e.st + 1; ++i) {
            os << e.data[i] << " ";
        }
        os << endl;
        return os;
    }
    
    // Destructor
    ~Evil() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
    }

    void Print(){
        cout << val << " ";
        for(int i = 0; i < ed-st+1; ++i)
            cout << data[i] <<" ";
        cout << endl;
    }
};

#endif//EVIL_HPP
