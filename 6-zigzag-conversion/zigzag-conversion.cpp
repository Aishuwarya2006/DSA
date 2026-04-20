class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            // Change direction
            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;

            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows
        string result = "";
        for (string row : rows) {
            result += row;
        }

        return result;
    }
};