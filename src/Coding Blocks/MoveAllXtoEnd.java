import java.util.*;

public class MoveX_End {
  static String MoveX(String str) {
		String endVar = "x", str1 = "", str2 = "";

		for (int i=0;i<str.length();++i) {
		    char curr = str.charAt(i);
		    if (String.valueOf(curr).matches(endVar)) {
		        str1 = str1 + curr;
		    }
		    else {
		        str2 = str2 + curr;
		    }
		}
		return str2 + str1;
	}

	public static void main(String[] args)
	{
	    Scanner sc = new Scanner(System.in);
		String str  = sc.nextLine();
		System.out.println(MoveX(str));
	}
}
