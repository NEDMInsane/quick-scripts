
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		// 2D arrays
		/* could also be stated like this
		String[][] cars = { {"Camaro", "Corvette", "Silverado"},
							{"Mustang", "Ranger", "F-150"},
							{"Ferrari", "Lamborghini", "Tesla"} };
		*/
		String[][] cars = new String[3][3];
		
		cars[0][0] = "Camaro";
		cars[0][1] = "Corevette";
		cars[0][2] = "Silverado";
		cars[1][0] = "Mustang";
		cars[1][1] = "Ranger";
		cars[1][2] = "F-150";
		cars[2][0] = "Ferarri";
		cars[2][1] = "Lamborghini";
		cars[2][2] = "Tesla";
		
		for(int i = 0; i < cars.length; i++) {
			System.out.println();
			for(int j = 0; j < cars[i].length; j++) {
				System.out.print(cars[i][j] + " ");
			}
		}
		
		
	}

}
