#include <iostream>
#include <vector>
using namespace std;

void explainVector() {
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    v.push_back(4);
    v.push_back(5);

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    vector<int> vecc(5, 100); // Vector of size 5, all elements initialized to 100
    vector<int> v4(5);        // Vector of size 5, all elements initialized to 0
    vector<int> v5(5, 20);    // Vector of size 5, all elements initialized to 20
    vector<int> v6(v5);       // Copy contents of v5 to v6

    cout << "\nFirst element of v6: " << v6.at(0) << endl;

    // Iterator example
    vector<int>::iterator it = v.begin();
    it++; // Points to the second element
    cout << *it << " "; // Prints second element
    it = it + 2;        // Moves 2 steps ahead
    cout << *it << " "; // Prints fourth element

    // Using iterators properly
    vector<int>::iterator it1 = v.end(); // Points one past the last element, DO NOT dereference

    vector<int>::reverse_iterator rit2 = v.rbegin(); // Points to the last element
    cout << "\nLast element using reverse iterator: " << *rit2 << endl;

    cout << "Last element using v.back(): " << v.back() << endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" "; 
    }
    for(auto it:v){
        cout<<it<<" ";
    }
    v.erase(v.begin()+1);
    v.erase(v.begin()+2,v.begin()+4);

    vector<int>vv(2,100);
    v.insert(v.begin(),300);
}

int main() {
    explainVector();
    return 0;
}
