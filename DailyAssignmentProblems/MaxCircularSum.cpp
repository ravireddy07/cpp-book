import java.util.*;

public class maxCircularSum {
     public static void main(String[] args){

    Scanner scn = new Scanner(System.in);

    int t;
    t = scn.nextInt();
    while(t>0){

        int n = scn.nextInt();

        int[] arr = new int[n];

        for(int i =0;i < n;i++)
            arr[i] = scn.nextInt();

        System.out.println(maxSum(arr));

        t--;
    }
  }

  public static int maxSum(int[] arr){

    int max_kadane = kadanes(arr);

    int max_wrap = 0;

    for(int i =0;i < arr.length;i++){
        max_wrap += arr[i];
        arr[i] = -arr[i];
    }

    int non_contib_sum = kadanes(arr);
    max_wrap = max_wrap + non_contib_sum;

    return (max_wrap > max_kadane?max_wrap:max_kadane);

  }

    public static int kadanes(int[] A) {

        int max_so_far = 0;
        int max_ending_here = 0;


        for(int i = 0;i < A.length;i++){

            max_ending_here += A[i];

            if(max_ending_here < 0){
                max_ending_here = 0;
            }

            if(max_so_far < max_ending_here){
                max_so_far = max_ending_here;
            }
        }

        return max_so_far;



    }
}
