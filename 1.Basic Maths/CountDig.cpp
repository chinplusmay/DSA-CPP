#include <bits/stdc++.h>
using namespace std;
// https://www.naukri.com/code360/problems/count-digits_8416387?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int countDigits(int n){
	// Write your code here.
	int count = 0;
	int temp = n;
	while(temp>0){  
		int rem;
		rem = temp % 10; 
		if(rem == 0){
			count=count;  // ignore rem=0 by having same count
		}
		else if(n % rem == 0 ){   // orignal % rem from temp
			count++;
		}
		temp = temp / 10;

	}return count;	 
}  

int main(){
    int n;
    cin >> n;
    cout << countDigits(n);
}