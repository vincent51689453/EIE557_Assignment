#include <iostream>
#include <vector>
#include <math.h>

/*
Compile:
g++ assignment1_question1.cpp -o assignment1_question1 -Wno-psabi

Run:
./assignment1_question1
*/

int xmin = -4;                      // Minimum x values
int xmax = 4;                       // Maximum x values
int num_bits = 8;                   // Number of bits for chromosome
double total_fitness = 0;           // Sum of all fitness values
std::vector<int> chromosomes;       // Store all individual chromosome
std::vector<double> decode_x;       // Part a results
std::vector<double> fitness;        // Part b fitness values
std::vector<double> select_prob;    // Part b selection probability
std::vector<double> acc_prob;       // Accumualted probability



int binaryToDecimal(long long n);   // Binary to Decimal
double f(double x);                 // Assignment 1 Q1 Function

int main()
{
    // Input all individual chromosome
    chromosomes.push_back(binaryToDecimal(100000));     // Individual 1 - Given by the question
    chromosomes.push_back(binaryToDecimal(10011000));   // Individual 2 - Given by the question
    chromosomes.push_back(binaryToDecimal(11001111));   // Individual 3 - Given by the question
    chromosomes.push_back(binaryToDecimal(1110100));    // Individual 4 - Given by the question

    // Decoding by calculating x - Part a
    std::cout << "Part a:" << std::endl;
    for (int i=0;i<chromosomes.size();i++)
    {
        double output = 0;
        output = xmin + chromosomes.at(i)*(xmax-xmin)/(pow(2,num_bits)-1);
        std::cout << "Individual #" << i+1 << ": "<< output << std::endl;
        decode_x.push_back(output);
    }
    std::cout << "----------------------------------------" << std::endl;

    // Calculate fitness, selection probability and accumualted probability - Part b
    std::cout << "Part b:" << std::endl;
    std::cout << "Consider the give function f(x), (pow(x,3)-2*pow(x,2) - x + 2)*exp(pow((x-1),2)*-0.5) < 1";
    std::cout << "Therefore, f(x) can be directly used as a fitness function." << std::endl;

    // Fitness
    //std::cout << "Fitness" << std::endl;
    for (int i=0;i<decode_x.size();i++)
    {
        double output = 0;
        output = f(decode_x.at(i));
        //std::cout << "Individual #" << i << ": "<< output << std::endl;
        total_fitness += output;
        fitness.push_back(output);
    }

    // Selected Probability
    //std::cout << "Selected Probability" << std::endl;
    for (int i=0;i<fitness.size();i++)
    {
        double output = 0;
        output = fitness.at(i)/total_fitness;
        //std::cout << "Individual #" << i << ": "<< output << std::endl;
        select_prob.push_back(output);
    }

    // Accumulated Probability
    //std::cout << "Accumulated Probability" << std::endl;
    double output = 0;
    for (int i=0;i<select_prob.size();i++)
    {
        output += select_prob.at(i);
        //std::cout << "Individual #" << i << ": "<< output << std::endl;
        acc_prob.push_back(output);
    }

    // Summary output
    for (int i=0;i<chromosomes.size();i++)
    {
        std::cout << "Individual #" << i+1 << " | Fitness: " << fitness.at(i) << " | Select P.:" << select_prob.at(i) << " | Accumulated P.: " << acc_prob.at(i) << std::endl;
    }
    return 0;
}

// Given function inside assignment
double f(double x){
    double output = 0;
    output = 1 + (pow(x,3)-2*pow(x,2) - x + 2)*exp(pow((x-1),2)*-0.5);
    return output;
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

