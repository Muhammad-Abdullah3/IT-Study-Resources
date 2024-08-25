import java.util.Scanner;
public class Concat {
    public static String concat(String firstName,String lastName) {
        return firstName + " " + lastName;
    }
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter your First Name here: ");
        String fName = inp.nextLine();
        System.out.println("Enter your Last Name here: ");
        String lName = inp.nextLine();
        System.out.println("Your Full Name is: " + concat(fName,lName));
    }
}
