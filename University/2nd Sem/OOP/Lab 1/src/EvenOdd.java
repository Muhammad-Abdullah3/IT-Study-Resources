import java.util.Scanner;
public class EvenOdd {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int num = inp.nextInt();
        if(num%2==0){
            num = num*10;
            System.out.println("Number is even.");
            System.out.println("Number after multiplication is: "+num);
        }
        else{
            num = num*num;
            System.out.println("Number is odd.");
            System.out.println("Number after squaring is: "+num);
        }
    }

}
