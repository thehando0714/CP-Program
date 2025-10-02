class Router {
public:
    int memLimit;
    queue<pair<int,pair<int,int>>>que;
    unordered_set<string> info;//source dest time
    unordered_map<int, vector<int>> timeST;
    Router(int memoryLimit) {
        memLimit=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key=to_string(source)+'#'+to_string(destination)+'#'+to_string(timestamp);
        if(info.count(key)){
            return false;
        }
        if(info.size()==memLimit){
            int erSo=que.front().first,erDe=que.front().second.first,erTi=que.front().second.second;
            string eraseKey=to_string(erSo)+'#'+to_string(erDe)+'#'+to_string(erTi);
            info.erase(eraseKey);
            timeST[erDe].erase(timeST[erDe].begin());
            que.pop();
            
        }
        auto it1=make_pair(destination,timestamp);
        auto it2=make_pair(source,it1);
        info.insert(key);
        que.push(it2);
        timeST[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        
        vector<int>ans;
        if(info.size()==0){
            return ans;
        }
        int qu1=que.front().first,qu2=que.front().second.first,qu3=que.front().second.second;
        ans.push_back(qu1);
        ans.push_back(qu2);
        ans.push_back(qu3);
        string eraseKey=to_string(qu1)+'#'+to_string(qu2)+'#'+to_string(qu3);
        info.erase(eraseKey);
        timeST[qu2].erase(timeST[qu2].begin());
        que.pop();
        
        return ans;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &vec = timeST[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return distance(it1, it2);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */