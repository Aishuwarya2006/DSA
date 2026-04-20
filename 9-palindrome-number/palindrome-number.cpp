class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // 1. Negative numbers are not palindromes (e.g., -121 != 121-).
        // 2. Numbers ending in 0 are not palindromes unless the number is 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = (reversedHalf * 10) + (x % 10);
            x /= 10;
        }

        // For even-length numbers: x == reversedHalf (e.g., 1221 -> 12 == 12)
        // For odd-length numbers: x == reversedHalf / 10 (e.g., 121 -> 1 == 12/10)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};