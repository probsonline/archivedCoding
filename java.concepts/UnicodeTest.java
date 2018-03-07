import javax.swing.*;

public class UnicodeTest extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	UnicodeTest(String title) {
		super(title);
		initUI();
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}

	void initUI() {
		JLabel aLabel = new JLabel(new String("\u223F"));
		JPanel templateGen = new JPanel();
		templateGen.add(aLabel);
		getContentPane().add(templateGen);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		System.out.println("In the name of Allah");

		UnicodeTest gst = new UnicodeTest("Testing Unicode");

		gst.setSize(250, 100);
		gst.setResizable(false);
		gst.setVisible(true);

	}

}
