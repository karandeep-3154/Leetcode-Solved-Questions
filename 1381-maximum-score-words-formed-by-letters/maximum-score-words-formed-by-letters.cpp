class Solution {
public:

    void precompute(vector<string>& words, vector<char>& letters, vector<int>& score, map<int, int> &getScore, map<char, int>& freq){
                
        int index = 0;

        for(auto i : words){

            map<char, int> p;
            for(auto j : i)
            p[j]++;

            int flag = 0;

            for(char c='a';c<='z';c++){
                if(freq[c]<p[c]){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){

                int currentScore = 0;

                for(auto j : i)
                currentScore += score[j-'a'];
                
                getScore[index++] = currentScore;

            }

            else
            getScore[index++] = 0;

            cout<<words[index-1]<<"dsfd"<<getScore[index-1]<<endl;

        }

    }

    void dfs(vector<string>& words, int i, int score, int &ans, map<char, int> freq, map<int, int>& getScore){

        if(i == words.size()){
            ans =  max(ans, score);
            return;

        }

        dfs(words, i+1, score, ans, freq, getScore);

        int canTake = 0;
        for(auto j : words[i])
        freq[j]--;

        for(auto j : freq){
            if(j.second <0){
                canTake = 1;
                break;
            }
        }
        
        if(!canTake)
        dfs(words, i+1, score+getScore[i], ans, freq, getScore);

        for(auto j : words[i])
        freq[j]++;

    

    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        map<int, int> getScore;
        map<char, int> freq;
        int ans = 0;

        for(auto i : letters)
        freq[i]++;

        precompute(words, letters, score, getScore, freq);

        dfs(words, 0, 0, ans, freq, getScore);

        return ans;

    }
};