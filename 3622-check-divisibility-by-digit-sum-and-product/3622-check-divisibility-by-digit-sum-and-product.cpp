class Solution {
public:
    bool checkDivisibility(int n) {
        if(n<9){
            return false;
        }
        else{
            int sum = 0;
            int product = 1;
            int orgn = n;
            while(n>0){
                int unit_digit = n % 10;
                sum+= unit_digit;
                product = product * unit_digit;
                n = n/10;
            }
            int sumplusproduct = sum + product;
            if(orgn % sumplusproduct == 0){
                return true;
            }
            else{
                return false;
            }
        }return false;
        
    }
};