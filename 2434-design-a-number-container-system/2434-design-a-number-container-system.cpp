class NumberContainers {
public:

    std::unordered_map<int, int> nums;
    std::unordered_map<int, std::set<int>> inds;

    NumberContainers() {
    }
    
    void change(int index, int number) {
        if (nums.find(index) != nums.end()) {
            inds[nums[index]].erase(index);
        }
        nums[index] = number;
        inds[number].emplace(index);
    }
    
    int find(int number) {
        if (inds[number].empty()) {
            return -1;
        }
        return *(inds[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */