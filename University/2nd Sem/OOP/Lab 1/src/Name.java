import java.util.Scanner;
public class Name {
    public static void main(String[] args)
    {
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter your name:");
        String name = inp.nextLine();
        for(int i=0;i<100;i++)
        {
            System.out.println(name);
        }
        inp.close();
    }

}
