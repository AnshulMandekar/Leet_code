class Solution {
public:
    int reverse(int x){
        long reverses=0;
        while( x != 0){
            reverses = reverses*10 + x%10;
            x = x/10;
        }
        if (reverses > INT_MAX || reverses < INT_MIN) {
            return 0; // Return 0 if the reversed number overflows an integer
        }
        return reverses;
    }
};
