public class Of // disks, with a method to return the number of disk it represents
{ // did this instead of a number array so i could make 10 of them w/o needing to manually input var names
    private int diskNum;

    public Of(int theNum)
    {
        diskNum = theNum;
    }

    public int getDiskNum()
    {
        return diskNum;
    }
}