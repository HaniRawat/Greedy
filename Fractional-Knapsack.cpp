//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
  
  static bool cmp(Item a, Item b){
      double r1 = (double) a.value/a.weight;
      double r2 = (double) b.value/b.weight;
      
      return r1 > r2;
  }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        double ans = 0;
        
        sort(arr,arr+n,cmp);
        
        for(int i=0; i<n; i++){
            if(arr[i].weight <= w){
                ans += arr[i].value;
                w -= arr[i].weight;
            }
            else{
                ans += (arr[i].value*((double)w/(double)arr[i].weight));
                break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends