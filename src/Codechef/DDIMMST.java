// https://www.codechef.com/OCT20B/problems/DDIMMST

import java.util.*;
import java.lang.*;
import java.io.*;
import java.io.BufferedReader;

public class Main {
    static long getDiff(ArrayList<Integer> line1, ArrayList<Integer> line2) {
        long res = 0;
        for (int i = 0; i < line1.size(); ++i)
            res += Math.abs(line1.get(i) - line2.get(i));
        return res;
    }
    
    static class Node {
        int val1, val2;
        long weight;

        Node(int v1, int v2, long w) {
            this.val1 = v1;
            this.val2 = v2;
            this.weight = w;
        }
    }
    
    static long getValue(long[] key, boolean[] tree, int s) {
        long val = Integer.MIN_VALUE;
        int res = -1;

        for (int i = 0; i < s; ++i) {
            if (tree[i] == false && key[i] > val) {
                val = key[i];
                res = i;
            }
        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;
        if ((input = br.readLine()) == null)
            return;
        
        String nn = input.substring(0, input.indexOf(" "));
        int n = Integer.parseInt(nn);

        String dd = input.substring(input.indexOf(" ") + 1);
        int d = Integer.parseInt(dd);
        
        ArrayList<ArrayList<Integer>> DSpace = new ArrayList<>();
        ArrayList<Node> aDiff = new ArrayList<>();
        long g[][] = new long[n][n];
        int parent[] = new int[g.length];
        long key[] = new long[g.length];
        boolean tree[] = new boolean[g.length];

        for (int i = 0; i < n; ++i) {
            String in[] = br.readLine().split(" ");
            ArrayList<Integer> temp = new ArrayList<>();
            for (int k = 0; k < in.length; ++k)
                temp.add(Integer.parseInt(in[k]));
            DSpace.add(temp);
        }

        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long w = (getDiff(DSpace.get(i), DSpace.get(j)));
                Node f = new Node(i, j, w);
                aDiff.add(f);
            }
        }

        for (int i = 0; i < aDiff.size(); ++i) {
            g[aDiff.get(i).val1][aDiff.get(i).val2] = aDiff.get(i).weight;
            g[aDiff.get(i).val2][aDiff.get(i).val1] = aDiff.get(i).weight;
        }

        for (int i = 0; i < g.length; ++i) {
            key[i] = Integer.MIN_VALUE;
            tree[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int i = 0; i < g.length - 1; ++i) {
            long ans = getValue(key, tree, g.length);
            tree[(int) ans] = true;
            for (int j = 0; j < g.length; ++j) {
                if (g[(int) ans][j] != 0 && tree[j] == false && g[(int) ans][j] > key[j]) {
                    parent[j] = (int) ans;
                    key[j] = g[(int) ans][j];
                }
            }
        }

        long res = 0;
        for (int i = 1; i < g.length; ++i)
            res += g[parent[(int) i]][(int) i];

        System.out.print(res + "\n");
        return;
    }
}