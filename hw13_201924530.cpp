#include <iostream>
#include <cstring>
using namespace std;

template <class T, int sz>
class List {
    T* items;
    int size;
    int top;
public:
    List(int len = 100) : size(len) {
        items = new T[size=len];
        top = 0;
    }
    List(const List& l) {
        delete[] items;
        size = l.size;
        items = new T[size];
        items = l.items;
        top = l.top;
    }
    ~List() {
        delete [] items;
    }
    List& operator = (const List& l) {
        delete[] items;
        items = new T[size = l.size];
        items = l.items;
        return *this;        
    }
    void add(const T& element) {
        items[top] = element;
        top++;
        cout << element << " is added" << endl;
    }
    void find(const T& element) {
        for (int i = 0; i < size; i++) {
            if (items[i] == element) {
                cout << element << "is found" << endl;
                return;
            }
        }
        cout << element << " is not found" << endl;
    }
    void remove(const T& element) {
        for (int i = 0; i < size; i++) {
            if (items[i] == element) {
                for (int j = i; j < size-1; j++) {
                    items[j] = items[j + 1];
                }
                size--;
                cout << element << " is removed" << endl;
                return;
            }
        }
        cout << element << " is not found so didn't removed" << endl;
        return;
    }
};

class Complex {
private:
    float real, imaginary;

public:
    Complex(float r = 0.F, float i = 0.F) : real(r), imaginary(i){}
    bool operator == (const Complex& c) const {
        return (real == c.real && imaginary == c.imaginary);
    }
    void operator = (const Complex& c) {
        real == c.real;
        imaginary == c.imaginary;
    }
    friend ostream& operator << (ostream& os, const Complex& c);
};
ostream& operator << (ostream& os, const Complex& c) {
    os << c.real << "," << c.imaginary;
    return os;
}

class MyString {
private:
    char* str;

public:
    MyString(const char* s = "") {
        str = new char[strlen(s)+1];
        strcpy(str, s); 
    }
    ~MyString() {
        if (str != nullptr)
            delete [] str;
    }
    MyString(const MyString& s) {
        str = new char[s.getSize() + 1];
        strcpy(str, s.getStr());
    }
    void operator = (const MyString& s) {
        str = new char[s.getSize() + 1];
        strcpy(str, s.getStr());
    }
    int getSize() const { 
        return strlen(str); 
    }
    char* getStr() const { 
        return str; 
    }
    bool operator == (const MyString& s) const {
        if (strcmp(str, s.str) == 0)
            return true;
        else
            return false;
    }
    friend ostream& operator << (ostream& os, const MyString& s);
};
ostream& operator << (ostream& os, const MyString& s) {
    os << s.str;
    return os;
} 

int main() {
    List<Complex, 100> cList;
    List<MyString, 200> sList;

    cList.add(Complex(0, 0));
    cList.add(Complex(1, 1));

    sList.add("abc");
    sList.add("def");

    cList.find(Complex(1, 0));
    sList.find("def");
    cList.remove(Complex(0, 0));
    sList.remove("abc");

    List<MyString, 200> s2List(sList);
    List<MyString, 200> s3List;
    s3List.add("123");
    s3List = s2List;
    s3List.remove("def");
}
