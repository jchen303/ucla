import java.util.ArrayList; // finishing this was unbelievably satisfying.

public class Hanoi // don't try this beyond 11 disks. it broke.
{
    private int numDisks; // num of disks we're playing with
    private int moveCounter; // num of total moves made
    private boolean justMovedOne; // true if you just moved disk1 to a peg
    private ArrayList<Of> disks;
    private ArrayList<Of> peg1; // the recursion is what took me so long to figure out. i split it into 2 recursion
    private ArrayList<Of> peg2;// methods to try to make it easier on myself but it ended up being necessary anyways
    private ArrayList<Of> peg3;
    private ArrayList<ArrayList<Of>> allPegs; // i did have to google this to make sure i could actually do it

    public Hanoi (ArrayList<Of> disks, int numODisks)
    {
        justMovedOne = false;
        numDisks = numODisks;
        peg1 = disks;
        peg2 = new ArrayList<Of>();
        peg3 = new ArrayList<Of>();
        allPegs = new ArrayList<ArrayList<Of>>();
        moveCounter = 0;
    }

    private String printer() // prints updated version of all pegs and updates the move counter
    {
        for (Of firstPeg : peg1)
            System.out.print(firstPeg.getDiskNum());
        System.out.print("--" + "\n");

        for (Of secondPeg : peg2)
            System.out.print(secondPeg.getDiskNum());
        System.out.print("--" + "\n");
        
        for (Of thirdPeg : peg3)
            System.out.print(thirdPeg.getDiskNum());
        System.out.print("--" + "\n");

        moveCounter++;
        System.out.println("moves: " + moveCounter);

        return "";
    }

    private void firstMove()
    {
        if (numDisks % 2 == 1) // if odd, start by putting first disk on 3rd peg
        {
            peg3.add(peg1.remove(peg1.size() - 1)); // blue pelican said there was a removeLast method!
            printer();                             // what happened to removeLast()?!
        }                                         // it would save so many keystrokes...
        else // if even, start by putting first disk on 2nd peg
        {
            peg2.add(peg1.remove(peg1.size() - 1));
            printer();
        }
    }

    private boolean finishedStacking() // tells if the last peg is finished stacking
    {
        int diskNumber = numDisks;

        if (peg3.size() == numDisks) // checks to make sure it has all the disks
        {
            for (Of eachDisk : peg3) // checks to make sure it's in ascending order
            {
                if (eachDisk.getDiskNum() != diskNumber)
                    return false;
                diskNumber--;
            }
            return true;
        }
        return false;
    }

    private String minMoves()
    {
        if (Math.pow(2, numDisks) - 1 == moveCounter)
            return "you've solved the puzzle in the minimum number of steps: ";
        return "you've solved the puzzle in ";
    }

    private boolean hasOpenPeg() // returns true if there is a peg that has no disks on it
    {
        allPegs.clear(); // allPegs doesn't update every time a peg is changed
        allPegs.add(peg1);
        allPegs.add(peg2);
        allPegs.add(peg3);

        for (ArrayList<Of> eachPeg : allPegs)
        {
            if (eachPeg.size() == 0)
                return true;
        }
        return false;
    }

    private boolean hasEvenPeg() // if there's an even-disk-ended-peg available, 
    {                           // disk1 will go to the even (over the open peg)
        for (ArrayList<Of> peg : allPegs) 
        {                     // if it's between an open peg or an odd,
            if (peg.size() != 0)
            {               // disk1 will go to the open peg (disk1 never goes on an odd disk)
                if (peg.get(peg.size() - 1).getDiskNum() % 2 == 0)
                    return true;
            }
        }
        return false;
    }

