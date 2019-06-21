import java.util.*;

class targetsubset {
	public static void main(String[] args) {
		int n=5;
        Scanner s1 = new Scanner(System.in);
        //n = s1.nextInt();
        int ar[] = new int[n];
		
		for(int i=0;i<n;i++){
			ar[i] = s1.nextInt();
		}
		int tar = s1.nextInt();

		targetSubset(ar, n, tar, " ");
	}

	public static void targetSubset(int[] arr, int si, int target, String osf) {
		if (si == arr.length) {
			if (target == 0) {
				System.out.println(osf);
			}
			return;
		}
		targetSubset(arr, si + 1, target, osf);
		targetSubset(arr, si + 1, target - arr[si], osf + arr[si] + " ");
	}
}
