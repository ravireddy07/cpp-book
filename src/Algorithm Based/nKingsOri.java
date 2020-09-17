import java.util.*;

public class Solution {
    boolean boards[][];
    Set<Integer> occupied_CL = new HashSet<Integer>();

    Solution(int n) {
        boards = new boolean[n][n];
    }
    Solution() {
    }

    void setBoard(boolean[][] boards) {
        this.boards = boards;
        for (int i = 0; i < boards.length; ++i) {
            for (int j = 0; j < boards.length; ++j) {
                if (boards[i][j]) {
                    occupied_CL.add(j);
                }
            }
        }
    }

int waysToPlace(int k) {
    if (k == boards.length - 1) {
        return 1;
    }
    int totalWays = 0;
    for (int pos = 0; pos < boards.length; ++pos) {
        int ways = 1;
        if (!isAttack(k + 1, pos)) {
            boards[k + 1][pos] = true;
            occupied_CL.add(pos);
            ways *= waysToPlace(k + 1);
            boards[k + 1][pos] = false;
            occupied_CL.remove(pos);
        } else {
            ways = 0;
        }
        totalWays += ways;
    }
    return totalWays;
}

boolean isAttack(int row, int col) {
    if (occupied_CL.contains(col)) {
        return true;
   }
    if ((col > 0 && row > 0 && boards[row - 1][col - 1]) || (col < boards.length - 1 && row > 0 && boards[row - 1][col + 1])) {
        return true;
    }
    return false;
}

void printArray() {
    for (int i = 0; i < boards.length; ++i) {
        for (int j = 0; j < boards.length; ++j) {
            System.out.print(boards[i][j] + " ");
        }
        System.out.println();
    }
}

public static void main(String args[]) {
    Solution sol = new Solution(4);
    System.out.println(sol.waysToPlace(-1));
    //sol.printArray();
    //readInput();
}

static void readInput() {
    Scanner scan = new Scanner(System.in);
    int t = scan.nextInt();
    for (int i = 0; i < t; ++i) {
        int n = scan.nextInt();
        //System.out.println(" n "+n );
        int k = scan.nextInt();
        // System.out.println(" k "+k );
        boolean boards[][] = new boolean[n][n];
        for (int row = 0; row < k; ++row) {
            int col = scan.nextInt();
            boards[row][col] = true;
        }
        Solution s = new Solution();
        s.setBoard(boards);
        int ways = s.waysToPlace(k - 1);
        System.out.println(ways);
        }
    }
}
