class RandomizedSet{
    private:
    unordered_set<int> kow;
    
public:
    bool insert(int val){
        if(kow.count(val)){
            return false;
        }
        kow.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(!kow.count(val)){
            return false;
        }
        kow.erase(val);
        return true;
    }
    
    int getRandom(){
        auto p = kow.begin();
        advance(p, rand()%kow.size());
        return *p;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */