//  GFG

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	priority_queue<int>maxHeap;
	priority_queue<int, vector<int>, greater<int>>minHeap;
	for(int i = 0;i < n;i++)
	{
	    int num;
	    int med;
	    cin>>num;
	    if(maxHeap.size() == 0 && minHeap.size() == 0)
	    {
	        med = num;
	        maxHeap.push(num);
	    }
	    else if(maxHeap.size() < minHeap.size())
	    {
	        if(num > med)
	        {
	            maxHeap.push(minHeap.top());
	            minHeap.pop();
	            minHeap.push(num);
	        }
	        else
	            maxHeap.push(num);
	        med = (minHeap.top() + maxHeap.top() )/2;
	    }
	    else if(maxHeap.size() > minHeap.size())
	    {
	        if(num < med)
	        {
	            minHeap.push(maxHeap.top());
	            maxHeap.pop();
	            maxHeap.push(num);
	        }
	        else
	            minHeap.push(num);
	        med = (minHeap.top() + maxHeap.top() )/2;
	    }
	    else if(maxHeap.size() == minHeap.size())
	    {
	        if(num < med)
	        {
	            maxHeap.push(num);
	            med = maxHeap.top();
	        }
	        else
	        {
	            minHeap.push(num);
	            med = minHeap.top();
	        }
	    }
	    cout<<med<<endl;
	}
	return 0;
}
