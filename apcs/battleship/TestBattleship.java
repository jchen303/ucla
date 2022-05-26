import java.util.Scanner;

public class TestBattleship
{
    public static void main(String[] args)
    {
        Scanner gotGames = new Scanner(System.in);
        System.out.println("would you like to blow up some ships?");
        String yesOrNo = gotGames.nextLine();
    
        if (!yesOrNo.equalsIgnoreCase("no"))
        {
            Battleship ussChen = new Battleship();

            while (!ussChen.allSunk())
            {
                System.out.println("please enter a guess");
                String hitOrMiss = gotGames.nextLine();
                System.out.println(ussChen.guess(hitOrMiss));
            }
        }

        else
            System.out.println("too bad");
    }
}