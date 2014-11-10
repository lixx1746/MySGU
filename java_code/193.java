import java.math.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger n = in.nextBigInteger();
        BigInteger two = BigInteger.ONE.add(BigInteger.ONE), ans;
        BigInteger half = n.divide(two);
        if(n.mod(two).equals(BigInteger.ZERO)) {
          if(half.mod(two).equals(BigInteger.ZERO)) {
            ans = half.subtract(BigInteger.ONE);
          }
          else {
              ans =  half.subtract(two);
          }
        }
        else {
            ans = half;
        }
        System.out.println(ans);
    }
}
