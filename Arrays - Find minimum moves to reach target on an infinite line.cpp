//GFG

class Solution
{
public:
    int solve_1(int pos, int lastSteps, int Dest)
    {
        if(abs(pos) > Dest)
            return INT_MAX;
        if(pos == Dest)
            return lastSteps;
        int positiveJump = solve_1(pos + lastSteps + 1, lastSteps + 1, Dest);
        int negativeJump = solve_1(pos - lastSteps - 1, lastSteps + 1, Dest);
        return min(positiveJump, negativeJump);
    }
    int solve_2(int target)
    {
        target = abs(target);
        int steps = 0, sum = 0;
        while(sum < target || (sum - target)%2 != 0)
        {
            steps++;
            sum += steps;
        }
        return steps;
    }
    int minSteps(int D)
    {
        //Sol 1 using recursion
        //return solve_1(0, 0, D);

        //Sol 2
        return solve_2(D);
    }
};
