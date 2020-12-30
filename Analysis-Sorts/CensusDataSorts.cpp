/*
 @file   CensusDataSorts.cpp

 @brief  In CensusDataSorts this file contains all the sorting functions
         (Insertion, Merge, Quick) along with merge functions for
         merge sort and partition for quick sort. All of these functions
         are responsible for retrieving data from CensusSort.cpp
         and sorting that data from the census files.

 @author Scott Roes
        
 @date   10/8/19         

 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <chrono>
#include <random>
#include "CensusData.h"

/*
 @brief   This function takes in an int that determines
          if sorting by population or name then sorts
          the data using insertion sort.

 @param   integer s for population int.

 @retrun  Nothing.

*/
void CensusData::insertionSort(int s)
{


   if(s == 0) //if population
   {
      
     Record *key;
   
    
      for(int j = 1; j < getSize(); j++)
      {
       
          key = data[j];
    
          int i = j - 1;
        
    
         while(i >= 0 && data[i]->population > key->population)
         {
           
             data[i + 1] = data[i];
             i = i-1;
            
         }
             data[i + 1] = key;

      }
    
    
   }
   if(s == 1) //if name
   {

      Record *key;
   
    
     for(int j = 1; j < getSize(); j++)
     {
      
         key = data[j];
    
         int i = j - 1;
        
       
         while(i >= 0 && *(data[i]->city) > *(key->city))
         {
           
            
             data[i + 1] = data[i];
             i = i-1;
            
         }
             data[i + 1] = key;

    }
    
  }



}
/*
 @brief   This function takes in an int that determines
          if sorting by population or name then calls
          mergeSort (by population) or mergeSort (by name) to sort the data.

 @param   integer s for population int.

 @return  Nothing.

*/
void CensusData::mergeSort(int s) 
{

   if(s == 0) //if population
   {
     int p, r;

     r = getSize() - 1;
     p = 0;

     mergeSort(p, r);

   }

   if (s == 1) //if name
   {
     int p, r;

     r = getSize() - 1;
     p = 0;

     mergeSortN(p, r);


   }
}
/*


 @brief   This merge sort by name function calls mergeN to sort the data
          by name.

 @param   integers p and r for merge sorting by name.

 @return  Nothing.

*/
void CensusData::mergeSortN(int p, int r)
{
   if(p < r)
   {
     int q = (p + r) / 2;
     mergeSortN(p, q);
     mergeSortN(q + 1, r);
     mergeN(p, q, r);

   }
}
/*
 
 @brief   This merge sort by population function calls merge
          to sort the data by population.

 @param   integers p and r for merge sorting by population.

 @return  Nothing.

*/
void CensusData::mergeSort(int p, int r)
{
   if(p < r)
   {
     int q = (p + r) / 2;
     mergeSort(p, q);
     mergeSort(q + 1, r);
     merge(p, q, r);

   }
}
/*
 @brief   This function is where the actual merge
          sorting by population takes place. It takes the 
          left and right parts of the data, sorts them,
          then merges them together.

 @param   integers p, q, and r for merge sorting by population.

 @return  Nothing.

*/
void CensusData::merge(int p, int q, int r)
{
    
   
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<Record*> L;
    vector<Record*> R;
  
    

    for(int i = 0; i < n1; i++)
    {
       
       L.push_back(data[i+p]);
    }

    
    for(int j = 0; j < n2; j++)
    {
    
        R.push_back(data[q+j+1]);
    }

   
  
    string temp = "";
    L.push_back(new Record(temp, temp, INT_MAX));
    R.push_back(new Record(temp, temp, INT_MAX));
   
    int i = 0;
    int j = 0;

    for(int k = p; k <= r; k++)
    {

        if(i != n1 && L[i]->population <= R[j]->population)
        {
            data[k] = L[i];
            i = i + 1;

        }
        else if(j != n2 && L[i]->population >= R[j]->population)
        {
            data[k] = R[j];
            j = j + 1;
        }   

    }

}
/*
 @brief   This function is where the actual merge
          sorting by name takes place. It takes the 
          left and right parts of the data, sorts them,
          then merges them together. 

 @param   integers p, q, and r for merge sorting by name.

 @return  Nothing.

*/
void CensusData::mergeN(int p, int q, int r)
{
    
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<Record*> L;
    vector<Record*> R;
  
    
    for(int i = 0; i < n1; i++)
    {
      
       L.push_back(data[i+p]);
    }

    
    for(int j = 0; j < n2; j++)
    {
       
        R.push_back(data[q+j+1]);
    }

 
    string temp = "{";
    L.push_back(new Record(temp, temp, INT_MAX));
    R.push_back(new Record(temp, temp, INT_MAX));
   
    int i = 0;
    int j = 0;

    for(int k = p; k <= r; k++)
    {

        if(i != n1 && *(L[i]->city) <= *(R[j]->city))
        {
            data[k] = L[i];
            i = i + 1;

        }
        else if(j != n2 && *(L[i]->city) >= *(R[j]->city))
        {
            data[k] = R[j];
            j = j + 1;
        }    

    }

}
/*
 @brief   This function takes in an int that determines if
          sorting by population or name. In this function is 
          a random number generator that will generate a random
          index in QuickSort (population) and QuickSortN (name) 
          functions. 

 @param   integer s for population int.

 @return  Nothing.

*/
void CensusData::quickSort(int s)
{

    if(s == 0)
    {
      int p, r;

      r = getSize() - 1;
      p = 0;
     
      quickSort(p, r);
    }

    if(s == 1)
    {
      int p, r;

      r = getSize() - 1;
      p = 0;
 
      quickSortN(p, r);

    }

}
/*
 @brief   This qucick sort by population function calls 
          randomPartitionN that will randomize the pivot then 
          quicksort the data by population.

 @param   integers p and r for population ints.

 @return  Nothing.

*/
void CensusData::quickSort(int p, int r)
{
 
   if(p < r)
   {
     int q = randomPartition(p, r);
     quickSort(p, q - 1);
     quickSort(q + 1, r);

   }

}
/*
 @brief   This qucick sort by name function calls
          randomPartitionN that will randomize the pivot then 
          quicksort the data by name.

 @param   integers p and r for name ints.

 @return  Nothing.

*/
void CensusData::quickSortN(int p, int r)
{
 
   if(p < r)
   {
     int q = randomPartitionN(p, r);
     quickSortN(p, q - 1);
     quickSortN(q + 1, r);

   }

}
/*
 @brief   This function is where the actual quick sorting
          by population takes place. The pivot divides
          two parts into the file and places the
          smaller data to the left of it and the larger 
          data to the right of it.

 @param   integers p and r for population ints.

 @return  integer i + 1 partition.

*/
int CensusData::partition(int p, int r)
{

    Record * x = data[r];

    int i = p - 1;

    for(int j = p; j < r; j++)
    {
       if(data[j]->population <= x->population)
       {
         i = i + 1;
                  
        std::swap(data[i], data[j]);

       }
    }
    std::swap(data[i + 1], data[r]);
    return i + 1;
}
/*
 @brief   randomizing partition by population. Set the pivot
          to a random engine generator, swap the data and return
          the data.

 @param   integers p and r for population.

 @return  call to partition with parameters of p and r.

*/
int CensusData::randomPartition(int p, int r)
{
      
    unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed); 
    std::uniform_int_distribution<int> distribution(p,r);

    int i = distribution(generator);
    std::swap(data[r], data[i]);

    return partition(p, r);
}
/*
 @brief   randomizing partition by name. Set the pivot
          to a random engine generator, swap the data and return
          the data.

 @param   integers p and r for name.

 @return  call to partitionN with parameters p and r.

*/
int CensusData::randomPartitionN(int p, int r)
{
   
    unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(p,r);

    int i = distribution(generator);
    std::swap(data[r], data[i]);

    return partitionN(p, r);
}

/*
 @brief   This function is where the actual quick sorting
          by name takes place. The randomized pivot 
          divides two parts into the file and places the
          smaller data to the left of it and the larger 
          data to the right of it.

 @param   integers p and r for name.

 @return    integer i + 1 partitionN.

*/
int CensusData::partitionN(int p, int r)
{

    Record *x = data[r];
    int i = p - 1;

    for(int j = p; j < r; j++)
    {
       if(*(data[j]->city) <= *(x->city))
       {
         i = i + 1;            

        std::swap(data[i], data[j]);

       }

    }
    std::swap(data[i + 1], data[r]);
    return i + 1;
}
