// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n)
{
    set<int, greater<int>> s1;
    vector<int> vec;
    vec.push_back(-1);
    s1.insert(arr[0]);
    set<int, greater<int> >::iterator itr;
    for(int i=1;i<n;i++){
        s1.insert(arr[i]);
        itr = s1.upper_bound(arr[i]);
        if(itr == s1.end()){
            vec.push_back(-1);
        }
        else{
            vec.push_back(*itr);
        }
    }
    return vec;
}