class Solution {
public:
    string customSortString(string order, string s) {
    // Define the custom comparator as lambda
        sort(s.begin(), s.end(), [order](char c1, char c2) { 
            return order.find(c1) < order.find(c2);
        });
    return s;
    }
};