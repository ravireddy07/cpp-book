import java.io.IOException;
import java.util.Scanner;

class Fractional_Knapsack {
    public static void main(String args[]) throws IOException {
        int i,j=0,max_qty,m,n;
        float sum=0,max;
        Scanner sc = new Scanner(System.in);
        int array[][]=new int[2][20];
        n=sc.nextInt();
        max_qty=sc.nextInt();

        for(i=0;i<n;i++)
            array[1][i]=sc.nextInt();
        for(i=0;i<n;i++)
            array[0][i]=sc.nextInt();

        m=max_qty;
        while(m>=0)
        {
            max=0;
            for(i=0;i<n;i++)
            {
                if(((float)array[1][i])/((float)array[0][i])>max)
                {
                    max=((float)array[1][i])/((float)array[0][i]);
                    j=i;
                }
            }
            if(array[0][j]>m)
            {
                //System.out.println((j+1));
                //System.out.println(m);
                sum+=m*max;
                m=-1;
            }
            else
            {
                //System.out.println("Quantity of item number: " + (j+1) + " added is " + array[0][j]);
                m-=array[0][j];
                sum+=(float)array[1][j];
                array[1][j]=0;
            }
        }
        System.out.println("The total profit is " + sum);
        sc.close();
    }
}
