//  GFG

static bool cmp(string a, string b)
{
    string ab = a.append(b);
    string ba = b.append(a);
    return ab > ba;
}
string printLargest(vector<string> &arr)
{
    // code here
    sort(arr.begin(), arr.end(), cmp);
    string ans = "";
    for(int i = 0;i < arr.size(); i++)
        ans += arr[i];
    return ans;
}
