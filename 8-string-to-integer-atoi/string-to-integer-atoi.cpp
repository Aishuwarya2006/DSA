class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long res = 0;
        
        // 1. Skip whitespaces
        while (i < s.length() && s[i] == ' ') i++;
        
        // 2. Check sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }
        
        // 3. Convert digits and handle overflow
        while (i < s.length() && isdigit(s[i])) {
            res = res * 10 + (s[i++] - '0');
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
        }
        
        return (int)(res * sign);
    }
};