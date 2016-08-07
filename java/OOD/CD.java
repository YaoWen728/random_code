
public class CD extends Item{
	private String artist;
	private String composer;
	
	public CD(String titleIn, double priceIn, String typeIn, String artistIn, String composerIn){
		super(titleIn, priceIn, typeIn);
		artist = artistIn;
		composer = composerIn;
	}
	
	public String getArtist(){
		return artist;
	} // get artist
	
	public String getComposer(){
		return composer;
	} // get composer
	
	public double cost(){
		double total;
		total = super.getPrice() * 1.13;
		return total;
	} //the abstract cost method.
	
	public String toString(){
		return ("Title: " + super.getTitle() + "\t" + "Price: " + super.getPrice() +"\tTotal: "+ this.cost() + "\t Artist: " + this.getArtist() + "\t Composer: " + this.getComposer());
	} // override toString method
	
	public int compareTo(Object other){
		int result;
		
		String otherType =((Item)other).getType();
		String otherComposer =((CD)other).getComposer();
		String otherTitle =((CD)other).getTitle();
		
		if(super.getType().equals(otherType)){
			if(composer.equals(otherComposer)){
				result = super.getTitle().compareTo(otherTitle);
			}
			else{
				result = this.getComposer().compareTo(otherComposer);
			}	
		}
		
		else
			result = super.getType().compareTo(otherType);
		
		return result;
	} // the compareTo method from class modified for the use of this assignment.

}
