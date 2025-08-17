    #include <bits/stdc++.h>
    using namespace std;
    // to return : maximum no. of pages assigned to a student is minimum
    //Allocate Min Page
    //                                       77
    int FindStudents(vector<int> &arr, int pages){
        int cntStudents = 1;
        int StudentPage = 0;
        for(int i = 0; i<arr.size(); i++){
            if(StudentPage+arr[i] > pages){
                cntStudents++;
                StudentPage = arr[i];
            }
            else{
                StudentPage += arr[i];
            }
        }return cntStudents;
    }

    int Brute(vector<int> &arr, int s){  // tc: O((sum-max+1     ) * N))
        if(arr.size() < s) return -1;
        int MaxNoOfPages = *max_element(arr.begin(), arr.end());
        int SumOfAllPages = accumulate(arr.begin(), arr.end(), 0);

        for(int pages = MaxNoOfPages; pages<=SumOfAllPages; pages++){
            int students = FindStudents(arr, pages);
            if(students == s){
                return pages;
            } 
        }return -1;
    }

    int Optimal(vector<int> &arr, int s){ // tc: O(log(sum-max+1) * N))   
        int MaxNoOfPages = *max_element(arr.begin(), arr.end());
        int SumOfAllPages = accumulate(arr.begin(), arr.end(), 0);

        int low = MaxNoOfPages;
        int high = SumOfAllPages;
        while(low<=high){
            int mid = (low+high)/2; // mid=pages

            int students = FindStudents(arr, mid);

            if(students <= s){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }return low;
    }

    int main(){
        vector<int> a = {25, 46, 28, 49, 24};
        int students = 4;
        cout<<Optimal(a, students);
    }