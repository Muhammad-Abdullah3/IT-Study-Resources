import java.util.Scanner;
public class HotelManagement {
    public static void menu()
    {
        System.out.println("Menu\n\t1. Ice Cream........200/-");
        System.out.println("\t2. Pasta...........500/-");
        System.out.println("\t3. Tea............100/-");
        System.out.println("\t4. Samosa............100/-");
    }
    public static double tax(double total)
    {
        double taxReturn = (total/100)*17;
        return total+taxReturn;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); 
        char choice;
        double total = 0;
        do {
            System.out.println("What do you want to Order:");
            menu();
            int order = sc.nextInt();
            System.out.println("Your order: ");
            switch (order) {
                case 1:
                    System.out.println("You have ordered Ice Cream.");
                    total += 200;
                    break;
                case 2:
                    System.out.println("You have ordered Pasta.");
                    total +=500;
                    break;
                case 3:
                    System.out.println("You have ordered Tea.");
                    total += 100;
                    break;
                case 4:
                    System.out.println("You have ordered Samosa.");
                    total += 100;
                    break;
            }
            System.out.println("Your total bill is: " + total);
            System.out.println("Do You want to order again? (y/n)");
            choice = sc.next().charAt(0);
        }while(choice!='n'&&choice!='N');
        System.out.println("Your total bill with tax is: " + tax(total));
        sc.close();
    }
}
