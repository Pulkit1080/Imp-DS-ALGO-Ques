//     GFG

int tour(petrolPump p[],int n)
{
    //Your code here
    int tot = 0;
    for(int i = 0;i < n;i++)
    {
        tot += p[i].petrol - p[i].distance;
    }
    if(tot < 0)
        return -1;
    int start = 0;
    tot = 0;
    for(int i = 0;i < n;i++)
    {
        tot += p[i].petrol - p[i].distance;
        if(tot < 0)
        {
            tot = 0;
            start = i+1;
        }
    }
    return tot > 0? start:-1;
}
