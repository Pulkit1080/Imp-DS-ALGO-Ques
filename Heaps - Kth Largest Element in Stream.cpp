//  GFG

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n ,k, num;
	    cin>>k>>n;
	    priority_queue<int, vector<int>, greater<int>>minHeap;
	    for(int i = 0;i < n;i++)
	    {
	        cin>>num;
	        if(minHeap.size() < k)
	        {
	            minHeap.push(num);
	            if(minHeap.size() == k)
	                cout<<minHeap.top()<<" ";
	            else
	                cout<<-1<<" ";
	        }
	        else if(minHeap.size() == k && num > minHeap.top())
	        {
	            minHeap.pop();
	            minHeap.push(num);
	            cout<<minHeap.top()<<" ";
	        }
	        else
	        {
	            cout<<minHeap.top()<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
