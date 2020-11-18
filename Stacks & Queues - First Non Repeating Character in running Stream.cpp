//  GFG


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    queue<char>q;
	    int freq[26];
	    memset(freq, 0, sizeof freq);
	    for(int i = 0;i < n;i++)
	    {
	        char ch;
	        cin>>ch;
	        freq[ch - 'a']++;
	        q.push(ch);
	        while(!q.empty())
	        {
	            if(freq[q.front() - 'a'] > 1)
	                q.pop();
	            else
	            {
	                cout<<q.front()<<" ";
	                break;
	            }
	        }
	        if(q.empty())
	            cout<<-1<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
