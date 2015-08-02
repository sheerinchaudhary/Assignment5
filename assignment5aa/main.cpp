//This is Sheerin Chaudhary with assignment 5 for summer 2015
//This program will read in a set of datas from input file into three arrays of score1, score2, and score3
//and print them in an output file.It will create a new array of person's bestscores
//and the lowest score of each company and it's position into an output file.
#include <iostream>
#include <fstream>
using namespace std;
const int SCORE=20;
void read3arrays( int[], int[], int[], int);
void print1array(int[],int);
void findlargestscores( int[], int[],int[],int[], int);
void findsmallestandpos( int[], int, int &, int &);
ifstream infile("assignment5input.txt");
ofstream outfile("assignment5output.txt");
int main() {
    int score1[SCORE],score2[SCORE],score3[SCORE];
    int n;
    int largestscores[SCORE];
    int smallest,smallpos;
    cout<<"How many people have their credit scores calculated by three companies"<<endl<<endl;
    cin>>n;
    read3arrays(score1,score2,score3,n);
    outfile<<"The function print1array will print out the person's first credit scores for the company  "<<endl<<endl;
    print1array(score1,n);
    outfile<<endl<<endl;
    outfile<<"The function print1array will print out the person's second credit scores for the  company  "<<endl<<endl;
    print1array(score2,n);
    outfile<<endl<<endl;
    outfile<<"The function print1array will print out the person's third credit scores for the company   "<<endl<<endl;
    print1array(score3,n);
    outfile<<endl<<endl;
    findlargestscores(score1,score2,score3,largestscores, n);
    outfile<<"The function print1array will print out the largest score array for the credit scores "<<endl<<endl;
    print1array(largestscores,n);
    outfile<<endl<<endl;
    findsmallestandpos(score1, n, smallest, smallpos);
    outfile<<"The smallest element in array score1 is "<<smallest<<" this value occurs in position  "<<smallpos<<endl<<endl;
    findsmallestandpos(score2, n, smallest, smallpos);
    outfile<<"The smallest element in array score2 is "<<smallest<<" this value occurs in position  "<<smallpos<<endl<<endl;
    findsmallestandpos(score3, n, smallest, smallpos);
    outfile<<"The smallest element in array score3 is "<<smallest<<" this value occurs in position  "<<smallpos<<endl<<endl;
    findsmallestandpos(largestscores, n, smallest, smallpos);
    outfile<<"The smallest element in array largestscore is "<<smallest<<" this value occurs in position  "<<smallpos<<endl<<endl;
    outfile.close();
    infile.close();
    return 0;
}
//Function read3arrays
//Input:
//  This function will be receiving a paramater value of j and arrays of cred1,cred2,and cred3.
//Process:
//  It will read the input file of j values of the three companies credit scores(cred1,cred2,cred3)
//Output:
//  It will print to the output file of the three credit scores arrays in column on each line.
void read3arrays( int cred1[], int cred2[], int cred3[], int j)
{
    int k;
    for( k=0; k<j; k++) {
        infile >> cred1 [k];
        infile >>cred2 [k];
        infile >>cred3 [k];
        outfile<<cred1[k]<<" "<<cred2[k]<<" "<<cred3[k]<<endl<<
        endl;
    }
    return;
}
//Function print1array
//Input:
//  This function will receive array num and integer j
//Process:
//  It will align each array in six elements on each line and send to outfile file
//Output:
//   It will send to output file of array num of six integers on each line
//  and align each other in columns.
void print1array( int num[], int j)

{
    for(int k=0; k<j; k++) {
        if(k%6==0)
            outfile<<endl<<endl;
        outfile<<" "<<num[k]<<" ";
    }
    return;
}
//Function findlargestscores
//Input:
//  The function will receive three arrays of cred1,cred2,cred3, and integer j
//Process:
//  It will compare each array in every position with one another and compute a new array of bestscores
//  which will be the largest values of each position in the three companies
//Output:
//  It will print out to the main program a new set of array called bestscoreswith the largest
//values in each position of cred1,cred2,and cred3.
void findlargestscores( int cred1[], int cred2[], int cred3[], int bestscores[],int j)
{
    for( int k=0; k<j; k++) {
        if(cred1[k]>=cred2[k])
            bestscores[k]=cred1[k];
        else
            bestscores[k]=cred2[k];
        if(bestscores[k]<cred3[k])
            bestscores[k]=cred3[k];
    }
    
    return;
    
}
//Function findsmallestandpos
//Input:
//  It will receive two reference integers smal and smalpos, an array num, and integer j
//Process:
//  It will compute the smallest values of array num called smal and its positioncalled smalpos
//Output:
//  It will send to the main program the smallest values and the positions of thevalues to the main program

void findsmallestandpos( int num[], int j, int &smal, int &pos)
{
    
    smal= num[0];
    pos=0;
    for(int k=1; k<j; k++){
        if(smal>num[k])
            smal=num[k];
        
        if(num[k]==smal)
            pos=k;
        
    }
    
    return;
}