// Problem link: https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
public:
    vector<int> arr;
    int last_zero_idx;
    ProductOfNumbers() {
        arr.clear();
        last_zero_idx = -1;
    }
    void add(int num) {
        if(num == 0){
            last_zero_idx = arr.size();
            arr.push_back(0);
            return;
        }
        if(arr.empty() || arr.back() == 0)
            arr.push_back(num);
        else
            arr.push_back(arr.back() * num);
    }
    
    int getProduct(int k) {
        int n = arr.size() - 1;
        int idx = n - k;

        if(idx < last_zero_idx) return 0; 
        if(idx == -1 || arr[idx] == 0) return arr[n];
        return arr[n] / arr[idx];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */