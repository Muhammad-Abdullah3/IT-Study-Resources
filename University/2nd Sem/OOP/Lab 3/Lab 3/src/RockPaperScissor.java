import java.util.Random;
import java.util.Scanner;
public class RockPaperScissor {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        int userChoice = 0;
        int score=0,turns=0;
        System.out.println("Win 1 game against computer to reach the next level: ");
        do {
            System.out.println("Enter your choice (1 for Rock, 2 for Paper, 3 for Scissor");
            System.out.println("Enter your choice: ");
            userChoice = inp.nextInt();
            Random ran = new Random();
            int computerChoice = ran.nextInt(3) + 1;
            if (computerChoice == 1) {
                System.out.println("Computer chooses: Rock");
            } else if (computerChoice == 2) {
                System.out.println("Computer chooses: Scissors");
            } else {
                System.out.println("Computer chooses: Paper");
            }

            if (userChoice == computerChoice) 
            {
                System.out.println("It's a tie.");
            } else if ((userChoice == 1 && computerChoice == 3) ||(userChoice== 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2)) 
            {
                System.out.println("Computer won the Game");
                score--;
            } else 
            {
                System.out.println("You won the Game");
                score++;
            }
            turns++;
        } while (score<5);
        System.out.println("You cleared the level in "+turns+" turns.");
        inp.close();
    }
}
