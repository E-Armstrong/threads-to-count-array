// Eric Armstrong

// HW 2

#include<stdio.h>
#include<pthread.h>

int num[]  ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
static int sum;
static int value;

// Start thread method
    void *SumOfArrayElements(int n) {
		int i,j;
		for(i=0; i<10; i++) {
			sum += num[n+i];
		}
	return NULL;

	}
// End of thread method

// Start main
int main(int argc, char *argv[]){
	
	sum = 0;
	
	pthread_t p1[10]; // The thread as an array

	pthread_create(&p1[0],NULL, SumOfArrayElements,0); // Call thread 1 passing array position 
	pthread_create(&p1[1],NULL, SumOfArrayElements,10); // Call thread 2 passing array position 
	pthread_create(&p1[2],NULL, SumOfArrayElements,20); // Call thread 3 passing array position 
	pthread_create(&p1[3],NULL, SumOfArrayElements,30); // Call thread 4 passing array position 

	pthread_join(p1[0],NULL);
	pthread_join(p1[1],NULL);
	pthread_join(p1[2],NULL);
	pthread_join(p1[3],NULL);

	printf("Your sum is: %d \n", sum);
	return(0);
} // End main
