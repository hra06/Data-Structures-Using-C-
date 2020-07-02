#include<iostream>
#include<climits>
using namespace std;


//Recursive BruteForce Solution
int minStepFn(int n){
	if(n==1){
		return 0;
	}
	
	int x = INT_MAX;
	int y = INT_MAX;
	int z = INT_MAX;
	if(n >1){
		x = minStepFn(n-1);
	}
	if(n>=3 && n%3==0){
		y = minStepFn(n/3);
	}
	if(n>=2 && n%2==0){
		z = minStepFn(n/2);
	}
	
	if(x<=y && x<=z){
		return x+1;
	}else if(y<=x && y<= z){
		return y+1;
	}else{
		return z+1;
	}
}
	

int main() {
	int n;
	cout<<"Enter the number of whom we want to calculate the min steps\n";
	cin>>n;
	int minStep = minStepFn(n);
	cout<<minStep<<endl;
	return 0;
}
