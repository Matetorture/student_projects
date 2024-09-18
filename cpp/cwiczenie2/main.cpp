#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> vec){
	int last = vec[vec.size()-1];
	int i = -1;

	for(int j = i; j <= last; j++){
		if(vec[j] <= last){
			i++;
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
}

void quickSort(vector<int> vec)

int main(){
	
	return 0;
}
