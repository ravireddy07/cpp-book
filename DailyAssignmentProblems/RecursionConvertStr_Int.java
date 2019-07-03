import java.util.*;
public class Main {
    public static void main(String args[]) {
          Scanner scn = new Scanner(System.in);
          String str=scn.nextLine();
           strtoin(str,0);
    }

    public static void strtoin(String str,int number) {
        if(str.length()==0) {
            System.out.println(number);
            return;
        }
        char ch=str.charAt(0);
        number=number+(ch-48)*(int)Math.pow(10, str.length()-1);
        String ros=str.substring(1);
        strtoin(ros,number);
    }
}
