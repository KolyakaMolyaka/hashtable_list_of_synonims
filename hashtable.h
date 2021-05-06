#pragma once

#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef list<vector<int>> ListOfSynonims;

ostream& operator<<(ostream& os, const vector<int> v);

class HashTable {
public:
    HashTable(int new_size = 5) : size(new_size) {
        table_rows.resize(new_size);
    };

    int hash(const vector<int>& nums) const;
    void addVector(const vector<int>& nums);
    void print();

    bool operator[](const vector<int>& nums);

private:
    vector<ListOfSynonims> table_rows; 
    int size;
};
