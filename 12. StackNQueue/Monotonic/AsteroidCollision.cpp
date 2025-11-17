#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids){ // tc, sc : O(N)
    stack<int> st;
    int n = asteroids.size();

    for(int i = 0; i<n; i++){

        if(asteroids[i] > 0) st.push(asteroids[i]);

        else{ // if asteroids[i] is -ve

            while(!st.empty() && st.top() > 0 && abs(asteroids[i]) > st.top()){ 
                st.pop();
            }
    
            if(!st.empty() && abs(asteroids[i]) == st.top()){
                st.pop();
            }
    
            else if(st.empty() || st.top() < 0){
                st.push(asteroids[i]);
            }
        }
    }
    vector<int> ans(st.size());
    for(int i = st.size()-1; i>=0; i--){
        ans[i] = st.top();
        st.pop();
    }
    return ans;

} 

int main(){
    vector<int> astro = {3,5,-6,2,-1,4};
    for(int i : asteroidCollision(astro)){
        cout << i << " ";
    }
}