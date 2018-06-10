int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   if (n == 0) 
   return 1%d;
    long long val = 1;
    long long powerto = x;
	while (n > 0)
	{
        if (n % 2 == 1) {
            val=(val*powerto)%d;
            n--;
        } 
		else {
            powerto=(powerto*powerto)%d;
            n=n/2;
        }
    }
    if (val<0) 
    val = (val+d) % d;
    return val;
}