    private ArrayList<Of> getEvenPeg() // the getPeg methods run if hasOpenPeg is false,
    {                                 // so hasOpenPeg must run and allPegs must be updated (i think)
        for (ArrayList<Of> thePeg : allPegs)
        {
            if (thePeg.size() != 0) // these prevent indexOutOfBoundsExceptions
            {
                if (thePeg.get(thePeg.size() - 1).getDiskNum() % 2 == 0)
                    return thePeg; // returns the even-disk-ended-peg
            }
        }
        return peg1; // arbitrary, there has to be an even disked peg if there is no open peg
    }

    private ArrayList<Of> getOnePeg()
    {
        for (ArrayList<Of> peg : allPegs)
        {
            if (peg.size() != 0)
            {
                if (peg.get(peg.size() - 1).getDiskNum() == 1) // returns the peg with disk1
                    return peg;
            }
        }
        return peg1; // arbitrary, the peg with the 1 disk MUST be on one of them
    }

    private ArrayList<Of> getOpenPeg() // returns the peg that has no disks on it
    {
        if (hasOpenPeg())
        {
            for (ArrayList<Of> thePeg : allPegs)
            {
                if (thePeg.size() == 0)
                    return thePeg;
            }
        }
        return peg3; // arbitrary, this method will only be called if there IS an open peg
    }

    private ArrayList<Of> getOtherPeg() // for secondRec, if there's an open peg and you're not moving disk1
    {
        for (ArrayList<Of> peg : allPegs) 
        {
            if (peg.size() != 0)
            {
                if (peg.get(peg.size() - 1).getDiskNum() != 1)
                    return peg;
            }
        }
        return peg1; // arbitrary, there has to be a peg that is not empty and does not have 1
    }

    private ArrayList<Of> getSmallerDiskPeg() // gets the peg w/ the smallest end disk that is not disk1
    {
        ArrayList<Of> smallestPeg = new ArrayList<Of>();
        int smallestDisk = 37;

        for (ArrayList<Of> eachPeg : allPegs)
        {
            if (eachPeg.get(eachPeg.size() - 1).getDiskNum() != 1)
            {
                if (eachPeg.get(eachPeg.size() - 1).getDiskNum() < smallestDisk)
                {
                    smallestDisk = eachPeg.get(eachPeg.size() - 1).getDiskNum();
                    smallestPeg = eachPeg;
                }
            }
        }
        return smallestPeg;
    }

    private ArrayList<Of> getValidPeg() // tells which peg you can move a non-disk1 to 
    {                                  // (a bigger disk than the one you want to move)
        int numToBeat = getSmallerDiskPeg().get(getSmallerDiskPeg().size() - 1).getDiskNum();

        for (ArrayList<Of> peg : allPegs)
        {
            if (peg.get(peg.size() - 1).getDiskNum() > numToBeat)
                return peg;
        }
        return peg1; // arbitrary, one of the pegs that it cycles through HAS to have the bigger disk
    }

    private void firstStackRec() // i feel like this is wrong, it doesn't feel like recursion since it doesn't have an nth term that i'm increasing or decreasing
    {                           // but bpj defines it as "the process of a method calling itself," so i'm hoping this counts
        if (peg1.get(0).getDiskNum() == numDisks && peg1.size() == 1 && peg3.size() == 0) // if it's the biggest disk left, move it to 3rd peg (end condition)
        {
            peg3.add(peg1.remove(peg1.size() - 1));
            justMovedOne = false;
            printer();
            secondStackRec();
        }
        else if (hasOpenPeg()) // if there's an open peg, move the disk from peg1 to the open peg (unless it's disk1)
        {
            if (peg1.get(peg1.size() - 1).getDiskNum() != 1)
            {
                getOpenPeg().add(peg1.remove(peg1.size() - 1)); // all disks will come from peg1 in firstRec
                justMovedOne = false;                          // in secondRec, it'll depend
                printer();
                firstStackRec();
            }
            else 
            {
                if (hasEvenPeg()) // the even-disk-ended-peg has priority over the openPeg
                {
                    getEvenPeg().add(getOnePeg().remove(getOnePeg().size() - 1)); 
                    justMovedOne = true;
                    printer();
                    firstStackRec();
                }
                else
                {
                    getOpenPeg().add(getOnePeg().remove(getOnePeg().size() - 1));
                    justMovedOne = true;
                    printer();
                    firstStackRec();
                }
            }
        }
        else if (!hasOpenPeg()) // add disk1 to the peg with an even disk if there's no openPeg
        {
            if (!justMovedOne) // as long as you haven't just moved disk1
            {
                getEvenPeg().add(getOnePeg().remove(getOnePeg().size() - 1));
                justMovedOne = true;
                printer();
                firstStackRec();
            }
            else // if you just moved disk1, it's time to move another disk (can't just keep moving the 1 back & forth)
            {
                getValidPeg().add(getSmallerDiskPeg().remove(getSmallerDiskPeg().size() - 1));
                justMovedOne = false;
                printer();
                firstStackRec();
            }
        }
    }

