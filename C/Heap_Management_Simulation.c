#include <stdio.h>

#include <stdlib.h>


static int holes = 0;
struct block* head = NULL;
struct block* tail = NULL;
int max = 800;
int used = 0;

struct block {
  int TF;
  int id;
  int numByte;
  struct block *next;
  struct block *previous;
};

struct block* newBlock(int a, int b){
	struct block* temp = (struct block*)malloc(sizeof(struct block));
	temp->TF = 1;
	temp->id = a;
	temp->numByte = b;
	temp->next = NULL;
	temp->previous = NULL;
	return temp;
}

void allocate(int a, int b){
	struct block* temp = newBlock(a, b);
	int search = 0;
	int smallest = 8000;
	int free = 8000;
	int free2 = 8000;
	int total = max;
	int modify = 0;
	
	total = max - (used + temp->numByte);
	
	if(total < 0){
		printf("Not enough bytes left for this allocation.");
		return;
	}
	
	if(head == NULL && holes == 0){
		head = temp;
		tail = temp;
		modify = 1;
		used = used + temp->numByte;
	} //if nothing in the list
	
	if(holes != 0 && modify == 0 ){ //traverse through list to find best fit hole
		struct block* Trav1 = head;
		struct block* Trav2 = head;
		int count = 0;

		while(Trav1 != NULL){
			if( Trav1->TF == 0 ){
				search = Trav1 -> numByte - temp-> numByte;
				
				if(search < smallest && search >-1){ // find the smallest difference, and a block that fits.
					smallest = search;
					free = Trav1->numByte;
					free2 = Trav1->id;
				}
			}
			Trav1 = Trav1->next;
		} //traverse through the list
		
		
		while(Trav2 != NULL && smallest != 8000 && free != 8000){
			int difference =0;
			if ( Trav2->TF == 0 && free == Trav2->numByte && modify == 0){
				Trav2->TF = 1;
				Trav2->id = temp->id;
				difference = Trav2->numByte - temp->numByte;
				Trav2->numByte = temp->numByte;
				modify = 1; 
			
				used = used + temp->numByte;
				
				if(difference == 0){
					holes--;
				} //if difference is 0, the hole is filled.
				
				if( difference != 0){
					struct block* inNew = (struct block*)malloc(sizeof(struct block));
					struct block* Tnext = Trav2->previous;
					inNew->TF = 0;
					inNew->id = -3;
					inNew->numByte = free - b;
					
					inNew->previous = Trav2->previous;
					inNew->next = Trav2;
					Trav2->previous = inNew;
					Tnext->next = inNew;
				} //Insert new linked list if the difference is not 0
			}
			
				Trav2 = Trav2->next;
		} //insert new element into the best fit hole.
	}
		
	if(holes == 0 && modify == 0){
		head->previous = temp;
		temp->next = head;
		head = temp;
		
		used = used + temp->numByte;
	}//if no holes is in the link list, assign it to the front of the link list.
}

void deallocate(int a){
	int i = a;
	struct block* left;
	struct block* right;
	struct block* Trav = head;
	
	while(Trav != NULL){
		
		if(i == Trav->id){
			left = Trav->next;
			right = Trav->previous;
			
			Trav->TF = 0 ;
			used = used - Trav->numByte;
			
			if(left == NULL && right == NULL){
				head = NULL;
				tail = NULL;
				free(Trav);
				break;
			}
			
			if(left == NULL && right->TF == 1 && Trav->TF == 1){
				holes++;
				break;
			}
			
			
			if(right == NULL && left->TF == 0 && left->next == NULL){
				head = NULL;
				tail = NULL;
				holes--;
				free(Trav);
				free(left);
				break;
			}
			
			
			if(left != NULL && right != NULL){
			
				if(left->TF ==1 && right->TF == 1){
					holes++;
					break;
				}
			
				if(left->TF == 0 && right->TF == 1){
					left->previous = Trav->previous;
					right->next = Trav->next;
					left->numByte = left->numByte + Trav->numByte;
					free(Trav);
					break;
				}
			
			
				if(left->TF == 1 && right->TF == 0){
					left->previous = Trav->previous;
					right->next = Trav->next;
					right->numByte = right->numByte + Trav->numByte;
					free(Trav);
					break;
				}
			
				if(left->TF == 0 && right->TF == 0){
					Trav->previous = right->previous;
					Trav->next = left->next;
					Trav->numByte = Trav->numByte + right->numByte + left->numByte;
					holes--;
					free(left);
					free(right);
					break;
				}
			
			}
			
			if(right == NULL && left->TF == 1){
				head =left;
				head->previous = right;
				free(Trav);
				break;
			}
			
			if(right == NULL && left->TF == 0){
				head = left->next;
				head->previous = right;
				holes--;
				free(Trav);
				free(left);
				break;
			}
			
			if(left == NULL && right->TF == 0){
				right->numByte = right->numByte + Trav->numByte;
				right->next = Trav->next;
				free(Trav);
				break;
			} 
		}
	
		Trav = Trav->next;
	}
}

