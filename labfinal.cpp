# include<iostream>
#include<bits/stdc++.h>
#include<gtest/gtest.h>

using namespace std;

class Student {
private:
    int id;
    string name;
public:
    Student(int id = 0, string name = "") : id(id), name(name) {}
    
    int getId() const {
        return id;
    }
    
    string getName() const {
        return name;
    }
    
    void setId(int newId) {
        id = newId;
    }
    
    void setName(string newName) {
        name = newName;
    }
};


