#include <stdio.h>
#include <time.h>

void random_walk(int i, int n){
	// i - index of numbers file
	FILE *fp;
	int x, y, z, krok, rx, ry, rz, a;
	int ttt;
	krok=1;

	x=0;
	y=0;
	z=0;
	ttt=time(NULL);
	srand(n*i*ttt);

	char *str;
	sprintf(str, "%d", i);

	fp = fopen(str,"w");
	fprintf(fp,"%d	%d	%d\n", x, y, z);
		
	for(a=0;a<n;a++){
		rx=rand()%3-1;
		ry=rand()%3-1;
		rz=rand()%3-1;	
	
		x=x+rx;
		y=y+ry;
		z=z+rz;
		fprintf(fp,"%d	%d	%d\n", x, y, z);
	}
fclose(fp);
}

int main(){
	//generate random walk files, each file contains n steps
	//each file is one molecule 
	int p; //how many molecules
	int n; //how many steps
	int i;
	n=1000;
	p=1000;


	for(i=1; i<=p; i++){
		random_walk(i, n);
		printf("%d/%d\n", i, p);
	}

	return 0;
}
