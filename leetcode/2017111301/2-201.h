#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() {

    for( int x = 1 ; x <= 9 ; x ++ ){

        int n = pow(10, x); //10的x次方

        clock_t startTime = clock();

        int sum = 0;
        for( int i = 0 ; i < n ; i ++ )
            sum += i;  //从0到n减一的和
        clock_t endTime = clock();

        cout<<"10^"<<x<<" : "<<double(endTime - startTime)/CLOCKS_PER_SEC<<" s"<<endl;
    }
    return 0;
}