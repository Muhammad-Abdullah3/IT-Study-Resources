import java.util.Scanner;
public class Calclulator {

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		System.out.print("Enter the first number: ");
		int x = inp.nextInt();
		System.out.print("\nEnter '+' for addition\nEnter '-' for subtraction\nEnter'*' for mulitplication\nEnter '/' for division\n");
		char op = inp.next().charAt(0);
		System.out.print("Enter the second number: ");
		int y = inp.nextInt();
		int result =0;
		switch(op)
		{
		case '+':
			result = x+y;
			break;
		case '-':
			result = x-y;
			break;
		case '*':
			result = x*y;
			break;
		case '/':
			result = x/y;
			break;
		default:
			System.out.println("Invalid Operator");
		}
		System.out.println(x+""+op+y+" = "+result);	
	}
}
