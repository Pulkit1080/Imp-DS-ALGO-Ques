//LEETCODE

class Solution {
public:
    string reorganizeString(string S)
    {
        int map[26];
        memset(map, 0, sizeof map);
        for (int i = 0;S[i] != '\0';i++)
        {
            map[S[i] - 'a']++;
            if(map[S[i] - 'a'] > (S.length() + 1)/2)    //freq of char is more than half of string
                return "";
        }
        priority_queue<pair<int, char>> pq;   //int should be first, as sorting will be based on freq
        for (int i = 0; i < 26; i++)
        {
            if (map[i])
                pq.push({map[i], i + 'a'});
        }
        string ans;
        while(!pq.empty())
        {
            pair<int, char> p1, p2;
            p1 = pq.top();
            pq.pop();
            ans.push_back(p1.second);
            if(!pq.empty())
            {
                p2 = pq.top();
                pq.pop();
                ans.push_back(p2.second);
                if(--p2.first)         //more of second most freq elements left
                    pq.push(p2);
            }
            if(--p1.first)             //more of most freq elements left
                pq.push(p1);
        }
        return ans;
    }
};
