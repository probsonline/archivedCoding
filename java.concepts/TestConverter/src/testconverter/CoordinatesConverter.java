package testconverter;

import java.awt.*;
import javax.swing.*;
import java.util.Vector;
import java.awt.event.*;
import java.text.DecimalFormat;

public class CoordinatesConverter extends JDialog implements MouseListener{

    final static int RECTANGULAR = 0;
    final static int CYLINDRICAL = 1;
    final static int SPHERICAL = 2;

    /* Converter Engine Instance creation. */
    ConverterEngine converter = new ConverterEngine();

    /* Main panel creation. */
    JPanel main_panel = new JPanel();
    GridLayout main_layout = new GridLayout(3, 2, 20, 20);

    /* Sub-panels in the main panel. */
    JPanel in_sys_panel = new JPanel(new GridLayout(2, 1));
    JPanel out_sys_panel = new JPanel(new GridLayout(2, 1));
    JPanel input_panel = new JPanel(new GridLayout(3, 2, 0, 30));
    JPanel output_panel = new JPanel(new GridLayout(3, 2, 0, 30));
    JPanel button_panel = new JPanel(new GridLayout(2, 1));
    JPanel info_panel = new JPanel(new GridLayout(2, 1));

    /* Components in the in and out sys panel. */
    Vector coordinate_list = new Vector(3);
    JLabel from = new JLabel("Input Coordinates System");
    JList in_sys = new JList(coordinate_list);
    JLabel to = new JLabel("Output Coordinates System");
    JList out_sys =  new JList(coordinate_list);

    /* Components in the input_panel. */
    JLabel in_cord_1 = new JLabel();
    JLabel in_cord_2 = new JLabel();
    JLabel in_cord_3 = new JLabel();
    JTextField in_cord_1_val = new JTextField();
    JTextField in_cord_2_val = new JTextField();
    JTextField in_cord_3_val = new JTextField();

    /* Components in the output_panel. */
    JLabel out_cord_1 = new JLabel();
    JLabel out_cord_2 = new JLabel();
    JLabel out_cord_3 = new JLabel();
    JTextField out_cord_1_val = new JTextField();
    JTextField out_cord_2_val = new JTextField();
    JTextField out_cord_3_val = new JTextField();

    /* Componets in the button panel. */
    JButton convert_button = new JButton("Convert");
    JButton cancel_button = new JButton("Cancel");

    /* Components in information panel. */
    JLabel name = new JLabel("    Created by Waseem Anwar  ");
    JLabel roll_no = new JLabel("   2003-UET-EE-RCET-029");

    public CoordinatesConverter(Frame owner, String title, boolean modal) {
        super(owner, title, modal);
        try {
            setDefaultCloseOperation(DISPOSE_ON_CLOSE);
            jbInit();
            pack();
        } catch (Exception exception) {
            exception.printStackTrace();
        }
    }

    public CoordinatesConverter() {
        this(new Frame(), "CoordinatesConverter", false);
    }

    private void jbInit() throws Exception
    {
        main_panel.setLayout(main_layout);

        /* Add coordinate systems supported by the converter.*/
        coordinate_list.add(RECTANGULAR, "Rectangular Coordinates");
        coordinate_list.add(CYLINDRICAL, "Cyclindrical Coordinates");
        coordinate_list.add(SPHERICAL, "Spherical Coordinates");

        /* Add components to input system panel. */
        in_sys_panel.add(from);
        in_sys_panel.add(in_sys);

        /* Add components to output system panel. */
        out_sys_panel.add(to);
        out_sys_panel.add(out_sys);

        /* Add components to input the values of the input coordinate system. */
        input_panel.add(in_cord_1);
        input_panel.add(in_cord_1_val);
        input_panel.add(in_cord_2);
        input_panel.add(in_cord_2_val);
        input_panel.add(in_cord_3);
        input_panel.add(in_cord_3_val);

        /* Add components to input the values of the input coordinate system. */
        output_panel.add(out_cord_1);
        output_panel.add(out_cord_1_val);
        output_panel.add(out_cord_2);
        output_panel.add(out_cord_2_val);
        output_panel.add(out_cord_3);
        output_panel.add(out_cord_3_val);

        /* Add componets to the button pane. */
        button_panel.add(convert_button);
        button_panel.add(cancel_button);

        name.setFocusable(false);
        roll_no.setFocusable(false);
        info_panel.add(name);
        info_panel.add(roll_no);

        /* Add sub-panels to the main panel. */
        main_panel.add(in_sys_panel);
        main_panel.add(out_sys_panel);
        main_panel.add(input_panel);
        main_panel.add(output_panel);
        main_panel.add(button_panel);
        main_panel.add(info_panel);

        /* Call the method that assigns action lister to the components. */
        addAllActionListener();

        getContentPane().add(main_panel);
    }

