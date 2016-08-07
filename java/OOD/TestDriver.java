
public class TestDriver {

	public static void main(String[] args) {
		Book Book1 = new Book("Tiger", 13.00, "Book", "abcde");
		Book Book2 = new Book("Lion", 14.00, "Book", "bad");
		Book Book3 = new Book("Penguin", 8.00, "Book", "qopl");
		Book Book4 = new Book("Zebra", 6.00, "Book", "dzbl");
		Book Book5 = new Book("Bird", 10.00, "Book", "xseee");
		
		CD CD1 = new CD("Apple", 15.00, "CD", "gzbe", "zzbe");
		CD CD2 = new CD("orange", 20.00, "CD", "ospl", "bgbgn");
		CD CD3 = new CD("pear", 11.00, "CD", "desdd", "bnbgn");
		CD CD4 = new CD("Grapes", 22.00, "CD", "jhjh", "jhjh");
		CD CD5 = new CD("Berry", 10.00, "CD", "dodo", "mnqp");
		
		
		Item[] Things = new Item[10];
		Things[0] = Book4;
		Things[1] = Book1;
		Things[2] = CD1;
		Things[3] = Book2;
		Things[4] = CD2;
		Things[5] = CD3;
		Things[6] = Book3;
		Things[7] = CD5;
		Things[8] = CD4;
		Things[9] = Book5;
		
		for(int i = 0; i<Things.length; i++){
			System.out.println(Things[i].toString());
		}
		
		System.out.println();
		System.out.println();
		System.out.println();
		
		Item.sort(Things);
		
		for(int i = 0; i<Things.length; i++){
			System.out.println(Things[i].toString());
		}
	}

}
