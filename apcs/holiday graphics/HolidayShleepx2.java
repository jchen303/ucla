import javax.swing.*;
import java.awt.*;

public class HolidayShleepx2
{
    public static void main(String[] args)
    {
        JFrame win;
        Container contentPane;
        Graphics g;
        int zblockY = 0;

        win = new JFrame("dreaming 'bout joo");
        win.setSize(750, 750);
        win.setLocation(150, 150);
        win.setVisible(true);

        contentPane = win.getContentPane();
        g = contentPane.getGraphics();

        try
        {
            Thread.sleep(300);
        }
        catch (Exception e) {}

        g.setColor(new Color(96, 191, 159)); // turquoise green
        g.fillRect(0, 0, 750, 750); // background color

        g.setColor(new Color(84, 180, 222)); // jean blue
        Polygon legs = new Polygon(); // legs
        legs.addPoint(520, 495); // right point
        legs.addPoint(225, 375); // top point
        legs.addPoint(90, 495); // left point
        g.fillPolygon(legs);

        g.setColor(new Color(96, 191, 159)); // turquoise green
        Polygon legHole = new Polygon(); // leg hole
        legHole.addPoint(157, 495); // left point
        legHole.addPoint(225, 435); // top point
        legHole.addPoint(322, 495); // right point
        g.fillPolygon(legHole);

        g.setColor(new Color(77, 169, 209)); // darker sky blue
        g.drawPolygon(legs); // pants outline
        g.drawPolygon(legHole); // pants outline

        g.setColor(new Color(223, 203, 182)); // table beige
        g.fillRect(75, 495, 30, 525); // left table leg
        g.fillRect(645, 495, 30, 525); // right table leg
        g.fillRect(75, 495, 600, 30); // table top

        g.setColor(new Color(212, 177, 150)); // darker table beige
        g.drawRect(75, 525, 30, 525); // table outline
        g.drawRect(645, 525, 30, 525); // table outline
        g.drawRect(75, 495, 600, 30); // table outline

        g.setColor(new Color(199, 206, 209)); // gray
        g.fillRect(322, 405, 202, 90); // shirt 

        g.setColor(new Color(175, 146, 103)); // shoe brown
        g.fillRoundRect(75, 457, 90, 37, 30, 10); // shoe
        g.setColor(new Color(114, 79, 53)); // darker shoe brown
        g.drawRoundRect(75, 457, 90, 37, 30, 10); // shoe outline

        g.setColor(new Color(135, 114, 82)); // darker brown
        g.drawOval(127, 442, 7, 22); // shoelace
        g.drawOval(129, 442, 7, 22); // shoelace

        g.setColor(new Color(250, 205, 160)); // skin tone
        g.fillRoundRect(555, 405, 120, 90, 15, 10); // head
        g.fillRect(525, 435, 75, 42); // neck
        g.fillRect(397, 456, 45, 34); // bicep
        g.fillRect(397, 420, 28, 45); // forearm
        g.fillArc(577, 399, 37, 30, -180, -180); // nose

        Polygon hand = new Polygon();
        hand.addPoint(397, 420); // hand
        hand.addPoint(405, 405); // hand
        hand.addPoint(450, 405); // hand
        hand.addPoint(427, 420); // hand
        g.fillPolygon(hand);

        g.drawRect(525, 435, 75, 42); // neck outline 

        g.setColor(new Color(151, 151, 151)); // darker gray
        Polygon shirtCollar = new Polygon();
        shirtCollar.addPoint(525, 495); // shirt collar
        shirtCollar.addPoint(540, 495); // shirt collar
        shirtCollar.addPoint(540, 420); // shirt collar
        shirtCollar.addPoint(525, 405); // shirt collar
        g.setColor(new Color(199, 206, 209)); // gray
        g.fillPolygon(shirtCollar); // shirt collar

        g.setColor(new Color(151, 151, 151)); // darker gray
        g.drawPolygon(shirtCollar); // shirt collar outline
        g.drawRect(322, 405, 202, 90); // shirt outline

        g.setColor(new Color(206, 188, 137));
        g.drawRoundRect(555, 405, 120, 90, 10, 5); // head outline

        g.drawPolygon(hand); // hand outline

        g.setColor(new Color(0, 0, 0)); // black
        g.fillRoundRect(667, 412, 19, 79, 10, 10); // hair
        Polygon glasses = new Polygon();
        glasses.addPoint(637, 405); // glasses
        glasses.addPoint(637, 468); // glasses
        glasses.addPoint(639, 468); // glasses
        glasses.addPoint(639, 405); // glasses
        g.fillPolygon(glasses);
        g.fillArc(630, 450, 75, 45, -90, -116); // sideburn
        g.fillArc(636, 451, 45, 45, 0, -90); // hair @ end of head

        g.fillRect(318, 412, 6, 82);

        g.setColor(new Color(151, 151, 151)); // darker gray
        g.drawRect(439, 450, 75, 45); // shirt sleeve
        g.drawRect(439, 448, 75, 45); // shirt sleeve 
        g.drawRect(441, 450, 75, 45); // shirt sleeve

        Polygon frames = new Polygon();
        frames.addPoint(627, 405); // glasses lens
        frames.addPoint(627, 409); // glasses lens
        frames.addPoint(648, 409); // glasses lens
        frames.addPoint(648, 405); // glasses lens
        g.fillPolygon(frames);

        g.setColor(new Color(27, 64, 185)); // navy blue
        Polygon polo = new Polygon();
        polo.addPoint(502, 424); // lil polo guy
        polo.addPoint(502, 427); // lil polo guy
        polo.addPoint(496, 427); // lil polo guy
        polo.addPoint(496, 424); // lil polo guy
        g.fillPolygon(polo);

        g.setColor(new Color(255, 255, 0)); // gold

        for (int zNum = 0; zNum < 1500000000; zNum++)
        {
            try
            {
                Thread.sleep(400);
            }
            catch (InterruptedException e) {}

            g.fillRoundRect(607, 292, 60, 15, 5, 5); // upper large z
            g.fillRoundRect(607, 360, 60, 15, 5, 5); // lower large z

            zblockY = 352;
            for (int zblockX = 607; zblockX < 660; zblockX = zblockX + 7)
            {
                g.fillRect(zblockX, zblockY, 13, 13); // large z
                zblockY = zblockY - 7; // large z
            }

            try
            {
                Thread.sleep(400);
            }
            catch (InterruptedException e) {}

            g.fillRoundRect(510, 157, 45, 12, 5, 5); // upper medium z
            g.fillRoundRect(510, 210, 45, 12, 5, 5); // lower medium z

            zblockY = 202;
            for (int zblockX = 510; zblockX < 555; zblockX = zblockX + 7)
            {
                g.fillRect(zblockX, zblockY, 10, 10); // medium z
                zblockY = zblockY - 7; // medium z
            }

            try
            {
                Thread.sleep(400);
            }
            catch (InterruptedException e) {}

            g.fillRoundRect(645, 82, 30, 9, 5, 5); // upper small z
            g.fillRoundRect(643, 117, 30, 9, 5, 5); // lower small z

            zblockY = 112;
            for (int zblockX = 645; zblockX < 675; zblockX = zblockX + 7)
            {
                g.fillRect(zblockX, zblockY, 7, 7); // small z
                zblockY = zblockY - 7; // small z
            }

            try
            {
                Thread.sleep(400);
            }
            catch (InterruptedException e) {}

            g.fillRoundRect(532, 19, 15, 6, 5, 5); // upper smallest z
            g.fillRoundRect(532, 37, 15, 6, 5, 5); // lower smallest z

            zblockY = 36;
            for (int zblockX = 532; zblockX < 547; zblockX = zblockX + 3)
            {
                g.fillRect(zblockX, zblockY, 4, 4); // smallest z
                zblockY = zblockY - 3; // smallest z
            }

            if (zNum % 2 == 0)
                g.setColor(new Color(96, 191, 159)); // turquoise green
            else 
                g.setColor(new Color(255, 255, 0)); // gold
        }
    }
}
