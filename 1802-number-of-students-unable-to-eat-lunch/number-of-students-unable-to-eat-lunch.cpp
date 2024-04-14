class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int cnt0 = 0, cnt1 = 0, k=0, shifts=0;
        queue<int> q;
        
        for(int i=0;i<students.size();i++)
            q.push(students[i]);
                
        while(q.size() and shifts < q.size()){

            if(q.front() == sandwiches[k]){
                
                q.pop();
                k++;
                shifts = 0;

            }

            else{
                
                int ele = q.front();
                q.pop();
                q.push(ele);
                shifts++;
            
            }


        }

        return q.size();

    }
};