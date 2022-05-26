public class Battleship
{
    private int numGuesses; // when i hit line 300 i figured that once again i've failed to reach the simple solution
    private String[] twoShip; // made a whoooooole lot of mistakes... but learned some stuff too
    private String[] threeShip; // sorry in advance if (when?) this gives you a headache when grading
    private String[] anothaThreeShip;
    private String[] fourShip;      // i just hit one out of bounds exception but its too late to fix it now
    private String[] fiveShip;     // and it happaned once out of like 20 runs  
    private String[][] gameboard; // it bothered me so i added something that i think will fix it but not sure 
    private String[][] userBoard;// since it only happened once but odds are this'll work for you (i hope) 

    String twoSunk;
    String threeSunk;
    String fourSunk;
    String fiveSunk;
    String anothaThreeSunk;

    public Battleship()
    {
        int charNum = 65;
        numGuesses = 0;

        twoSunk = "you sunk my two ship! "; // sink messages
        threeSunk = "you sunk my first three ship! ";
        fourSunk = "you sunk my four ship! ";
        fiveSunk = "you sunk my five ship! ";
        anothaThreeSunk = "you sunk my second three ship! ";

        twoShip = new String[] {"2", "2"}; // the ships
        threeShip = new String[] {"3", "3", "3"};
        fourShip = new String[] {"4", "4", "4", "4",};
        fiveShip = new String[] {"5", "5", "5", "5", "5"};
        anothaThreeShip = new String[] {"6", "6", "6"};

        gameboard = new String[11][11];
        gameboard[0][0] = " ";

        for (int gameboardInit = 1; gameboardInit < gameboard.length; gameboardInit++) // initialize gameboard
        {
            gameboard[0][gameboardInit] = "" + (char)(charNum);
            gameboard[gameboardInit][0] = "" + gameboardInit;

            for (int boardInit = 1; boardInit < gameboard[gameboardInit].length; boardInit++)
                gameboard[gameboardInit][boardInit] = "?";
                
            charNum++;
        }

        userBoard = new String[11][11];
        userBoard[0][0] = " ";
        charNum = 65;

        for (int userBoardInit = 1; userBoardInit < userBoard.length; userBoardInit++) // initialize userBoard
        {
            userBoard[0][userBoardInit] = "" + (char)(charNum);
            userBoard[userBoardInit][0] = "" + userBoardInit;

            for (int boardInit = 1; boardInit < userBoard[userBoardInit].length; boardInit++)
                userBoard[userBoardInit][boardInit] = "?";
            
            charNum++;
        }

        shipPlacer(twoShip);
        shipPlacer(threeShip);
        shipPlacer(fourShip);
        shipPlacer(fiveShip);
        shipPlacer(anothaThreeShip);
    }

    public String guess(String theGuess)
    {
        String guessLetter = (theGuess.substring(0, 1).toUpperCase()); // takes in user guess and converts to numbers for the array
        String guessNumber = (theGuess.substring(1, 2));

        int actualGuessNumber = Integer.parseInt(guessNumber);
        int actualGuessLetter = (int)(guessLetter.charAt(0)) - 64;

        if (!gameboard[actualGuessNumber][actualGuessLetter].equals("?"))
        {
            gameboard[actualGuessNumber][actualGuessLetter] = "X";
            userBoard[actualGuessNumber][actualGuessLetter] = "X";
            numGuesses++;
            // hey mr joo! keep up the good work! print this if you want to see the answers
            // System.out.println("computer board: ");
            // for (int row = 0; row < gameboard.length; row++)
            // {
            //     if (colm == 0)
            //     {
            //         if (row != 10)
            //             System.out.print(gamebaord[row][colm] + "     ");
            //         else
            //             System.out.print(gameboard[row][colm] + "    ");
            //     }
            //     else
            //         System.out.print(gameboard[row][colm] + "   ");
            // }

            // if (row == 0)
            //     System.out.print("\n" + "\n" + "\n");
            // else
            //     System.out.print("\n" + "\n");
            // }
    
            // System.out.println("");

            // System.out.println("user board: ");
            for (int row = 0; row < userBoard.length; row++)
            {
                for (int colm = 0; colm < userBoard[0].length; colm++)
                {
                    if (colm == 0)
                    {
                        if (row != 10)
                            System.out.print(userBoard[row][colm] + "     ");
                        else
                            System.out.print(userBoard[row][colm] + "    ");
                    }
                    else
                        System.out.print(userBoard[row][colm] + "   ");
                }

                if (row == 0)
                    System.out.print("\n" + "\n" + "\n");
                else
                    System.out.print("\n" + "\n");
            }
    
            System.out.println("");

            if (numOShips(twoShip) == 0) 
                {
                    System.out.print(twoSunk);
                    twoSunk = "";
                }
            if (numOShips(threeShip) == 0)
                {
                    System.out.print(threeSunk);
                    threeSunk = "";
                }
            if (numOShips(fourShip) == 0)
                {
                    System.out.print(fourSunk);
                    fourSunk = "";
                }
            if (numOShips(fiveShip) == 0)
                {
                    System.out.print(fiveSunk);
                    fiveSunk = "";
                }
            if (numOShips(anothaThreeShip) == 0)
                {
                    System.out.print(anothaThreeSunk);
                    anothaThreeSunk = "";
                }

            else if (allSunk())
            {
                    return ("congratulations! you sunk all the battleships! \nyou took " + numGuesses + " guesses!");
            }
            
            return "hit!";
        }

        else
        {
            gameboard[actualGuessNumber][actualGuessLetter] = "O";
            userBoard[actualGuessNumber][actualGuessLetter] = "O";
            numGuesses++;
            // answer print below
            // System.out.println("computer board: ");
            // for (int row = 0; row < gameboard.length; row++)
            // {
                // for (int colm = 0; colm < gameboard[0].length; colm++)
                // {
                //     if (colm == 0)
                //     {
                //         if (row != 10)
                //             System.out.print(gamebaord[row][colm] + "     ");
                //         else
                //             System.out.print(gameboard[row][colm] + "    ");
                //     }
                //     else
                //         System.out.print(gameboard[row][colm] + "   ");
                // }

                // if (row == 0)
                //     System.out.print("\n" + "\n" + "\n");
                // else
                //     System.out.print("\n" + "\n");
            // }
    
            // System.out.println("");

            // System.out.println("user board: ");
            for (int row = 0; row < userBoard.length; row++)
            {
                for (int colm = 0; colm < userBoard[0].length; colm++)
                {
                    if (colm == 0)
                    {
                        if (row != 10)
                            System.out.print(userBoard[row][colm] + "     ");
                        else
                            System.out.print(userBoard[row][colm] + "    ");
                    }
                    else
                        System.out.print(userBoard[row][colm] + "   ");
                }

                if (row == 0)
                    System.out.print("\n" + "\n" + "\n");
                else
                    System.out.print("\n" + "\n");
            }
    
            System.out.println("");

            return "miss"; 
        }
    }

    private void shipPlacer(String[] theShip)
    {
        int letterCoord = 0;
        int numberCoord = 0; 
        String startingPoint = "";

        while (occupied(numberCoord, letterCoord)) // determines starting point for each ship
        {
            letterCoord = (int)(randomChar()) - 64;
            numberCoord = randomNum();
        }

        gameboard[numberCoord][letterCoord] = theShip[0];

        while (numOShips(theShip) <= theShip.length - 1) // make it so the starting point OR the second point adds or subtracts the row or column
        {
            startingPoint = numConverter(numberCoord, letterCoord);
            String newCoordinates = possibleMoves(startingPoint, theShip);
            int newNumber = Integer.parseInt(newCoordinates.substring(0, 2));
            int newLetter = Integer.parseInt(newCoordinates.substring(2, 4));

            if (newLetter > 11)
                newLetter = newLetter - 90;
            if (newNumber > 11)
                newNumber = newNumber - 90;
            
            if (!occupied(newNumber, newLetter))
                gameboard[newNumber][newLetter] = theShip[0]; // second point

            while (overlap(theShip))
            {
                for (int row = 1; row < gameboard.length; row++)
                {
                    for (int column = 1; column < gameboard[row].length; column++)
                    {
                        if (gameboard[row][column].equals(theShip[0]))
                            gameboard[row][column] = "?";   // reset that ship if it's overlapping
                    }
                }
                shipPlacer(theShip); // place ship until overlap is gone
            }
        }
    }

    private String possibleMoves(String startPoint, String[] theShip) 
    {
        int shipNumber = Integer.parseInt(startPoint.substring(0, 2));
        int shipLetter = Integer.parseInt(startPoint.substring(2, 4));

        if (shipLetter > 12)
            shipLetter = shipLetter - 90;
        if (shipNumber > 12)
            shipNumber = shipNumber - 90;

        int switchNum = 37;

        if (shipInRow(theShip) && numOShips(theShip) <= theShip.length - 1) // if there's more than 2 of the ship point in the row,                                                                      // it limits the switch case to adding or subtracting a row
        {                                                                  // it limits the switch case to adding or subtracting a column
            if (shipLetter != 0)
            {
                if (!occupied(shipNumber, shipLetter - 1)) // is the second point occupied
                    switchNum = 2;
            }

            if (shipLetter != 10)
            {
                if (!occupied(shipNumber, shipLetter + 1)) // is the second point occupied
                    switchNum = 1;
            }

            if (occupied(shipNumber, shipLetter - 1) && occupied(shipNumber, shipLetter + 1)) // are the successive points occupied
            {                                                                                // where can you next place a ship point
                if (!occupied(shipNumber, freeSpace(theShip, shipLetter, shipNumber, 2)))
                    switchNum = 2;
    
                if (!occupied(shipNumber, freeSpace(theShip, shipLetter, shipNumber, 1)))
                    switchNum = 1;
            }
        }

        if (shipInColumn(theShip) && numOShips(theShip) <= theShip.length - 1) // if there's more than 2 of the ship point in the column,
        {                                                                     // it limits the switch case to adding or subtracting a row
            if (shipNumber != 10)
            {
                if (!occupied(shipNumber + 1, shipLetter)) // is the second point occupied
                    switchNum = 4;
            }

            if (shipNumber != 0)
            {
                if (!occupied(shipNumber - 1, shipLetter)) // is the second point occupied
                    switchNum = 3;
            }

            if (occupied(shipNumber + 1, shipLetter) && occupied(shipNumber - 1, shipLetter)) // are the successive points occupied
            {                                                                                // where can you next place a ship point
                if (!occupied(freeSpace(theShip, shipLetter, shipNumber, 4), shipLetter))
                    switchNum = 4;
    
                if (!occupied(freeSpace(theShip, shipLetter, shipNumber, 3), shipLetter))
                    switchNum = 3;
            }
        }

        while (switchNum > 4) // get a random num from 1-4 for the switch case
            switchNum = randomNum();

        switch (switchNum)
        {
            case 1: 
                if (shipLetter != 10) 
                {
                    if (numOShips(theShip) >= 2)
                    {
                        do
                            shipLetter = shipLetter + 1; // next point is a column to the right
                        while (occupied(shipNumber, shipLetter) && shipLetter <= 10);
                        break;
                    }
                    shipLetter = shipLetter + 1;
                        break;
                }

            case 2:
                if (shipLetter != 1)
                {
                    if (numOShips(theShip) >= 2)
                    {
                        do
                            shipLetter = shipLetter - 1; // next point is a column to the left
                        while (occupied(shipNumber, shipLetter) && shipLetter >= 1);
                        break;
                    }
                    shipLetter = shipLetter - 1;
                        break;
                }

            case 3: 
                if (shipNumber != 1)
                {
                    if (numOShips(theShip) >= 2)
                    {
                        do
                            shipNumber = shipNumber - 1; // next point is a row up
                        while (occupied(shipNumber, shipLetter) && shipNumber >= 1);
                        break;
                    }
                    shipNumber = shipNumber - 1;
                        break;
                }

            case 4:
                if (shipNumber != 10)
                {
                    if (numOShips(theShip) >= 2)
                    {
                        do 
                            shipNumber = shipNumber + 1; // next point is a row down
                        while (occupied(shipNumber, shipLetter) && shipNumber <= 10);
                        break;
                    }
                    shipNumber = shipNumber + 1;
                        break;
                }
        }

        return (numConverter(shipNumber, shipLetter));
    }

    private int freeSpace(String[] theShip, int shipLett, int shipNumb, int switchCaseNum) // see if there's an available spot to place a ship point
    {
        if (switchCaseNum == 3)
        {
            while (occupied(shipNumb, shipLett) && shipNumb != 1)
                shipNumb = shipNumb - 1;
            return shipNumb;
        }

        if (switchCaseNum == 4)
        {
            while (occupied(shipNumb, shipLett) && shipNumb != 10)
                shipNumb = shipNumb + 1;
            return shipNumb;
        }

        if (switchCaseNum == 2)
        {
            while (occupied(shipNumb, shipLett) && shipLett != 1)
                shipLett = shipLett - 1;
            return shipLett;
        }

        if (switchCaseNum == 1)
        {
            while (occupied(shipNumb, shipLett) && shipLett != 10)
                shipLett = shipLett + 1;
            return shipLett;
        }
        return 0;
    }

    private boolean overlap(String[] theShip)
    {
        int numbOfShips = 0;
        int theRow = 0;
        int theColm = 0;
        String lapCheck = "";
        String addUp = "";
        boolean overflow = false; 

        for (String ship: theShip)
            addUp = addUp + ship;

        for (int row = 1; row < gameboard.length; row++)
        {
            for (int column = 1; column < gameboard[row].length; column++)
            {
                if (gameboard[row][column].equals(theShip[0]))
                {
                    numbOfShips++;
                    theRow = row; // last ship point
                    theColm = column;
                }
            }
        }

        if (numbOfShips == theShip.length && shipInColumn(theShip))
        {
            while (gameboard[theRow][theColm].equals(theShip[0]) && theRow >= 1)
            {
                lapCheck = lapCheck + gameboard[theRow][theColm];
                theRow--; // checks for overlap by seeing if column equals say 55555
            } // if there's overlap it re-places the ship

            if (!lapCheck.equals(addUp))
                overflow = true;
        }

        if (numbOfShips == theShip.length && shipInRow(theShip))
        {
            while (gameboard[theRow][theColm].equals(theShip[0]) && theColm >= 1)
            {
                lapCheck = lapCheck + gameboard[theRow][theColm];
                theColm--; // checks for overlap by seeing if the row equals say 55555
            } // if there's overlap it re-places the ship

            if (!lapCheck.equals(addUp))
                overflow = true;
        }

        return overflow; 
    }

    private boolean shipInColumn(String[] ship) // is there more than one ship in a each column
    {
        String shipPoint = ship[0];
        int numOfShips = 0; 
        boolean moreThanTwo = false;

        if (ship.length > 2)
        {
            for (int column = 1; column < gameboard[0].length; column++)
            {
                for (int row = 1; row < gameboard.length; row++)
                {
                    if (gameboard[row][column].equals(shipPoint))
                        numOfShips++;
                }
                if (numOfShips >= 2)
                {
                    moreThanTwo = true;
                    break;
                }
                numOfShips = 0;
            }
        }
        return (moreThanTwo);
    }

    private boolean shipInRow(String[] ship) // is there more than one ship in each row
    {
        String shipPoint = ship[0];
        int numOfShips = 0;
        boolean moreThanTwo = false;

        if (ship.length > 2)
        {
            for (int row = 1; row < gameboard.length; row++)
            {
                for (int column = 1; column < gameboard[0].length; column++)
                {
                    if (gameboard[row][column].equals(shipPoint))
                        numOfShips++;
                }
                if (numOfShips >=2)
                {
                    moreThanTwo = true;
                    break;
                }
                numOfShips = 0;
            }   
        }
        return (moreThanTwo);
    }

    public boolean allSunk() // are all ships sunk? uses number of X's to see if it totals the possible number of ship points one could hit
    {
        int numXs = 0;

        for (int row = 1; row < gameboard.length; row++)
        {
            for (int column = 1; column < gameboard[row].length; column++)
            {
                if (gameboard[row][column].equals("X"))
                    numXs++;
            }
        }
        return (numXs == 17);
    }

    private int numOShips(String[] whichShip) // determines remaining number of live points on a ship
    {
        String thisShip = whichShip[0];
        int numShips = 0;

        for (int row = 1; row < gameboard.length; row++)
        {
            for (int column = 1; column < gameboard[row].length; column++)
            {
                if (gameboard[row][column].equals(thisShip))
                    numShips++;
            }
        }

        return numShips;
    }

    private int randomNum() // random number from 1-10
    {
        int numb = 0;
        while (numb <= 0 || numb >= 11)
            numb = (int)(Math.random() * 10);
        return numb;
    }

    private char randomChar() // random char from A-J
    { // i know it's kinda redundant but it helps me with the coordinate organizing
        int rando = 0;
        while (rando <= 64 || rando > 74)
            rando = (int)(Math.random() * 100);
        return (char)rando;
    }

    private String numConverter(int firstNum, int secondNum) // makes a string of coordinates (of length 4 for ease of use
    {                                                       // with substring and to account for if row/column is 10)
        String convertedNum = "";
        if (firstNum <= 9 && secondNum == 10)
            convertedNum = "9" + firstNum + secondNum;
        if (firstNum <= 9 && secondNum <= 9)
            convertedNum = "9" + firstNum + "9" + secondNum;
        if (firstNum == 10 && secondNum == 10)
            convertedNum = "" + firstNum + secondNum;
        if (firstNum == 10 && secondNum <= 9)
            convertedNum = firstNum + "9" + secondNum;

        return convertedNum;
    }

    private boolean occupied(int coordinateOne, int coordinateTwo) // see if the point is open for placement
    {
        if (coordinateOne == 0 || coordinateOne == 10 || coordinateTwo == 0 || coordinateTwo == 10)
            return true;

        return (!gameboard[coordinateOne][coordinateTwo].equals("?"));
    }
}