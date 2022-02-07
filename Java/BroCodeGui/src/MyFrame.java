import java.awt.Color;

import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class MyFrame extends JFrame {
	
	MyFrame(){
		
		this.setTitle("JFrame Title example"); //sets the title of the window
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //exit out of the application
		this.setSize(420, 420); //sets the x-dimension and y-dimension of the frame.
		this.setResizable(false); //prevents the frame from being resized
		this.setVisible(true); //allows us to see the frame
		
		ImageIcon image = new ImageIcon("devildog.jpg"); //creates ImageIcon
		this.setIconImage(image.getImage()); //change icon of JFrame
		
		//color allows specific colors, Green, Blue ect, or make your own using RGB values or Hex values
		this.getContentPane().setBackground(new Color(100, 25, 255)); //change background color

	}
}