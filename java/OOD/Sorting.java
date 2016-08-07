
public class Sorting {
	
	public static void sort(Item[] list){
		int smallest=-1;
		Item holder;
		Item holder2;
		Item holder3;
		int count  = 0;
		int countsort = 0;
		int count2 = 0; 
		
			for(int i = 0 ; i < list.length ; i++){
				if(list[i].getType().equals("Book")){
					holder = list[i];
					list[i] = list[count];
					list[count] = holder;
					count++;
					countsort++;
				}
			} // sorting all the books first and anything else comes after that.

			for(int i = count ; i < list.length-1 ; i++){
				if(list[i].getType().equals("CD")){
					holder = list[i];
					list[i] = list[count];
					list[count] = holder;
					count++;
				}
			} // sorting all the CD and everything else that isn't book or CD comes after that.
			
			
			for(int i = 0 ; i < countsort-1 ; i++){
				String First= ((Book)list[i]).getAuthor();
				String Second=((Book)list[i+1]).getAuthor();
				
				if(Second.compareTo(First) < 0){
					smallest = i+1;
				}
				
				holder2 = list[smallest];
				list[i+1] = list[i];
				list[i] = holder2;
			} //sorting all the books using the compareTo method
			
			for(int i =countsort ; i < count-1 ; i++){
				String First= ((CD)list[i]).getComposer();
				String Second=((CD)list[i+1]).getComposer();
				
				if(Second.compareTo(First) < 0){
					smallest = i+1;
				}
				
				holder3 = list[smallest];
				list[i+1] = list[i];
				list[i] = holder3;
			} //sorting all the books using the compare to method.
	}
}
