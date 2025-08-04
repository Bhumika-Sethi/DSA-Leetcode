class Solution {
public:
    int countGoodNumbers(long long n) {
        // n here is length of the number
        // So for the given length n we need to return how many good numbers are possible
        // Good number = oddIndex = 2,3,5,7
        //               evenIndex = 0,2,4,6,8
        // So for a number of size n -> odd indexes = n/2
        //                           -> even indexes = (n+1)/2
        // For example: when n is odd = 5 -> odd index = 1,3 ->(5/2)
        //                                -> even index = 0,2,4  -> (5+1)/2
        //              when n is even = 6 -> odd index = 1,3,5 ->(6/2)
        //                                -> even index = 0,2,4  -> (6+1)/2

        // Here we'll be using permutation and combination
        // 5 possiblity for even
        // 4 possible for prime number
        // Multiply 5 now many evenIndex are there and 4 by number of times odd index is there
        // Formula : 5^((n+1)/2)*4(n/2);

        // Use binary exponentation as we need to reduce time complexity to O(logn) from O(n)

        long long cnt = 0;
        long long binaryFormForOddPlace = n/2;//odd place
        long long PrimeNumPermuation = 4;
        long long oddPlacesAns = 1;
        while(binaryFormForOddPlace>0){
            if(binaryFormForOddPlace%2==1){
                oddPlacesAns %= 1000000007;
                PrimeNumPermuation %= 1000000007;
                oddPlacesAns*=PrimeNumPermuation;
            }
            PrimeNumPermuation = ((PrimeNumPermuation)%(1000000007)*(PrimeNumPermuation)%(1000000007))%(1000000007);
            binaryFormForOddPlace/=2;
        }
        long long binaryFormForEvenPlace = (n+1)/2;//odd place
        long long EvenNumberPermuation = 5;
        long long evenPlacesAns = 1;
        while(binaryFormForEvenPlace>0){
            if(binaryFormForEvenPlace%2==1){
                evenPlacesAns %= 1000000007;
                EvenNumberPermuation %= 1000000007;
                evenPlacesAns*=EvenNumberPermuation;
            }
            EvenNumberPermuation = ((EvenNumberPermuation)%(1000000007)*(EvenNumberPermuation)%(1000000007))%(1000000007);
            binaryFormForEvenPlace/=2;
        }
        cnt = oddPlacesAns%(1000000007);
        evenPlacesAns%=(1000000007);
        cnt*=evenPlacesAns;
        cnt%=1000000007;
        return cnt;

    }
};