    public void addAllActionListener()
    {
        in_sys.addMouseListener(this);
        out_sys.addMouseListener(this);

        convert_button.addMouseListener(this);
        cancel_button.addMouseListener(this);
    }


    public void mouseClicked(MouseEvent e)
    {
        double x, y, z, r, phi, theta, rho;
        DecimalFormat fmt=new DecimalFormat("0.###");

        /* Get the source of the action.*/
        Object source = e.getSource();

        if(source.equals(in_sys))
        {
            if(in_sys.getSelectedIndex() == RECTANGULAR)
            {
                in_cord_1.setText("    x");
                in_cord_2.setText("    y");
                in_cord_3.setText("    z");
            }
            else if(in_sys.getSelectedIndex() == CYLINDRICAL)
            {
                in_cord_1.setText("    \u03C1"); /* Rho*/
                in_cord_2.setText("    \u03A6"); /* Phi*/
                in_cord_3.setText("     z");
            }
            else if(in_sys.getSelectedIndex() == SPHERICAL)
            {
                in_cord_1.setText("     r");
                in_cord_1.setText("    \u0398");  /* theta*/
                in_cord_2.setText("    \u03A6"); /* Phi*/
            }

        }
        else if(source.equals(out_sys))
        {
            if(out_sys.getSelectedIndex() == RECTANGULAR)
            {
                out_cord_1.setText("     x");
                out_cord_2.setText("     y");
                out_cord_3.setText("     z");
            }
            else if(out_sys.getSelectedIndex() == CYLINDRICAL)
            {
                out_cord_1.setText("    \u03C1"); /* Rho*/
                out_cord_2.setText("    \u03A6"); /* Phi*/
                out_cord_3.setText("     z");
            }
            else if(out_sys.getSelectedIndex() == SPHERICAL)
            {
                out_cord_1.setText("     r");
                out_cord_1.setText("    \u0398");  /* theta*/
                out_cord_2.setText("    \u03A6"); /* Phi*/
            }
        }
        else if(source.equals(convert_button))
        {
            if(in_sys.getSelectedIndex() == RECTANGULAR)
            {
                x = Double.parseDouble(in_cord_1_val.getText());
                y = Double.parseDouble(in_cord_2_val.getText());
                z = Double.parseDouble(in_cord_3_val.getText());

                if(out_sys.getSelectedIndex() == CYLINDRICAL)
                {
                    /* convert Rectangular coordinates to cylindrical coordinates. */
                    converter.ReToCy(x, y, z);

                    /* Display the resultant values. */
                    out_cord_1_val.setText(fmt.format(converter.getRHO()));
                    out_cord_2_val.setText(fmt.format(converter.getPHI()));
                    out_cord_3_val.setText(fmt.format(converter.getZ()));
                }
                else if(out_sys.getSelectedIndex() == SPHERICAL)
                {

                }
                else
                {
                    System.out.println("Useless to select the same output coordinate as the input coordinates.");
                }
            }
            else if(in_sys.getSelectedIndex() == CYLINDRICAL)
            {
                if(out_sys.getSelectedIndex() == RECTANGULAR)
                {

                }
                else if(out_sys.getSelectedIndex() == SPHERICAL)
                {

                }
                else
                {
                    System.out.println("Useless to select the same output coordinate as the input coordinates.");
                }


            }
            else if(in_sys.getSelectedIndex() == SPHERICAL)
            {
                if(out_sys.getSelectedIndex() == CYLINDRICAL)
                {

                }
                else if(out_sys.getSelectedIndex() == RECTANGULAR)
                {

                }
                else
                {
                    System.out.println("Useless to select the same output coordinate as the input coordinates.");
                }

            }
        }
        else if(source.equals(cancel_button))
        {
            /* Exit the dialogue */
            this.dispose();
        }
        else
        {
            System.out.println("unhandeled even");
        }
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    public void mousePressed(MouseEvent e) {
    }

    public void mouseReleased(MouseEvent e) {
    }
}
