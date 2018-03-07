/*
 * Created on Apr 14, 2005
 *
 */
package student.gui.led;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JPanel;

/**
 * @author Kaleem Anwar
 */
public class LED7Seg extends JPanel
{
    final static int xOffset=50;
    final static int yOffset=40;
    final static int SegmentLength=60;
    final static int RectWidth=7;
    final static int RoundMargin=4;
    final static int adjustMargin=RectWidth;
    
    final static int LEDT=0;	/* LED Top Segment */
    final static int LEDRT=1;	/* LED Right Top Segment */
    final static int LEDRB=2;	/* LED Right Botton Segment */
    final static int LEDB=3;	/* LED Bottom Segment */
    final static int LEDLB=4;	/* LED Left Bottom Segment */
    final static int LEDLT=5;	/* LED Left Top Segment */
    final static int LEDM=6;	/* LED Middle Segment */
    
    
    /**
     * @param title
     * @throws java.awt.HeadlessException
     */
    public LED7Seg()
    {
/*        Thread t = new Thread(this);
        t.setDaemon(true);
        t.start();        */
    }

    public void paintComponent(Graphics g1) 
    {
        Graphics2D g = (Graphics2D)g1;
        super.paintComponent(g);
        g.setColor(Color.DARK_GRAY);

/*
        g.drawRoundRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*0 - adjustMargin, SegmentLength+adjustMargin,  RectWidth, RoundMargin, RoundMargin);
        g.drawRoundRect(xOffset+ SegmentLength*1, yOffset+ SegmentLength*0,  RectWidth,  SegmentLength, RoundMargin, RoundMargin);
        g.drawRoundRect(xOffset+ SegmentLength*1, yOffset+ SegmentLength*1,  RectWidth,  SegmentLength, RoundMargin, RoundMargin);
        g.drawRoundRect(xOffset+ SegmentLength*0, yOffset+ SegmentLength*2,  SegmentLength+adjustMargin,  RectWidth, RoundMargin, RoundMargin);
        g.drawRoundRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*1, RectWidth,  SegmentLength, RoundMargin, RoundMargin);
        g.drawRoundRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*0, RectWidth,  SegmentLength, RoundMargin, RoundMargin);
        g.drawRoundRect(xOffset+ SegmentLength*0 + adjustMargin,  yOffset+ SegmentLength*1, SegmentLength-adjustMargin,  RectWidth, RoundMargin, RoundMargin);        

*/

        g.fillRoundRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*0 - adjustMargin, SegmentLength+adjustMargin,  RectWidth, RoundMargin, RoundMargin);
        g.fillRoundRect(xOffset+ SegmentLength*1, yOffset+ SegmentLength*0,  RectWidth,  SegmentLength, RoundMargin, RoundMargin);
        g.fillRoundRect(xOffset+ SegmentLength*1, yOffset+ SegmentLength*1,  RectWidth,  SegmentLength, RoundMargin, RoundMargin);
        g.fillRoundRect(xOffset+ SegmentLength*0, yOffset+ SegmentLength*2,  SegmentLength+adjustMargin,  RectWidth, RoundMargin, RoundMargin);
        g.fillRoundRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*1, RectWidth,  SegmentLength, RoundMargin, RoundMargin);
        g.fillRoundRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*0, RectWidth,  SegmentLength, RoundMargin, RoundMargin);
        g.fillRoundRect(xOffset+ SegmentLength*0 + adjustMargin,  yOffset+ SegmentLength*1, SegmentLength-adjustMargin,  RectWidth, RoundMargin, RoundMargin);        

    }  
    
    private void turnOnSegment(int id)
    {
        Graphics2D page = (Graphics2D)this.getGraphics();       
        page.setColor(Color.RED);
        
        switch(id)
        {
        case LEDT:
            page.fill3DRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*0 - adjustMargin, SegmentLength+adjustMargin,  RectWidth, true);
            break;
        case LEDRT:
            page.fill3DRect(xOffset+ SegmentLength*1, yOffset+ SegmentLength*0,  RectWidth,  SegmentLength, true);
            break;
        case LEDRB:
            page.fill3DRect(xOffset+ SegmentLength*1, yOffset+ SegmentLength*1,  RectWidth,  SegmentLength, true);
            break;
        case LEDB:
            page.fill3DRect(xOffset+ SegmentLength*0, yOffset+ SegmentLength*2,  SegmentLength+adjustMargin,  RectWidth, true);
            break;
        case LEDLB:
            page.fill3DRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*1, RectWidth,  SegmentLength, true);
            break;
        case LEDLT:
            page.fill3DRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*0, RectWidth,  SegmentLength, true);
            break;
        case LEDM:
            page.fill3DRect(xOffset+ SegmentLength*0 + adjustMargin,  yOffset+ SegmentLength*1, SegmentLength-adjustMargin,  RectWidth, true);                    
            break;
        default:
            break;
        }

    }
    
    public void turnOff7Segment()
    {
        Graphics2D page = (Graphics2D)this.getGraphics();
        page.setColor(Color.DARK_GRAY);        
        page.fill3DRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*0 - adjustMargin, SegmentLength+adjustMargin,  RectWidth, true);
        page.fill3DRect(xOffset+ SegmentLength*1, yOffset+ SegmentLength*0,  RectWidth,  SegmentLength, true);
        page.fill3DRect(xOffset+ SegmentLength*1, yOffset+ SegmentLength*1,  RectWidth,  SegmentLength, true);
        page.fill3DRect(xOffset+ SegmentLength*0, yOffset+ SegmentLength*2,  SegmentLength+adjustMargin,  RectWidth, true);
        page.fill3DRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*1, RectWidth,  SegmentLength, true);
        page.fill3DRect(xOffset+ SegmentLength*0,  yOffset+ SegmentLength*0, RectWidth,  SegmentLength, true);
        page.fill3DRect(xOffset+ SegmentLength*0 + adjustMargin,  yOffset+ SegmentLength*1, SegmentLength-adjustMargin,  RectWidth, true);
    }
    
    public void displayValue(int val)
    {
        turnOff7Segment();        
        switch(val)
        {
        case 1:
            turnOnSegment(LEDRT);            
            turnOnSegment(LEDRB);            
            break;
        case 2:
            turnOnSegment(LEDT);            
            turnOnSegment(LEDRT);                       
            turnOnSegment(LEDM);            
            turnOnSegment(LEDLB);                        
            turnOnSegment(LEDB);                        
            break;
        case 3:
            turnOnSegment(LEDT);            
            turnOnSegment(LEDRT);
            turnOnSegment(LEDM);            
            turnOnSegment(LEDRB);                       
            turnOnSegment(LEDB);                                    
            break;
        case 4:
            turnOnSegment(LEDLT);
            turnOnSegment(LEDM);            
            turnOnSegment(LEDRT);
            turnOnSegment(LEDRB);                       
            break;
        case 5:
            turnOnSegment(LEDT);            
            turnOnSegment(LEDLT);
            turnOnSegment(LEDM);            
            turnOnSegment(LEDRB);                       
            turnOnSegment(LEDB);                                                
            break;
        case 6:
            turnOnSegment(LEDT);            
            turnOnSegment(LEDLT);
            turnOnSegment(LEDLB);
            turnOnSegment(LEDB);
            turnOnSegment(LEDRB);            
            turnOnSegment(LEDM);            
            break;
        case 7:
            turnOnSegment(LEDT);            
            turnOnSegment(LEDRT);            
            turnOnSegment(LEDRB);                        
            break;
        case 8:
            turnOnSegment(LEDT);            
            turnOnSegment(LEDLT);
            turnOnSegment(LEDLB);
            turnOnSegment(LEDB);
            turnOnSegment(LEDRB);            
            turnOnSegment(LEDRT);            
            turnOnSegment(LEDM);                                    
            break;
        case 9:
            turnOnSegment(LEDT);            
            turnOnSegment(LEDLT);
            turnOnSegment(LEDB);
            turnOnSegment(LEDRB);            
            turnOnSegment(LEDRT);            
            turnOnSegment(LEDM);                                                
            break;
        default:
            turnOff7Segment();
            break;
        }
    }

    public void displayValueCyclically()
    {
        for (int i=0; i<10; i++)
        {
            displayValue(i);
            pause();
        }
    }
    
    private void pause()
    {
        for(int i=0; i<250000000; i++);
    }

}
