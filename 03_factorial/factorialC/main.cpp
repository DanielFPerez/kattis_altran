#include <iostream>
//#include <time.h>

int main() {
    /*** Read data input ***/
//    clock_t tStart = clock();

    int n_in;
    while (std::cin >> n_in){}

    unsigned long long fact_result = 1;
    int temp = 0;
    unsigned long long n = n_in;

    while(n > 1)
    {
        temp = n;
        fact_result = fact_result * temp;

        while( fact_result % 10 == 0)
        {
            fact_result /= 10;
        }

        if (fact_result > 1000000000000)
        {
            fact_result = fact_result % 1000000000000;
        };

        n -= 1;
    }

    unsigned long long int extract_numb = fact_result % 10000000;

    std::string mystring  = std::to_string(extract_numb);

    if(n_in < 7)
    {
        std::cout << mystring << std::endl;
    }
    else {

        if (mystring.length() < 3) {
            for (int i = 0; i < (3 - mystring.length()); ++i) {
                std::cout << "0";
            }
            std::cout << mystring << std::endl;
        } else {
            std::cout << (mystring.substr(mystring.length() - 3, mystring.length())) << std::endl;
        }
    }

//    printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}