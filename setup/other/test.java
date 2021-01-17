import java.util.*;
import java.util.Scanner;

public class test {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int n, m, x;
        TreeSet<Integer> V = new TreeSet<Integer>();
        Stack<Integer> tempStore = new Stack<Integer>();
        while (t-- != 0) {
            V.clear();
            V.add(0);
            tempStore.clear();
            tempStore.push(0);

            n = in.nextInt();
            m = in.nextInt();

            int a[] = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = in.nextInt();
            int b[] = new int[m];
            for (int i = 0; i < m; ++i)
                b[i] = in.nextInt();

            while (!tempStore.isEmpty()) {
                x = (int) (tempStore.pop());
                for (int i = 0; i < n; ++i) {
                    if (!V.contains(x | a[i])) {
                        V.add(x | a[i]);
                        tempStore.push(x | a[i]);
                    }
                }
                for (int i = 0; i < m; ++i) {
                    if (!V.contains(x & b[i])) {
                        V.add(x & b[i]);
                        tempStore.push(x & b[i]);
                    }
                }
            }
            System.out.println(V.size());
            // in.close();
        }
    }
}
