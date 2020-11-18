//LEETCODE (Locked)
int maxD = 0;
int maxDiameter(node*root)
{
    if(root == nullptr)
        return 0;
    int first_max = 0;
    int second_max = 0;
    for(auto child:root->children)
    {
        int tmp_height = 1 + maxDiameter(child);
        if(tmp_height > first_max)
        {
            second_max = first_max;
            first_max = tmp_height;
        }
        else if(tmp_height > second_max)
            second_max = tmp_height;
    }
    maxD = max(maxD, first_max + second_max);
    return maxD;
}
