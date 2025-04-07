#include<bits/stdc++.h>
using namespace std;

int main(){


map<int, string> mp;
//     mp[0] = "A";
//     mp[1] = "B";
//     mp[2] = "C";

//     auto itr = mp.find(2);
//     cout<< itr -> first;    // 2
//     cout<< itr -> second;  // C

//     auto ir = mp.find(3);  // ir = mp.end(): return itrator points just past the last element
// }


mp[0] = "bob";
mp[1] = "job";

int key = 2;

if(mp.find(key) != mp.end()){  // if element exist
    cout << "key found: " << mp[key];
}

else{
    cout << "key not found";  // output as keu=2 doesnot exist
}


}