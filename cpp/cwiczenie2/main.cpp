#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &vec, int low, int high){

	int last = vec[high];
	int i = low - 1;

	for(int j = low; j <= high -1; j++){
		if(vec[j] <= last){
			i++;
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	int temp = vec[i + 1];
	vec[i + 1] = vec[high];
	vec[high] = temp;

	return (i+1);
}

void quickSort(vector<int> &vec, int low, int high){
	if(low < high){

		int pi = partition(vec, low, high);

		quickSort(vec, low, pi - 1);
		quickSort(vec, pi + 1, high);

	}
}

//int main(){
//	vector<int> vec = {24, 34, 57, 92, 12, 34, 32};
//	
//	quickSort(vec, 0, vec.size()-1);
//
//	for(auto i : vec){
//	 	cout<<i<<" ";
//	}
//	return 0;
//}
