import java.util.Scanner;
public class Calculator {
    public static double sum(double a,double b){
        return a+b;
    }
    public static double diff(double a,double b){
        return a-b;
    }
    public static double prod(double a,double b){
        return a*b;
    }
    public static double quot(double a,double b){
        return a/b;
    }
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter first number: ");
        double x = inp.nextDouble();
        System.out.println("Enter second number: ");
        double y = inp.nextDouble();
        System.out.println("Enter the operation you want to perform.");
		System.out.print("\nEnter '+' for addition\nEnter '-' for subtraction\nEnter'*' for mulitplication\nEnter '/' for division\n");
        char op = inp.next().charAt(0);
        double result =0;
		switch(op)
		{
		case '+':
			result = sum(x,y);
			break;
		case '-':
			result = diff(x,y);
			break;
		case '*':
			result = prod(x, y);
			break;
		case '/':
			result = quot(x,y);
			break;
		default:
			System.out.println("Invalid Operator");
		}
		System.out.println(x+""+op+y+" = "+result);
    }
}
