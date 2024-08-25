import java.util.Scanner;
public class HotelManagement {
    public static void menu()
    {
        System.out.println("Menu\n\t1. Ice Cream........200/-");
        System.out.println("\t2. Pasta...........500/-");
        System.out.println("\t3. Tea............100/-");
        System.out.println("\t4. Samosa............100/-");
    }
    public static double tax(int total)
    {
        double taxReturn = (total/100)*17;
        return taxReturn;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); 
        char choice;
        int total = 0;
        do {
            System.out.println("What do you want to Order:");
            menu();
            int order = sc.nextInt();
            System.out.println("Your order: ");
            switch (order) {
                
            }
            System.out.println("Do You want to order again? (y/n)");
            choice = sc.next().charAt(0);
        }while(choice!='n'&&choice!='N');
        sc.close();
    }
}