    private void secondStackRec()
    {
        if (finishedStacking()) // then we're done!
        {
        }

        else if (hasOpenPeg()) // if there's an open peg, move the disk from peg1 to the open peg (unless it's disk1)
        {
            if (getOtherPeg().get(getOtherPeg().size() - 1).getDiskNum() != 1 && justMovedOne) // the only change from firstRec is that peg1 won't
            {                                                                                 // be the only peg you're moving disks to openPegs from
                getOpenPeg().add(getOtherPeg().remove(getOtherPeg().size() - 1));
                justMovedOne = false;
                printer();
                secondStackRec();
            }
            else 
            {
                if (hasEvenPeg())
                {
                    getEvenPeg().add(getOnePeg().remove(getOnePeg().size() - 1));
                    justMovedOne = true;
                    printer();
                    secondStackRec();
                }
                else
                {
                    getOpenPeg().add(getOnePeg().remove(getOnePeg().size() - 1));
                    justMovedOne = true;
                    printer();
                    secondStackRec();
                }
            }
        }
        
        else if (!hasOpenPeg())
        {
            if (!justMovedOne)
            {
                getEvenPeg().add(getOnePeg().remove(getOnePeg().size() - 1));
                justMovedOne = true;
                printer();
                secondStackRec();
            }
            else 
            {
                getValidPeg().add(getSmallerDiskPeg().remove(getSmallerDiskPeg().size() - 1));
                justMovedOne = false;
                printer();
                secondStackRec();
            }
        }
    }

    public void solve()
    {
        firstMove();
        firstStackRec();
        secondStackRec();
        System.out.println(minMoves() + moveCounter + " moves!");
    }
} //firstStackRec takes you from the second move up until the moment when you're moving the 
// biggest disk over from the first peg to the third peg. the end condition is when the 
// biggest disk is all that's left on the first disk, at which point it'll move the 
// biggest disk to the third peg and begin the second recursion method. if there's an open peg, 
// and if you just moved the 1disk, it puts the disk from peg1 on the open peg 
// (i.e. after the first move, the 2disk will go to the open peg since you just moved the 1disk).
// the 1disk can only go on top of an even disk or an open peg, and prioritizes even disks over 
// open pegs if presented with both. after the 1disk moves, either the disk from peg1 moves to 
// the open peg or, if there are no open pegs, the smallest disk (smallest next to the 1disk) 
// moves to a peg with a bigger disk (found with getValidPeg()) (i.e. if the disks on pegs 1-3 
// are 54, 3, 21, the 1disk will go on top of the 4 and then the 2disk will go on top of the 
// 3disk, and then you just moved the 2disk so you can move the 1disk now (presented with 
// either the openPeg or the 2disk, so it'll go to the 2disk))

// the secondStackRec(ursion) does the same thing, except when there are open pegs it can't 
// just take the disk off of peg1, since there's the possibility of peg1 being the open one 
// itself. so instead, i wrote the getOtherPeg() method to get the peg that neither contains 
// the 1disk nor is empty. that peg is the one from which the open peg receives the disk 
// (given you had just moved the 1disk).