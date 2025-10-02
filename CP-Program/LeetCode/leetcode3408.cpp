class TaskManager {
public:
    map<pair<int,int>,int>allInfo;//(-pri,-task,user)
    map<int,int>extra;//(task,pri)
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            auto it=make_pair(-tasks[i][2],-tasks[i][1]);
            allInfo[it]=tasks[i][0];
            extra[tasks[i][1]]=tasks[i][2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        
        auto it1=make_pair(-priority,-taskId);
        allInfo[it1]=userId;
        extra[taskId]=priority;
    }
    
    void edit(int taskId, int newPriority) {
        
        int user=allInfo[{-extra[taskId],-taskId}];
        allInfo.erase({-extra[taskId],-taskId});
        allInfo[{-newPriority,-taskId}]=user;
        
        extra[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        allInfo.erase({-extra[taskId],-taskId});
        extra.erase(taskId);
    }
    
    int execTop() {
        if(allInfo.size()==0){
            return -1;
        }
        int top=-allInfo.begin()->first.second,res=allInfo.begin()->second;//2 3 4 5
        extra.erase(top);
        allInfo.erase(allInfo.begin());
        return res;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */