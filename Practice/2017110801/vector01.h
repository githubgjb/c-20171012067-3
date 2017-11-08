
#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	vector<int> arr({1,2,3,4,5});
	vector<int>::iterator iter;
	
	for(iter = arr.begin() ; iter != arr.end ; iter++){
		cout << *iter << endl;
	}
	
	return 0;
}