class SummaryRanges {
public:
    map<int,int>mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        mp[value] = value;
        while(value <= 1e4){
            if(mp.count(value-1) && mp.count(value)){
                mp[value] = mp[value-1];
                value++;
            }
            else break;
        }
        value++;
        while(value <= 1e4){
            if(mp.count(value-1) && mp.count(value)){
                mp[value] = mp[value-1];
                value++;
            }
            else break;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>a;
        if(mp.size() == 0)return {};
        vector<int>v;
        int s = -1;
        for(auto i : mp){
              if(s == -1){
                s = i.first;
                v.push_back(i.first);
              }
              else if(i.second == s){
                v.push_back(i.first);
              }
              else {
                a.push_back(v);
                s = i.first;
                v.assign(0,0);
                v.push_back(i.first);
              }
        }
        if(v.size() > 0){
            a.push_back(v);
        }
        vector<vector<int>>ans;
        for(vector v : a){
            vector<int>c;
            int m = v.size();
            c.push_back(v[0]);
            c.push_back(v[m-1]);
            ans.push_back(c);
        }
        
        return ans;
    }
};

