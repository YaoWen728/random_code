
public abstract class Item implements Comparable{
	private String title;
	private double price;
	private String type;
	
	public Item(String titleIn, double priceIn, String typeIn){
		title = titleIn;
		price = priceIn;
		type = typeIn;
	}
	
	public String getTitle(){
		return title;
	} // get title
	
	public double getPrice(){
		return price;
	} // get price
	
	public String getType(){
		return type;
	} // get type
	
	public String toString(){
		return ("Title: " + getTitle() + "\t" + "Price: \t" + getPrice()); 
	} // toString method
	
	public abstract double cost();

	public static void sort(Item[] list){
		int smallest;
		Item holder;
		Item holder2;
		Item holder3;
		int count  = 0;
		int countsort = 0;
		int count2 = 0; 
		
			for(int i = 0 ; i < list.length ; i++){
				String Book = "Book";
				if(list[i].getType().equals("Book")){
					holder = list[i];
					list[i] = list[count];
					list[count] = holder;
					count++;
					countsort++;
				}
			} // sorting all the books first and anything else comes after that.
			
			for(int i = count ; i < list.length ; i++){
				if(list[i].getType().equals("CD")){
					holder = list[i];
					list[i] = list[count];
					list[count] = holder;
					count++;
				}
			} // sorting all the CD, in case entries that is not a Book nor CD.
			
			for(int i = 0 ; i < countsort-1 ; i++){
				smallest = i;
				
				for (int find = i+1; find < countsort-1; find++){
					String First= ((Book)list[i]).getAuthor();
					String Second=((Book)list[find]).getAuthor();
				
				
					if(Second.compareTo(First) < 0){
						smallest = find;
						
						holder2 = list[smallest];
						list[find] = list[i];
						list[i] = holder2;
					}
				}

			} //sorting all the books using the compareTo method. countsort will be length in which all books exist within.
			
			for(int i =countsort ; i < list.length-1 ; i++){
				smallest=i;
				
				for(int find = i+1; find<list.length; find++ ){
					String First= ((CD)list[i]).getComposer();
					String Second=((CD)list[find]).getComposer();
				
					if(Second.compareTo(First) < 0){
						smallest = find;
					
						holder3 = list[smallest];
						list[find] = list[i];
						list[i] = holder3;
					}
				}
			} //sorting all the CD using the compare to method. Starting from countsort, which is where the first CD is located.
	
	}
}
