class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(),people.end());

        int n=people.size(), i=0, j=n-1, ans=0;

        while(i<=j){

            ans++;

            int cursum = people[i] + people[j];

            if(cursum<=limit)
            i++;

            j--;//Note we are taking jth element(i.e. greater element in the case if cursum>limit but not ith element as if we take jth element singly, there exists a chance when our ith element makes pair with j-1 or j-2... element and thus reducing the no. of boats used)

        }

        return ans;

    }
};