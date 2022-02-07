import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		/* TODO Auto-generated method stub
		println creates a newline?
		*/
		System.out.println("\tI love pizza");
		// \t adds a tab
		// \n creates newline adding this to println adds an additional line
		System.out.print("\"It's really good.\"" + " -New York Times\n");
		// \" adds quotes
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("What is your name? ");
		String name = scanner.nextLine();
		
		System.out.println("Hello "+name);
		
		

	}

}
