class ProductOfNumbers {
public:
    vector<int> prod;
    int last0;
    ProductOfNumbers() {
        prod.push_back(1);
        last0 = -1;
    }

    void add(int num) {
        int n = prod.size();
        if (num == 0) {
            prod.clear();
            prod.push_back(1);
            int nw = prod.size();
            last0 = nw - 1;
        } else {
            prod.push_back(prod.back() * num); // prod.back()= prod[n-1]
        }
    }

    int getProduct(int k) {
        int n = prod.size();
        return (n - 1 - k < last0) ? 0 : prod.back() / prod[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */