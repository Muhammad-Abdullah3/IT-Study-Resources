import java.util.Scanner;
public class Main {
    public static void main(String[] args)
    {
        Scanner inp = new Scanner(System.in);
        int[] arr = new int[10];
        System.out.println("Enter array elements from here on out.");
        for(int i=0;i<10;i++)
        {
            arr[i] = inp.nextInt();
        }
        System.out.println("Maximum Element of the array is: "+MinMax.max(arr));
        System.out.println("Minimum Element of the array is: "+MinMax.min(arr));
    }
}
