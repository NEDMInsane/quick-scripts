import java.util.Scanner;
import java.util.Random;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Random rand = new Random();
		double x = 3.14159;
		double y = -10;
		
		double z = Math.max(x, y);
		/*
		Scanner s = new Scanner(System.in);
		
		
		System.out.println("Enter side x: ");
		x = s.nextDouble();
		System.out.println("Enter side y: ");
		y = s.nextDouble();
		
		z = Math.sqrt((x*x)+(y*y));
		System.out.println("The hypatenuse is: "+z);
		
		s.close();
		*/
		int r = rand.nextInt();
		System.out.println(r);
	}

}
