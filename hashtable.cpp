
#include "hashtable.h"
#include <iomanip>
#include <numeric>

ostream& operator<<(ostream& os, const vector<int> v){
    int cur_elem = 1;
    for (auto item: v){
        if (cur_elem != v.size())
            os << item << " ";
        else
            os << item;
        ++cur_elem;
    }
    return os;
};

int HashTable::hash(const vector<int>& nums) const {
    // average % size
    int average = accumulate(begin(nums), end(nums), 0) / static_cast<int>(nums.size());
    return average % size;
};

void HashTable::addVector(const vector<int>& nums){
    table_rows[hash(nums)].push_back(nums);    
}

void HashTable::print(){
    for (int i = 0; i < size; ++i){
        
        
        if (table_rows[i].empty())
            cout << i + 1 << " row is empty" << endl;
        else {
            cout << i + 1 << " row: " << endl;
            ListOfSynonims list_of_synonims = table_rows[i];
            
            for (const auto& vec: list_of_synonims){
                cout << "\t";
                cout << vec << endl;
            }
        }
        
    }
}


bool HashTable::operator[](const vector<int>& nums){
    ListOfSynonims list_of_synonims = table_rows[hash(nums)];
    
    if (list_of_synonims.empty()) return false;
    
    for (const auto& vec: list_of_synonims){
        if (vec == nums) return true;
    }
    
    return false;
   
}