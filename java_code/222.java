import java.math.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Int k = in.nextInt();
        int[] b = new int[n];
        for (int i = 0; i < n; ++i) b[i] = in.nextInt();
        Arrays.sort(b);
        BigInteger[] ans = new BigInteger[b.length + 1];
        ans[0] = BigInteger.ONE;
        for(int i = 1; i <= n; i++) {
            ans[i] = BigInteger.ZERO;
            for(int j = i; j >= 1; j--) {
                if(b[i - 1] > j - 1) {
                    ans[j] = ans[j].add(ans[j - 1].multiply(BigInteger.valueOf(b[i - 1] - j + 1)));
                }
            }
        }
        System.out.println(k > n ? 0 : ans[k]);
    }
}
