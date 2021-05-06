
#include <iostream>
#include <iomanip>
#include "hashtable.h"
using namespace std;



int main()
{
    HashTable ht; 
    ht.addVector({1,2,3,4,5});
    ht.addVector({1,2,3,45}); // creating collisions 
    
    ht.addVector({100,0,0,0,0}); 
    
    
    ht.print();
    
    vector<int> searchFor = {1,2,3,4,5};
    
    if (ht[searchFor]){ // true
        cout << "{" << searchFor << "}" << " is in table" << endl; 
    } else {
        cout << "{" << searchFor << "}" << " isn't in table" << endl;
    }
    
    searchFor = {5,4,3,2,1};
    
    if (ht[searchFor]){ // false
        cout << "{" << searchFor << "}" << " is in table" << endl;
    } else {
       
        cout << "{" << searchFor << "}" << " isn't in table" << endl;
    }
    
 
    
    return 0;
}

