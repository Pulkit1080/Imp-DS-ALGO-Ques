//  LEETCODE

//Integer to Roman

class Solution
{
public:
    string intToRoman(int num)
    {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[] = {"", "M", "MM", "MMM"};

        return thousands[num/1000] + hundreds[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

//Roman to Integer

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int>mp;
        mp.insert({'I',1});
        mp.insert({'V',5});
        mp.insert({'X',10});
        mp.insert({'L',50});
        mp.insert({'C',100});
        mp.insert({'D',500});
        mp.insert({'M',1000});
        int ans = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(i > 0 && mp[s[i]] > mp[s[i-1]])
                ans += mp[s[i]] - 2*mp[s[i-1]];
            else
                ans += mp[s[i]];
        }
        return ans;
    }
};
