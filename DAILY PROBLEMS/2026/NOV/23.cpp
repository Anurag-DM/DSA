// 1352. Product of the Last K Numbers
// Time : O(n)
// Space : O(n)
class ProductOfNumbers {
public:
    vector<int> prod;

    ProductOfNumbers() {

    }
    
    void add(int num) {
        if(num == 0)
            prod.clear();
        else{
            if(prod.empty())
                prod.push_back(num);
            else
                prod.push_back(num * prod.back());
        }
            
    }
    
    int getProduct(int k) {
        int n = prod.size();

        if(n - k < 0)
            return 0;
        else if(n - k == 0)
            return prod[n - 1];
        else
            return prod[n - 1] / prod[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */