public class Book extends Item{
		private String author;
		
		public Book(String titleIn, double priceIn, String typeIn, String authorIn){
			super(titleIn, priceIn, typeIn);
			author = authorIn;
		}
		
		public String getAuthor(){
			return author;
		} // get method for author
		
		public double cost(){
			double total;
			total = super.getPrice();
			return total;
		} // get cost
		
		public String toString(){
			return ("Title: " + super.getTitle() + "\t" + "Price: " + super.getPrice() +"\t Total: "+ this.cost()  + "\t Author: " + this.getAuthor());
		} //Override toString method
		
		public int compareTo(Object other){
			int result;
			
			String otherType =((Item)other).getType();
			String otherAuthor =((Book)other).getAuthor();
			String otherTitle =((Book)other).getTitle();
			
			if(super.getType().equals(otherType)){
				if(author.equals(otherAuthor)){
					result = super.getTitle().compareTo(otherTitle);
				}
				else{
					result = this.getAuthor().compareTo(otherAuthor);
				}	
			}
			
			else
				result = super.getType().compareTo(otherType);
			
			return result;
		} // the compareTo method from class modified for the use of this assignment.
		
	}


