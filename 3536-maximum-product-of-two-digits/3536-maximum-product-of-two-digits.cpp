class Solution {
public:
    int maxProduct(int n) {
        int first_max = INT_MIN;
        int second_max = INT_MIN;

        while (n > 0) {
            int last_digit = n % 10;

            if (last_digit > first_max) {
                second_max = first_max;
                first_max = last_digit;
            }
            else if (last_digit > second_max) {
                second_max = last_digit;
            }

            n = n / 10;
        }

        return first_max * second_max;
    }
};