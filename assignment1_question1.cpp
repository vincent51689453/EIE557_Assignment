#include <iostream>
#include <vector>
#include <math.h>

/*
Compile:
g++ assignment1_question1.cpp -o assignment1_question1

Run:
./assignment1_question1
*/

int xmin = -4;                  // Minimum x values
int xmax = 4;                   // Maximum x values
int num_bits = 8;               // Number of bits for chromosome
std::vector<int> chromosomes;   // Store all individual chromosome


int binaryToDecimal(long long n);

int main()
{
    // Input all individual chromosome
    chromosomes.push_back(binaryToDecimal(100000));     // Individual 1
    chromosomes.push_back(binaryToDecimal(10011000));   // Individual 2
    chromosomes.push_back(binaryToDecimal(11001111));   // Individual 3
    chromosomes.push_back(binaryToDecimal(1110100));    // Individual 4

    // Decoding by calculating x
    for (int i=0;i<chromosomes.size();i++)
    {
        double output = 0;
        output = xmin + chromosomes.at(i)*(xmax-xmin)/(pow(2,num_bits)-1);
        std::cout << "Part a:" << std::endl;
        std::cout << "Individual #" << i << ": "<< output << std::endl;
    }

    return 0;
}

// Function to convert binary to decimal
int binaryToDecimal(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

