// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

struct node{
   node* links[26];
   int endwith=0;
   int start_index = -1;

   node(){
       for(int i = 0;i<26;i++){
           links[i] = nullptr;
       }
   }

   bool iscontains(char ch){
       //checking wether the charcter is already there are not
       return (links[ch-'a'] != NULL) ;

   }

   void put(char ch,node* Node){
       links[ch-'a'] = Node ;
   }

   node* get(char ch){
       //for getting particular link 
       return links[ch-'a'];
   }

   void increaseend(){
       endwith++;
   }
   
   void decreaseend(){
       endwith--;
   }
   
   void set_start_index(int i){
       start_index = i;
   }
   
   int getendswith(){
       return endwith ;
   }
   int get_start_index(){
       return start_index ;
   }
};

class trie{
   private:
   node* root ;
   public:
   trie(){
       //intilisation
       root = new node();
   }

   void insert(string s,int ind){
       //inserting function
       node* temp = root ;
       for(int i = 0;i<s.size();i++){
           if(!temp->iscontains(s[i])){
               temp->put(s[i],new node());
           }
           temp = temp->get(s[i]);
       }
       temp->increaseend();
       if(temp->get_start_index() == -1){
           temp->set_start_index(ind) ;
       }
   }

   int countwordsequalto(string s){
       //for getting frequency
       node* temp = root;
       for(int i = 0;i<s.size();i++){
           if(!temp->get(s[i])){
               return 0;
           }
           temp = temp->get(s[i]);
       }
       return temp->getendswith();
   }
   
   int get_starting_index(string s){
       //for getting starting index
       node* temp = root;
       for(int i = 0;i<s.size();i++){
           if(!temp->get(s[i])){
               return 0;
           }
           temp = temp->get(s[i]);
       }
       return temp->get_start_index();
   }
};

class Solution
{
   public:
   //Function to find most frequent word in an array of strings.
   string mostFrequentWord(string arr[], int n) 
   {
      trie t;
      for(int i = 0;i<n;i++){
          t.insert(arr[i],i);
      }
      int fre = -1;
      string ans = "";
      for(int i = 0;i<n;i++){
          int x = t.countwordsequalto(arr[i]);
          int c = t.get_starting_index(arr[i]);
          if(x>fre){
              fre = x;
              ans = arr[i];
          }
          else if(x == fre){

// for getting last occurrence of same frequency
              int c2 = t.get_starting_index(ans);
              if(c>c2){
                  ans = arr[i];
              }
          }
      }
      return ans;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends