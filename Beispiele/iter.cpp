// sorted data
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> data;
    int number;

    cout << "input integers until < 0:" << endl;
    cin >> number;

    while (number >= 0) {
        auto iter = data.begin();
        while(iter != data.end() && *iter < number){
            iter++;
        }

        if(iter == data.end())
            data.push_back(number);
        else
            data.insert(iter, number);
        
        cout << "data: ";
        auto iters = data.begin();
        while(iters != data.end()){
            cout << *iters << " ";
            iters++;
        }
        cout << endl;

        cin >> number;
    }
}