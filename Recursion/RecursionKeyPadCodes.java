import java.util.*;

public class Main {
   public static void main(String[] args) {
		Scanner scn=new Scanner(System.in);
		String table[]= {" ","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
		String n;
		n=scn.nextLine();
		int i=n.charAt(0)-48;
		int j=n.charAt(1)-48;

		 System.out.println(KeypadCode(table,i,j,"",0,0,0));
		}
	public static int KeypadCode(String table[],int x,int y,String result,int count,int i,int j){
		if(i==table[x].length())
		{	System.out.print(result);
			System.out.println();
			return count;
		}
		if(j==table[y].length())
		{
			return KeypadCode(table,x,y,result,count,i+1,0);
		}
		return KeypadCode(table,x,y,result+table[x].charAt(i)+table[y].charAt(j)+" ",count+1,i,j+1);
	}
}