void SSprint(){
	struct block* Trav = head;
	struct block* Trav2 = tail;
	struct block* Trav3 = head;
	int counter = 0;
	int counter2 = 0;
	int top = 800;
	
	if(head == NULL || tail == NULL){
		printf("List is empty, free space: %d , Holes: %d \n", max, holes);
		return;
	}
	
	while(Trav3 != NULL){
		top = top - Trav3->numByte;
		Trav3 = Trav3->next;
	}
	
	printf("\n");
	/**
	
	while(Trav2 != NULL){
		if(Trav2->TF == 1){
			printf("Allocated ID: %d Byte: %d Previous: %d \n", Trav2->id, Trav2->numByte, Trav2->previous);
		}
		if(Trav2->TF == 0){
			printf("Freespace: %d byte \n", Trav2->numByte);
		}	
		Trav2 = Trav2->previous;
		counter++;
	}
	printf("Freespace left: %d byte \n", top );
	printf("Total space used: %d \n", used );
	
	**/
	
	printf("\n");
	
	printf("Total space used: %d, Number of holes: %d \n", used, holes);
	printf("Freespace: %d byte \n", top );
	while(Trav != NULL){
		if(Trav->TF == 1){
			printf("Allocated ID: %d Byte: %d Next: %d \n", Trav->id, Trav->numByte, Trav->next);
		}
		
		if(Trav->TF == 0){
			printf("Freespace: %d byte \n", Trav->numByte);
		}
			
		Trav = Trav->next;	
		counter2++;
	}
}

stats(){
	int max1  = (double)max;
	int used1 = (double)used;
	double percent = 0;
	int holes1 = 0;
	int inHoles = 0;
	float Average = 0;	
	struct block* Trav = head;
	
	printf("\n");
	
	printf("Used: %d, Max: %d \n", used1, max1);
	
	percent =(((double)used1)*100/max1); 
	
	printf("Percentage of heap used: %f% \n", percent);
			
	while(Trav != NULL){
		if(Trav->TF == 0){
			holes1++;
			inHoles = inHoles + Trav->numByte;
		}
		
		Trav = Trav->next;
	}
	
	printf("Number of holes in the heap: %d \n", holes1);
	
	if(holes1 == 0){
		printf("No holes found, Average: 0");
	}
	
	if(holes1 != 0){	
		Average = (float)inHoles/holes1;
	}
	
	if(holes1 !=0){
		printf("Average size of holes: %f \n", Average);
	}
}

int main(){

	allocate(1,10);
	allocate(2,20);
	allocate(3,10);
	allocate(4,30);
	allocate(5,40);
	allocate(6,25);
	allocate(7,15);
	allocate(8,5);
	allocate(9,35);
	allocate(10,30);
	
	SSprint();
	stats();
		
	deallocate(2);
	deallocate(7);
	
	SSprint();
	stats();

	deallocate(3);
	deallocate(6);
	
	SSprint();
	stats();
	
	deallocate(4);
	
	SSprint();
	stats();
	
	deallocate(10);
	deallocate(9);
	deallocate(1);
	SSprint();
	stats();
	
	allocate(20, 13);
	SSprint();
	stats();
	
	allocate(21, 2);
	SSprint();
	stats();
	
	deallocate(1);
	allocate(40, 8);
	SSprint();
	stats();
	
	deallocate(1);
	deallocate(2);
	allocate(29, 29);
	SSprint();
	stats();
}
