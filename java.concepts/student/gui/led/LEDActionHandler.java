/*
 * Created on Apr 13, 2005
 *
 */

package student.gui.led;
import java.awt.event.*;

/**
 * @author Kaleem Anwar
 */
class LEDActionHandler implements MouseListener
{
    LEDPanel	actionSource;
    /**
     * 
     */
    public LEDActionHandler(LEDPanel inputSource)
    {
        actionSource = inputSource;
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mouseClicked(java.awt.event.MouseEvent)
     */
    public void mouseClicked(MouseEvent e)
    {
        if(e.getSource().equals(actionSource.cyclic))
        {
            actionSource.hexValList.setEnabled(false);            
            actionSource.seven_seg.displayValueCyclically();
        }
        else if(e.getSource().equals(actionSource.non_cyclic))
        {
            actionSource.seven_seg.turnOff7Segment();            
            actionSource.hexValList.setEnabled(true);
        }
        else if(e.getSource().equals(actionSource.hexValList))
        {                       
            actionSource.seven_seg.displayValue(
            actionSource.hexValList.getSelectedIndex());
        }
        else
        {
            /* Ignore the event: Not going to occur. */
        }
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mousePressed(java.awt.event.MouseEvent)
     */
    public void mousePressed(MouseEvent e)
    {

        
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mouseReleased(java.awt.event.MouseEvent)
     */
    public void mouseReleased(MouseEvent e)
    {

        
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mouseEntered(java.awt.event.MouseEvent)
     */
    public void mouseEntered(MouseEvent e)
    {

        
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mouseExited(java.awt.event.MouseEvent)
     */
    public void mouseExited(MouseEvent e)
    {

        
    }

}
