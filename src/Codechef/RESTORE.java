// https://www.codechef.com/NOV20B/problems/RESTORE

import java.lang.*;
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class Codechef 
{
    static int ll = 4000001;
    static ArrayList<Integer> primes = new ArrayList<>();
    static boolean prime[] = new boolean[ll];

    public static void generateSieve() 
    {
        for (int i = 0; i < ll; ++i)
            prime[i] = true;
        for (int j = 2; j * j < ll; ++j)
            if (prime[j])
                for (int i = j * j; i < ll; i += j)
                    prime[i] = false;

        for (int i = 2; i < ll; ++i)
            if (prime[i])
                primes.add(i);
    }
    
    public static void main(String args[]) 
    {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        generateSieve();

        while (t-- > 0) 
        {
            int n = in.nextInt();
            int ar[] = new int[n];
            ArrayList<Integer> l = new ArrayList<>();
            HashMap<Integer, Integer> map = new HashMap<>();

            for (int i = 0; i < n; ++i) 
            {
                ar[i] = in.nextInt();
                map.put(ar[i], map.getOrDefault(ar[i], 0) + 1);
            }

            for (int i = 0; i < n; ++i) 
            {
                l.add(primes.get(ar[i]));
                map.put(ar[i], map.get(ar[i]) - 1);
            }
            for (int i : l)
                System.out.print(i + " ");
            System.out.print("\n");
        }
    }
}
