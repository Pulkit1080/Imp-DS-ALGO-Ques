//GFG

class Solution
{
public:
    int absSum(vector<int>a)
    {
        int sum = 0;
        for(int i:a)
            sum += abs(i);
        return sum;
    }
	int search(string pat, string txt)
	{
	    int count = 0;
	    if(txt.length() < pat.length() || txt.length() == 0)
	        return count;
	    vector<int>mp(26, 0);
	    for(int i = 0;i < pat.length();i++)
	        mp[pat[i] - 'a']--;
	    int left = 0, right = 0;
	    while(right < pat.length())
	    {
	        mp[txt[right] - 'a']++;
	        right++;
	    }
	    right--;
	    while(right < txt.length())
	    {
	        if(absSum(mp) == 0)
	            count++;
	        mp[txt[left] - 'a']--;
	        left++;
	        right++;
	        if(right < txt.length())
	            mp[txt[right] - 'a']++;
	    }
	    return count;
	}
};
//LEETCODE


class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int>ans;
        if(s.length() < p.length())
            return ans;
        vector<int>sv(26, 0);
        vector<int>pv(26, 0);
        int window = p.length();
        int left = 0, right = 0;
        while(right < window)
        {
            sv[s[right] - 'a']++;
            pv[p[right] - 'a']++;
            right++;
        }
        right--;
        while(right < s.length())
        {
            if(sv == pv)
                ans.push_back(left);
            sv[s[left] - 'a']--;
            left++;
            right++;
            if(right != s.length())
                sv[s[right] - 'a']++;
        }
        return ans;
    }
};
