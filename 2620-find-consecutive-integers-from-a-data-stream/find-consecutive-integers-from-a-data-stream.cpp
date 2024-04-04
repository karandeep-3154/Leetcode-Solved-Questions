class DataStream {
public:

    int v, k, cnt = 0;

    DataStream(int value, int kk) {

        v = value;
        k = kk;

    }
    
    bool consec(int num) {
        
        if(num != v){
            cnt = 0;
            return false;
        }
cout<<"Cnt is "<<cnt<<endl;
        if(cnt == k-1)
        return true;

        cnt++;
        return false;

    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */