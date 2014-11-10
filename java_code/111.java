import java.math.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger n = in.nextBigInteger();
        BigInteger l = BigInteger.ONE;
        BigInteger r = n.shiftRight(1).add(BigInteger.ONE);
        while(l.compareTo(r) <= 0) {
            BigInteger mid = l.add(r).shiftRight(1);
            BigInteger ans = mid.pow(2);
            if(ans.compareTo(n) == 0) { System.out.println(mid); return; }
            else if(ans.compareTo(n) < 0) l = mid.add(BigInteger.ONE);
            else r = mid.add(BigInteger.ONE.negate());
        }
        System.out.println(r);
    }

}
