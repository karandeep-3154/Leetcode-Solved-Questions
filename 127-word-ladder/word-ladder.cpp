class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        set<string> list;

        for(auto i : wordList)
        list.insert(i);

        if(list.find(endWord) == list.end())
        return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(q.size()){

            string top = q.front().first;
            int level = q.front().second;
            q.pop();

            if(top == endWord)
            return level;

            for(int i=0;i<top.size();i++){
                char ch = top[i];
                for(char j='a';j<='z';j++){

                    if(j == ch)
                    continue;

                    string temp = top;
                    temp[i] = j;

                    if(list.find(temp)!=list.end()){

                        q.push({temp,level+1});
                        list.erase(temp);

                    }

                }
            }

        }

        return 0;

    }
};