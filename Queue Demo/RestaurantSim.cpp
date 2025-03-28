// Programmer: Cheyenne Frediani-Jost
// Programmer ID: 1429200

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>

#include "Queue.h"
#include "DynamicArray.h"

int getRandomNumberOfArrivals(double); // Poisson Function Prototype to generate new arrivals

struct Customer
{
  char id;
  int arrivalTime;
  int endTime;
};

int main()
{
  // Programmer's Identification
  cout << "Programmer Name (Last, First): Frediani-Jost, Cheyenne\n";
  cout << "Programmer's ID: 1429200\n";
  cout << "File: " << __FILE__ << "\n" << endl;
  
  Queue<Customer> waitLine; // Line structure
  DynamicArray<Customer> serving; // Checkout structure
  DynamicArray<bool> serverStatus; // Bool array to track Checkout Status
  int serversNum; // Number of servers
  double rate;  // Rate of customers arriving per minute
  int waitLength; // Maximum number of people who can be in line
  int minTime; // Fastest possible check out
  int maxTime; // Slowest possible check out
  int totalTime; // Time until new arrivals stop (store closes)
  
  int newArrivals; // Customer holder
  char Id = 'A'; // Customer ID counter
  
  // Seed Random Time for program
  srand(time(0));
  
  // Read the input file
  ifstream fin;
  string buf;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";
  else
  {
    cout << "File contents: \n";
    fin >> buf;
    serversNum = atof(buf.c_str());
    fin >> buf;
    rate = atof(buf.c_str());
    fin >> buf;
    waitLength = atof(buf.c_str());
    fin >> buf;
    minTime = atof(buf.c_str());
    fin >> buf;
    maxTime = atof(buf.c_str());
    fin >> buf;
    totalTime = atof(buf.c_str());
  }
  // Close File
  fin.close();
  
  // Check inputs
  cout << "Number of servers: " << serversNum << endl;
  cout << "Customer arrival rate: " << rate << " per minute, for "  << totalTime << endl;
  cout << "Maximum Queue length: " << waitLength << endl;
  cout << "Minimum service wait time: " << minTime << endl;
  cout << "Maximum service wait time: " << maxTime << endl << endl;
  
  
  // Begin Running Simulation
  for (int time = 0; ; time++) // Clock time
  {
    // Handle all services scheduled to finish at current time
    for(int i = 0; i < serversNum; i++)
    {
      if (serverStatus[i] == true)
        if (serving[i].endTime == time)
          serverStatus[i] = false;
    }
    
    // Handle new arrivals IF totalTime has not been reached
    if (time < totalTime)
    {
      //get new arrivals
      newArrivals = getRandomNumberOfArrivals(rate);
      for (int i = 0; i < newArrivals; i++)
      {
        if (waitLine.size() < waitLength) // if there is room in line
        {
          // Assign ID and create customer
          Customer nextInLine = {Id,time};
          waitLine.push(nextInLine);
          Id += 1;
          if (Id == 'Z' + 1) Id = 'A'; // reset ID generator if entire alpha is use
        }
      }
    } // end new arrival check in
    
    //Check Server Status
    int i = 0;
    for(; i < serversNum; i++)
    {
      if(serverStatus[i] == false && waitLine.empty() == false)
      {
        serving[i] = waitLine.front();
        waitLine.pop();
        
        serving[i].endTime = time + (rand() % maxTime + minTime);
        serverStatus[i] = true;
      }
    }
    
    // Display Summary ------------------------------------------------------------
    cout << "\nTime: ";
    setw(4);
    cout << time << endl;
    cout << "---------------------------\n";
    setw(7);
    cout << "Server ";
    setw(12);
    cout << "Now Serving ";
    setw(12);
    cout << "Wait Queue\n";
    setw(7);
    cout << "------ ";
    setw(12);
    cout << "----------- ";
    setw(12);
    cout << "----------\n";
    
    for (int i = 0; i < serversNum; i++) // For all servers
    {
      // Cout server Num
      //setw(4);
      cout << i + 1 << "        ";
      
      // Cout now serving
      if (serverStatus[i] == true) // If current server is occupied
      {
        //setw(7);
        cout << serving[i].id << "          ";
      }
      else cout << " ";
      
      // Cout wait queue
      if(i == 0)
      {
        if (waitLine.empty() == false)
        {
          Queue<Customer> lineCopy = waitLine; // Copy line to pop
          for (int i = 0; i < waitLength; i++)
          {
            Customer current = lineCopy.front();
            cout << current.id;
            lineCopy.pop();
          }
        }
        else cout << " ";
      }
      
      cout << endl;
    }
    cout << "\n----------------------------\n";
    
    // Check for end simulation conditions
    bool end = false;
    if (waitLine.size() == 0 && time >= totalTime)
    {
      for (int i =0; i < serversNum; i++)
      {
        if(serverStatus[i]) break;
        end = true;
      }
    }
    if(end) {cout << "\nSimulation end!\n"; break;}
    
    cout << "Press ENTER to continue....";
    cin.get();
    
  } // end clock
}; // end main

int getRandomNumberOfArrivals(double avgArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-avgArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX;
       (randomValue -= probOfnArrivals) > 0;
       probOfnArrivals *= avgArrivalRate / static_cast<double>(++arrivals));
  return arrivals;
}
