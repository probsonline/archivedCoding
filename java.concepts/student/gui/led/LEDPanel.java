/*
 * Created on Apr 14, 2005
 *
 */

package student.gui.led;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.util.Vector;

import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;

/**
 * @author Kaleem Anwar
 */
public class LEDPanel extends JFrame
{

    JRadioButton cyclic = new JRadioButton("Cyclic Counter", false);
    JRadioButton non_cyclic = new JRadioButton("Value from List", false);
    JList hexValList = new JList();
    LED7Seg seven_seg = new LED7Seg();    
    
    public LEDPanel(String panelName)
    {
        super(panelName);
        initUI();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    private void initUI()
    {
        setLayout(new BorderLayout());
                
        /* Create a radio panel for radio control buttons. */
        JPanel radioPanel = new JPanel(new GridLayout(1,2));
        non_cyclic.setToolTipText("Select the value from the list on the right");
        ButtonGroup gourp = new ButtonGroup();
        gourp.add(cyclic);
        gourp.add(non_cyclic);
        radioPanel.add(cyclic);
        radioPanel.add(non_cyclic);
        
        Vector hexVals = new Vector();
        for(int i=0; i<10; i++)
        {
            hexVals.addElement(new Integer(i));
        }
        hexValList.setListData(hexVals);
        
        JScrollPane scrollPane = new JScrollPane();
        scrollPane.getViewport().setView(hexValList);
        hexValList.setEnabled(false);
               
        getContentPane().add(scrollPane, BorderLayout.EAST);
        getContentPane().add(seven_seg, BorderLayout.CENTER);
        getContentPane().add(radioPanel, BorderLayout.NORTH);
               
        /* Register the Action handler sources. */
        hexValList.addMouseListener(new LEDActionHandler(this));
        cyclic.addMouseListener(new LEDActionHandler(this));
        non_cyclic.addMouseListener(new LEDActionHandler(this));
                
    }
}
