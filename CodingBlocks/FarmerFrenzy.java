import java.util.*;
public class main {
  static int maxHist(int R,int C,int row[]) {
    Stack<Integer> result = new Stack<Integer>();
    int top_val;
    int max_area = 0, area = 0,i = 0;
    while(i<C) {
      if(result.empty() || row[result.peek()] <= row[i])
           result.push(i++);
      else {
        top_val = row[result.peek()];
        result.pop();
        area = top_val*i;
        if (!result.empty())
            area = top_val*(i-result.peek()-1);
            max_area = Math.max(area, max_area);
      }
    }

    while(!result.empty()) {
      top_val = row[result.peek()];
      result.pop();
      area = top_val * i;
      if(!result.empty())
          area = top_val * (i - result.peek() - 1 );
          max_area = Math.max(area, max_area);
        }
        return max_area;
    }
    static int maxRectangle(int R,int C,int A[][]) {
        int result = maxHist(R,C,A[0]);
        for(int i=1;i<R;i++) {
            for(int j=0;j<C;j++)
                if (A[i][j] == 1) A[i][j] += A[i - 1][j];
            result = Math.max(result, maxHist(R,C,A[i]));
        }
        return result;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        int[][] mat = new int[r][c];
        for(int i =0;i<r;i++){
            for(int j = 0;j<c;j++){
                mat[i][j]=sc.nextInt();
            }
        }
        System.out.println(maxRectangle(r,c,mat));
    }
}
