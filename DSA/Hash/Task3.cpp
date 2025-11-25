#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class HashTable 
{
private:
 int* table;
 int s; // Table size
 int n; // Current number of elements
public:
 HashTable(int size)
 {
    s=size;
    n=0;
    table=new int[size];
    for (int i = 0; i < size; i++)
    {
        table[i]=0;
    }
    
 }
 ~HashTable()
 {
    delete table;
 }

 int getRandomNumber(int start, int end) 
{
 return rand() % (end - start + 1) + start;
}

int experiment(int tableSize) 
{
    int num=getRandomNumber(2,3);
    
}

};

using namespace std;
int main() 
{
HashTable h(5);
 srand(static_cast<unsigned>(time(0))); 
 const int numExperiments = 50;
 cout << "Table Size\tAverage Inserted\n";
 cout << "-----------\t----------------\n";
 // Run experiments for table sizes 10, 20, 30, ..., 100
 for (int S = 10; S <= 100; S += 10)
 {
 double totalInserted = 0.0;
 for (int i = 0; i < numExperiments; i++)
 totalInserted += h.experiment(S);
 double averageInserted = totalInserted / numExperiments;
 cout << setw(5) << S << "\t\t" << fixed << setprecision(2)
 << averageInserted << endl;
 }
}
 