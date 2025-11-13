class SmallestInfiniteSet {
public:
    set<int>info;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            info.insert(i);
        }
    }
    
    int popSmallest() {
        int p=*info.begin();
        info.erase(info.begin());
        return p;
    }
    
    void addBack(int num) {
        info.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */