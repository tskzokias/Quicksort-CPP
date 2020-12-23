#include <iostream> //cout, endl
#include <random>  
#include <algorithm>//copy, random_shuffle
#include <iterator> //ostream_iterator
#include <ctime>    //std::time (NULL) to seed srand
#include "quicksort.h"



int main() {
	const int n = 1000;
	int a[n];
	for ( int i=0; i<n; ++i ) { a[i] = i; }
	
//    std::copy(a, a + n, std::ostream_iterator<int>(std::cout, " ")); 
//    std::cout << std::endl;

    bool OK = true;
    for ( int i=0; i<5000 and OK; ++i ) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle( a, a+n, g );

        quicksort(a,0,n);

        //    std::copy(a, a + n, std::ostream_iterator<int>(std::cout, " "));
        //    std::cout << std::endl;

        //check result
        for ( int i=0; i<n; ++i ) {
            if ( a[i] != i ) {
                std::cout << "Error at index " << i << std::endl;
                OK = false;
            }
        }
    }

    if ( OK ) {
        std::cout << "OK" << std::endl;
    }
    return OK;
}
