// Aufgabe 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout << "Type a small positive Integer: ";
    cin >> n;

    vector<int> indices;
    for(int i = 0; i < n; i++){
        indices.push_back(i);
    }

    for(auto j: indices){
        cout << j << ' ';
    }
    cout << '\n';

    //cout << "Testing perm: " << next_permutation(indices.begin(),indices.end()) << endl;

    while(next_permutation(indices.begin(),indices.end())){
        for(auto j: indices){
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}