#include <iostream>
#include <vector>
#include <math.h>
#include <string>

/*
Author: VincentChan
Compile:
g++ assignment1_question1.cpp -o assignment1_question1 -Wno-psabi

Run:
./assignment1_question1
*/

int xmin = -4;                              // Minimum x values
int xmax = 4;                               // Maximum x values
int num_bits = 8;                           // Number of bits for chromosome
double total_fitness = 0;                   // Sum of all fitness values
std::vector<double> random_number;          // Given list of random number
std::vector<int> chromosomes;               // Store all individual chromosome
std::vector<double> decode_x;               // Part a results
std::vector<double> fitness;                // Part b fitness values
std::vector<double> select_prob;            // Part b selection probability
std::vector<double> acc_prob;               // Part b accumualted probability
std::vector<std::string> bin_chromosomes;   // Part c chromosome in string



int binaryToDecimal(long long n);   // Binary to Decimal
double f(double x);                 // Assignment 1 Q1 Function

int main()
{
    // Input the given random number list
    random_number = {0.9058, 0.7943, 0.3786, 0.6820, 0.0942, 0.5407,0.5606, 0.8541, 0.1321, 0.1704, 0.3551, 0.6938, \
                    0.1270, 0.3112, 0.8116, 0.0424, 0.5985, 0.8699,0.9296, 0.3479, 0.7227, 0.2578, 0.9970, 0.0098,  \
                    0.9134, 0.5285, 0.5328, 0.0714, 0.4709, 0.2648,0.6967, 0.4460, 0.1104, 0.3968, 0.2242, 0.8432,  \
                    0.6324, 0.1656, 0.3507, 0.5216, 0.6959, 0.3181,0.5828, 0.0542, 0.1175, 0.0740, 0.6525, 0.9223};

    // Input all individual chromosome
    // Current generation
    //chromosomes.push_back(binaryToDecimal(100000));     // Individual 1 - Given by the question
    //chromosomes.push_back(binaryToDecimal(10011000));   // Individual 2 - Given by the question
    //chromosomes.push_back(binaryToDecimal(11001111));   // Individual 3 - Given by the question
    //chromosomes.push_back(binaryToDecimal(1110100));    // Individual 4 - Given by the question
    
    // New generation
    chromosomes.push_back(binaryToDecimal(11000));        // Individual 1 - Given by the question
    chromosomes.push_back(binaryToDecimal(11010100));     // Individual 2 - Given by the question
    chromosomes.push_back(binaryToDecimal(10111000));     // Individual 3 - Given by the question
    chromosomes.push_back(binaryToDecimal(1110100));      // Individual 4 - Given by the question    

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
    // ******************* Part a DONE *******************  //

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
    std::cout << "----------------------------------------" << std::endl;
    // ******************* Part b DONE *******************  //

    // Crossovoer and Mutation - Part C & D
    std::cout << "Part c & d:" << std::endl;
    bin_chromosomes.push_back("00100000");  //Binary form of individual 1
    bin_chromosomes.push_back("10011000");  //Binary form of individual 2
    bin_chromosomes.push_back("11001111");  //Binary form of individual 3
    bin_chromosomes.push_back("01110100");  //Binary form of individual 4

    std::cout << "Not calculation.. skipped " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    // ******************* Part C&D DONE *******************  //

    // Elitism
    std::cout << "Part e:" << std::endl;
    std::cout << "Please change the chromosomes vector to calculate new fitness vector" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    // ******************* Part E DONE *******************  //



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

