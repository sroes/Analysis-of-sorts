/*
 @file   CensusData.h

 @brief  Modified version of CensusData.h with added
         private helper functions
 
 @author Scott Roes

 @date   10/8/19
*/

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData
{
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int);               // sorts data using insertionSort
   void mergeSort(int);                   // sorts data using mergeSort
   void quickSort(int);                   // sorts data using quickSort
private:
   class Record
   {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data; 

   /*
   Added private helper functions
   */
   void merge(int p, int q, int r);
   void mergeN(int p, int q, int r);
   void mergeSort(int r, int s);
   void mergeSortN(int r, int s);
   void quickSort(int p, int r);
   void quickSortN(int p, int r);
   int partition(int p, int r);
   int partitionN(int p, int r);
   int randomPartition(int p, int r);
   int randomPartitionN(int p, int r);



};

#endif // CSCI_311_CENSUSDATA_H
