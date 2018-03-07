/*
 * Created on Apr 11, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package temperatureconverter;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import java.util.Vector;


/**
 * @author Kaleem
 *
 * Temperature Converter User Interface
 */
public class TempConverterUI extends JFrame implements MouseListener{

    final static int DEGREE=0;
    final static int FAHRENHEIT=1;
    final static int KELVIN=2;
    
    JPanel mainPanel = new JPanel(new GridLayout(3, 3, 20, 20));
    
    JLabel 	inputSysLabel  = new JLabel("Select the input system"); 
    JList 	inputSysList   = new JList();
    JTextField inputValue  = new JTextField("Enter Value Here");
    
    JLabel 	outputSysLabel = new JLabel("Select the output system"); 
    JList 	outputSysList  = new JList();
    JTextField outputValue = new JTextField("Ouput will be displayed here");

    JButton close = new JButton("close");    
    JButton calculate =  new JButton("Calculate");
    JButton reset = new JButton("Reset");
    
    Vector systems = new Vector();
    /**
     * Converter for the TempConverterUI
     */
    public TempConverterUI() 
    {
        super();
        setSize(500, 130);
        setLayout(new BorderLayout());
        /* Initialize the GUI. */
        initUI();
    }
 
    /* Initialize UI here. */
    public void initUI()
    {
        systems.add(DEGREE, "Degree");
        systems.add(FAHRENHEIT, "Fahrenheit");
        systems.add(KELVIN, "Kelvin");
        
        inputSysList.setListData(systems);
        outputSysList.setListData(systems);
        
        mainPanel.add(inputSysLabel);
        mainPanel.add(inputSysList);
        mainPanel.add(inputValue);
        
        mainPanel.add(outputSysLabel);
        mainPanel.add(outputSysList);
        mainPanel.add(outputValue);
        
        mainPanel.add(close);
        mainPanel.add(calculate);
        mainPanel.add(reset);
        
        getContentPane().add(mainPanel, BorderLayout.CENTER);
        
        
    }
    
    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mouseClicked(java.awt.event.MouseEvent)
     */
    public void mouseClicked(MouseEvent e) 
    {
        TempConverterEngine converter = new TempConverterEngine();
        if(e.getSource().equals(close))
        {
            this.dispose();
        }
        else if(e.getSource().equals(reset))
        {
            inputValue.setText("Enter Value Here");
            outputValue.setText("");
        }
        else if(e.getSource().equals(calculate))
        {
            if(inputSysList.getSelectedIndex()==DEGREE)
            {
                if(outputSysList.getSelectedIndex()==FAHRENHEIT)
                {
                    outputValue.setText("" + converter.degreeToFahrenheit(Double.parseDouble(inputValue.getText())));
                }
                else if(outputSysList.getSelectedIndex()==KELVIN)
                {
                    outputValue.setText("" + converter.degreeToKelvin(Double.parseDouble(inputValue.getText())));                    
                }
                else if(outputSysList.getSelectedIndex()==DEGREE)
                {
                    outputValue.setText(inputValue.getText());
                }
                else
                {
                    System.out.println("No output Item selected");
                }
            }
            else if(inputSysList.getSelectedIndex()==FAHRENHEIT)
            {
                if(outputSysList.getSelectedIndex()==DEGREE)
                {
                    outputValue.setText("" + converter.fahrenhietToDegree(Double.parseDouble(inputValue.getText())));
                }
                else if(outputSysList.getSelectedIndex()==KELVIN)
                {
                    outputValue.setText("" + converter.fahrenheitToKelvin(Double.parseDouble(inputValue.getText())));                    
                }
                else if(outputSysList.getSelectedIndex()==FAHRENHEIT)
                {
                    outputValue.setText(inputValue.getText());
                }
                else
                {
                    System.out.println("No output Item selected");
                }
            }
            else if(inputSysList.getSelectedIndex()==KELVIN)
            {
                if(outputSysList.getSelectedIndex()==DEGREE)
                {
                    outputValue.setText("" + converter.kelvinToDegree(Double.parseDouble(inputValue.getText())));
                }
                else if(outputSysList.getSelectedIndex()==FAHRENHEIT)
                {
                    outputValue.setText("" + converter.kelvinToFahrenheit(Double.parseDouble(inputValue.getText())));                    
                }
                else if(outputSysList.getSelectedIndex()==KELVIN)
                {
                    outputValue.setText(inputValue.getText());
                }
                else
                {
                    System.out.println("No output Item selected");
                }
            }
            else
            {
                System.out.println("Select an output unit system");
            }            
        }
        else
        {
            System.out.println("Unhandeled Event");
        }
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mousePressed(java.awt.event.MouseEvent)
     */
    public void mousePressed(MouseEvent arg0) 
    {
        /* No implementation needed */
        
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mouseReleased(java.awt.event.MouseEvent)
     */
    public void mouseReleased(MouseEvent arg0) 
    {
        /* No implementation needed */        
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mouseEntered(java.awt.event.MouseEvent)
     */
    public void mouseEntered(MouseEvent arg0) 
    {
        /* No implementation needed */        
    }

    /* (non-Javadoc)
     * @see java.awt.event.MouseListener#mouseExited(java.awt.event.MouseEvent)
     */
    public void mouseExited(MouseEvent arg0) 
    {
        /* No implementation needed */        
    }

}
