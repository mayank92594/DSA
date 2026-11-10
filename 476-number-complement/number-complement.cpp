class Solution {
public:
    int findComplement(int num) {
        string sum = "";

        while(num > 0) {
            if(num % 2 == 1)
                sum += '0';
            else
                sum += '1';

            num /= 2;
        }

        reverse(sum.begin(), sum.end());

        int ans = 0;
        int power = 0;

        for(int i = sum.size()-1; i >= 0; i--) {
            ans += (sum[i] - '0') * pow(2, power);
            power++;
        }

        return ans;
    }
};