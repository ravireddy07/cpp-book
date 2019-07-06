import java.io.*;
import java.util.*;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


class TestClass {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static class Node {
        Character data;
        boolean isTerminal;
        Node[] children;

        Node(Character data, boolean isTerminal) {
            this.data = data;
            this.isTerminal = isTerminal;
            this.children = new Node[26];
            for(int i=0;i<26;i++) {
                this.children[i]=null;
            }
        }
    }
    public static TestClass p = new TestClass();
    public Node root;
    public static PrintWriter pw = new PrintWriter(System.out);
    TestClass() {
        this.root = new Node('\0', false);
    }

    public static void addword(Node root, String s) {
        if (s.length() == 0) {
            if(!root.isTerminal) {
                root.isTerminal = true;
            }
            return;
        }
        Node child;
        int idx = s.charAt(0) - 'a';
        if (root.children[idx] != null) {
            child = root.children[idx];
        } else {
            child = new Node(s.charAt(0), false);
            root.children[idx] = child;
        }

        addword(child, s.substring(1));

    }

    public static void searchWord(Node parent, String word, String original) {
        if (word.length() == 0) {
            if(parent.isTerminal) {
                pw.println(original);
                pw.flush();
            }
            numberOfString(parent, original);
            return;
        }
        Character ch = word.charAt(0);
        int idx = word.charAt(0) - 'a';
        String ros = word.substring(1);
        Node child = parent.children[idx];
        if (child == null) {
            System.out.println("No suggestions");
            addword(p.root, original);
            return;
        }
        searchWord(child, ros, original);
    }

    public static int numberOfString(Node parent, String str) {
        if (parent == null) {
            return 0;
        }
        int result = 0;
        for (int i=0;i<parent.children.length;i++) {
            if(parent.children[i]==null) {
                continue;
            }
            if (parent.children[i].isTerminal) {
                pw.println(str + parent.children[i].data);
                pw.flush();
                result++;
            }
            result += numberOfString(parent.children[i], str + parent.children[i].data);
        }
        return result;
    }

    public static void main(String[] args) {
        FastReader scn = new FastReader();
        int n = scn.nextInt();

        while (n-- > 0) {
            addword(p.root, scn.next());
        }
        int q = scn.nextInt();
        while (q-- > 0) {
            String s=scn.next();
            searchWord(p.root, s, s);
        }
    }
}
