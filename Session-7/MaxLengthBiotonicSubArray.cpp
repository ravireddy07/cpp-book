import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int t=scn.nextInt();
        while(t-- > 0) {
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        System.out.println(bitonic(arr));
        }
    }

    public static int bitonic(int arr[])
    {
        int n=arr.length;
        int[] inc = new int[n];

        int[] dec = new int[n];
        int max;

        inc[0] = 1;
        dec[n-1] = 1;
        for (int i = 1; i < n; i++)
           inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;
        for (int i = n-2; i >= 0; i--)
            dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;
        max = inc[0] + dec[0] - 1;
        for (int i = 1; i < n; i++)
            if (inc[i] + dec[i] - 1 > max)
                max = inc[i] + dec[i] - 1;

        return max;
    }

}
