class Solution {
public:
    string intToRoman(int num) {
        // Vector of pairs to store the Roman numeral symbols and their corresponding values
        vector<pair<int, string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string result = ""; // Initialize result string

        // Iterate over the Roman numeral values
        for (const auto& [value, symbol] : roman) {
            while (num >= value) {
                result += symbol; // Append the Roman numeral to the result
                num -= value;     // Subtract the value from the input number
            }
        }

        return result; // Return the final Roman numeral representation
    }
};
