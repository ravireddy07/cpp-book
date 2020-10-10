// https://www.codechef.com/OCT20B/problems/DDIMMST

import java.util.*;
import java.lang.*;
import java.io.*;
import java.io.BufferedReader;

public class Main {
    static class Edge {
        int src, dest;
        long weight;

        Edge(int src, int dest, long weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        if ((line = br.readLine()) == null) {
            return;
        }
        String ff = line.substring(0, line.indexOf(" "));
        String ss = line.substring(line.indexOf(" ") + 1);

        int n = Integer.parseInt(ff);
        int d = Integer.parseInt(ss);

        ArrayList<ArrayList<Integer>> list = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            String str[] = br.readLine().split(" ");
            ArrayList<Integer> values = new ArrayList<>();
            for (int k = 0; k < str.length; ++k) {
                values.add(Integer.parseInt(str[k]));
            }
            list.add(values);
        }

        ArrayList<Edge> edges = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long weight = (diff(list.get(i), list.get(j)));
                Edge curr = new Edge(i, j, weight);
                edges.add(curr);
            }
        }

        long graph[][] = new long[n][n];

        for (int i = 0; i < edges.size(); ++i) {
            graph[edges.get(i).src][edges.get(i).dest] = edges.get(i).weight;
            graph[edges.get(i).dest][edges.get(i).src] = edges.get(i).weight;
        }

        printMST(graph);
    }

    private static long diff(ArrayList<Integer> x, ArrayList<Integer> y) {
        long diff = 0;
        for (int i = 0; i < x.size(); ++i) {
            diff += Math.abs(x.get(i) - y.get(i));
        }
        return diff;
    }

    private static void printMST(long graph[][]) {
        int v = graph.length;
        int parent[] = new int[v];
        long key[] = new long[v];
        boolean mstSet[] = new boolean[v];

        for (int i = 0; i < v; ++i) {
            key[i] = Integer.MIN_VALUE;
            mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < v - 1; ++count) {
            long u = maxKey(key, mstSet, v);
            mstSet[(int) u] = true;
            for (int j = 0; j < v; ++j) {
                if (graph[(int) u][j] != 0 && mstSet[j] == false && graph[(int) u][j] > key[j]) {
                    parent[j] = (int) u;
                    key[j] = graph[(int) u][j];
                }
            }
        }
        printMST(parent, graph, v);
    }

    private static void printMST(int[] parent, long[][] graph, int v) {
        long sum = 0;
        for (int i = 1; i < v; ++i) {
            sum += graph[parent[i]][i];
        }
        System.out.println(sum);
    }

    private static long maxKey(long[] key, boolean[] mstSet, int v) {
        long max = Integer.MIN_VALUE;
        int index = -1;

        for (int i = 0; i < v; ++i) {
            if (mstSet[i] == false && key[i] > max) {
                max = key[i];
                index = i;
            }
        }
        return index;
    }
}