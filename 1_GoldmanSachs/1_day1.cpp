// Day1 Problem 1
// GoldmanSachs 
// https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/


class Solution {
public:
    long gcd(int a, int b){
        if(b==0)    return a;
        return gcd(b,a%b);
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        

        int l = 1, r = 2*(uniqueCnt1+uniqueCnt2);
        while(l<=r){
            int mid = l + ((r-l)>>1);
            // or built in lcm function
            long lcm = (long)(divisor1)*(long)(divisor2)/gcd(divisor1,divisor2); 
            long a = mid - mid/divisor1;
            long b = mid - mid/divisor2;
            long c2 = mid - mid/lcm; // a+b-c ,, c = mid - mid/div1 -mid/div2 + mid/lcm;

            if(a>=uniqueCnt1 && b>=uniqueCnt2 && c2>=uniqueCnt1+uniqueCnt2){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};