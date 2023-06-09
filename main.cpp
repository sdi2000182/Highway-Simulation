#include <iostream>
#include "attiki1.h"
#include <ctime>

using namespace std;

int Highway::K;
int Highway::Percent;
int Highway::Nsegs;


int main(int argc, char * argv[]){
	srand(time(NULL));
	int i;
	if (argc!=5){
		cout << "Wrong number of arguments\n";
		return -1;
	}
	else{
		int N=atoi(argv[1]);
		Highway::Nsegs=atoi(argv[2]); //arithmos komvwn
		Highway::K=atoi(argv[3]);//maximum 
		Highway::Percent=atoi(argv[4]);//pososto
		if(Highway::Percent>100){
			cout << "Percent should be less than 100\n";
			return -1;
		}
		Highway odos;
		for(i=0;i<N;i++){
			odos.operate();
		}
		cout << "End of simulation\n";
		return 0;
		
	}
	
}