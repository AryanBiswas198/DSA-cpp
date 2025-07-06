class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int, int> mpp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto it: nums1) {
            arr1.push_back(it);
        }

        for(auto it: nums2) {
            arr2.push_back(it);
            mpp[it]++;
        }
    }
    
    void add(int index, int val) {
       mpp[arr2[index]]--;
       if(mpp.find(arr2[index]) == mpp.end()) {
        mpp.erase(arr2[index]);
       }

       arr2[index] += val;
       mpp[arr2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto it: arr1) {
            int val = tot - it;
            if(mpp.find(val) != mpp.end()) {
                cnt += mpp[val];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */