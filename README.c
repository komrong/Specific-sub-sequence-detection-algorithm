//Specific-sub-sequence-detection-algorithm -- Detects sub-sequence that matches the condition

/*
Let a1, a2, . . . , an (n ≥ 2) be a sequence of integers. Find  
a subsequence a(sub)k1, a(sub)k2, . . . , a(sub)km, where 1 ≤ k1 < k2 < · · · < km ≤ n, 
such that a^2(sub)k1 + a^2(sub)k2 + · · · + a^2(sub)km is divisible by n.

*/
My algorithm generates random number of sequence and matches specified condition
analyzing each random sequence.
/*

*/

#include <stdio.h>
#include <time.h>

int main(void){
	int num_run = 700, y, f = 0;
	int count1 = 0;
	for(y = 0; y < num_run; y++){
	f++;
	srand(time(NULL));
	int num_term = rand()%20;
	int seq[num_term];
	int i;
	
	printf("Number of terms in sequence: %d\n", num_term);
	
	for(i = 0; i < num_term; i++){
		seq[i] = rand()%23+2;
		printf("%d ", seq[i]);
	}
	
	printf("\n");
	
	int t;
	int sum = 0;
	int j;
	int count = 0;
	int z, z1;
	for(t = 2; t <= num_term; t++){
		for(i = 0; i < num_term -t + 1; i++){
			for(j = i, z = 0; z < t; z++, j++){
				sum += seq[j]*seq[j];
			}
			
			if(sum % num_term == 0){
				printf("Found subsequence: ");
				for(z1 = i; z1 < i+t; z1++){
					printf("%d ", seq[z1]);
				}
				printf("\n");
				printf("Sum of each squared term of subsequence: %d\n", sum);
				printf("%d is divisible by %d\n", sum, num_term);
				count++;
				count1++;
				break;
			}
			sum = 0;
		}
		if(count != 0){
			break;
		}
	}
	printf("\n");
	printf("\n");
	}
	printf("Number of run-time: %d\n", num_run);
	printf("No. of subsequence found each run-time: %d\n", count1);
	return 0;
	
}
