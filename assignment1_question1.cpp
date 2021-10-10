#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>

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

int num_particles = 4;                      // Part f number of particles
int random_indicator = 0;                   // Part f indicate which random number should be used
double weight = 0.9;                        // Part f inertia weight
double c1 = 2;                              // Part f acceleartion
double c2 = 2;                              // Part f acceleartion
double vmax = 3;                            // Part f maximum velocity
std::vector<double> particles_x;            // Part f PSO particles x
std::vector<double> particles_v;            // Part f PSO particles v
std::vector<double> particles_y;            // Part f PSO particles y
std::map<double,double> global_best;        // Part f Global Best position
std::map<double,double>::iterator itr;      // Part f global best iterator

std::vector<double> particles_x2;            // Part f PSO particles x
std::vector<double> particles_v2;            // Part f PSO particles v
std::vector<double> particles_y2;            // Part f PSO particles y
std::map<double,double> global_best2;        // Part f Global Best position


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

    // Global PSO
    // 1. Initialize the populations
    std::cout << "Part f:" << std::endl;
    for(int i=0;i<num_particles;i++)
    {
        double xi = 0;
        double vi = 0;
        xi = xmin + random_number.at(random_indicator)*(xmax-xmin);
        //vi = xmin + random_number.at(random_indicator+1)*(xmax-xmin);
        vi = 0;
        particles_x.push_back(xi);
        particles_v.push_back(vi);
        random_indicator ++;
    }
    std::cout << "Step 1: Particles initialization" << std::endl;
    for(int i = 0;i<num_particles;i++)
    {
        std::cout << "Particle #" << i+1 << " | xi = " << particles_x.at(i) << " | vi = " << particles_v.at(i) << std::endl;
    }
    std::cout << "Random number indicator = " << random_indicator << std::endl;

    // 2. Evaluate fitness of each particle
    std::cout << std::endl;
    std::cout << "Step 2: Evaulate Fitness of each particles" << std::endl;
    for(int i=0;i<num_particles;i++)
    {
        double result;
        result = f(particles_x.at(i));
        std::cout << "f(x" << i+1 << ") = " << result << std::endl;
        global_best.insert(std::make_pair(result,particles_x.at(i)));
        particles_y.push_back(result);
    }

    //3. Find out the global best in step 2
    itr = global_best.end();
    itr--;
    std::cout << std::endl;
    std::cout << "Step 3: Global Best Position" << std::endl;
    std::cout << "x = " << itr->second << " | f(x) = " << itr->first << std::endl;

    //4. Calculate the new velocity and position of each particle (t = t+1)
    std::cout << std::endl;
    std::cout<< "Step 4: Calculate new velocity and positions" << std::endl;
    // First Iteration
    std::cout << "First iteration..." << std::endl;
    for(int i=0l;i<num_particles;i++)
    {
        double new_v;
        //new_v = weight*particles_v.at(i) + c1*random_number.at(random_indicator)*(particles_y.at(i)-particles_x.at(i)) + \
        //c2*random_number.at(random_indicator+1)*(itr->second-particles_x.at(i));
        // Current posiion is the global best
        new_v = weight*particles_v.at(i) + c2*random_number.at(random_indicator)*(itr->second-particles_x.at(i));
        double new_x;
        new_x = particles_x.at(i) + new_v;

        particles_x2.push_back(new_x);
        particles_y2.push_back(new_v);
        particles_y2.push_back(f(new_x));
        random_indicator ++;
        std::cout << "Particle #" << i+1 << "| new_v = " << new_v  << " | new_x = " << new_x << "| new_f(x) = " << f(new_x) <<std::endl;
    }
    std::cout << "Random number indicator = " << random_indicator << std::endl;

    // Second Iteration
    std::cout << std::endl;
    std::cout << "Second iteration..." << std::endl;
    for(int i=0l;i<num_particles;i++)
    {
        double new_v;
        new_v = weight*particles_v.at(i) + c1*random_number.at(random_indicator)*(itr->second-particles_x.at(i)) + \
        c2*random_number.at(random_indicator+1)*(itr->second-particles_x.at(i));

        double new_x;
        new_x = particles_x.at(i) + new_v;

        //particles_x2.push_back(new_x);
        //particles_y2.push_back(new_v);
        //particles_y2.push_back(f(new_x));
        random_indicator += 2;
        std::cout << "Particle #" << i+1 << "| new_v = " << new_v  << " | new_x = " << new_x << "| new_f(x) = " << f(new_x) <<std::endl;
    }
    std::cout << "Random number indicator = " << random_indicator << std::endl;    

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

