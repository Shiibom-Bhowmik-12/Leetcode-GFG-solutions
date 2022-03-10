// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insertatbottom(stack<int> &s,int k){
    if(s.empty() or s.top()<k){
        s.push(k);
        return;
    }
    
    int p=s.top();
    s.pop();
    insertatbottom(s,k);
    s.push(p);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    
    int k=s.top();
    s.pop();
    reverse(s);
    insertatbottom(s,k);
}

void SortedStack :: sort()
{
   //Your code here
   reverse(s);
}