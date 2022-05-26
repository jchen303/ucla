import java.util.Scanner;
import java.util.ArrayList;

public class Tower
{
    public static void main(String[] args)
    {
        Scanner discReader = new Scanner(System.in);
        System.out.print("how many disks would you like to play with? ");
        int discNum = discReader.nextInt();

        ArrayList<Of> solver = new ArrayList<Of>();

        for (int init = discNum; init > 0; init--)
        {
            Of em = new Of(init);
            solver.add(em);
        }

        Hanoi discs = new Hanoi(solver, discNum);
        discs.solve();
    }
}