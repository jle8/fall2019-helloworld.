#include <iostream>
#include <fstream>
#include <math.h>
#include <cctype>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

//probability calculator function for bigrams
double probCalc(double countforChar, double totSum){
    double val = countforChar/totSum;
    return val * 100;
}

//probability calculator for all characters
void probforEach(string textfile, double totSum){
  ifstream inFile;
  inFile.open(textfile);
  int countA = 0;
  int countC = 0;
  int countT = 0;
  int countG = 0;

  int countAA = 0;
  int countAC = 0;
  int countAT = 0;
  int countAG = 0;

  int countCA = 0;
  int countCC = 0;
  int countCT = 0;
  int countCG = 0;

  int countTA = 0;
  int countTC = 0;
  int countTT = 0;
  int countTG = 0;

  int countGA = 0;
  int countGC = 0;
  int countGT = 0;
  int countGG = 0;

  string bi = "";  // bigram storage

  //counts the characters and bigrams
  string x;
  while (inFile >> x)
  {
    for(int i = 0; i < x.size(); i++){
      if(x.at(i) == 'A'){
        countA += 1;
      }
      else if(x.at(i) == 'C'){
        countC += 1;
      }
      else if(x.at(i) == 'T'){
        countT += 1;
      }
      else if(x.at(i) == 'G'){
        countG += 1;
      }

      bi = bi + x.at(i);

      /*********BIGRAM CHECKER********/

      if(bi.size() == 2){
        if(bi == "AA"){
          countAA += 1;
        }
        else if(bi == "AC"){
          countAC += 1;
        }
        else if(bi == "AT"){
          countAT += 1;
        }
        else if(bi == "AG"){
          countAG += 1;
        }
        else if(bi == "CA"){
          countCA += 1;
        }
        else if(bi == "CC"){
          countCC += 1;
        }
        else if(bi == "CT"){
          countCT += 1;
        }
        else if(bi == "CG"){
          countCG += 1;
        }
        else if(bi == "TA"){
          countTA += 1;
        }
        else if(bi == "TC"){
          countTC += 1;
        }
        else if(bi == "TT"){
          countTT += 1;
        }
        else if(bi == "TG"){
          countTG += 1;
        }
        else if(bi == "GA"){
          countGA += 1;
        }
        else if(bi == "GC"){
          countGC += 1;
        }
        if(bi == "GT"){
          countGT += 1;
        }
        else if(bi == "GG"){
          countGG += 1;
        }

        bi = ""; //reset bi count to 0 after 1 check
      }
    }
  }

  string myname = "jonle.out.txt";
  ofstream printFile;

  printFile.open(myname, ios::app); //appends probability + 1000 DNA string
  printFile << "Probability of A is " << probCalc(countA, totSum) << "%" << endl;
  printFile << "Probability of C is " << probCalc(countC, totSum) << "%" <<endl;
  printFile << "Probability of T is " << probCalc(countT, totSum) << "%" <<endl;
  printFile << "Probability of G is " << probCalc(countG, totSum) << "%" <<endl;
  printFile << "Probability of AA is " << probCalc(countAA, totSum) << "%" <<endl;
  printFile << "Probability of AC is " << probCalc(countAC, totSum) << "%" <<endl;
  printFile << "Probability of AT is " << probCalc(countAT, totSum) << "%" <<endl;
  printFile << "Probability of AG is " << probCalc(countAG, totSum) << "%" <<endl;
  printFile << "Probability of CA is " << probCalc(countCA, totSum) << "%" <<endl;
  printFile << "Probability of CC is " << probCalc(countCC, totSum) << "%" <<endl;
  printFile << "Probability of CT is " << probCalc(countCT, totSum) << "%" <<endl;
  printFile << "Probability of CG is " << probCalc(countCG, totSum) << "%" <<endl;
  printFile << "Probability of TA is " << probCalc(countTA, totSum) << "%" <<endl;
  printFile << "Probability of TC is " << probCalc(countTC, totSum) << "%" <<endl;
  printFile << "Probability of TT is " << probCalc(countTT, totSum) << "%" <<endl;
  printFile << "Probability of TG is " << probCalc(countTG, totSum) << "%" <<endl;
  printFile << "Probability of GA is " << probCalc(countGA, totSum) << "%" <<endl;
  printFile << "Probability of GC is " << probCalc(countGC, totSum) << "%" <<endl;
  printFile << "Probability of GT is " << probCalc(countGT, totSum) << "%" <<endl;
  printFile << "Probability of GG is " << probCalc(countGG, totSum) << "%" <<endl;
  printFile << "1000 Strings" << endl;

/*Gaussian distribution function DOESN'T WORK*******
  double tsum = 0;
  double totmean = 0;
  double numstring = 0;
  double totvar = 0;
  double stdev = 0;
  stdev = sqrt(totvar);

  for (int i = 0; i < 1000; i++){
    float rand1 = ((float) rand()/RAND_MAX);
    float rand2 = ((float) rand()/RAND_MAX);
    float c = sqrt(-2 * log(rand1)) * cos(2 * M_PI * rand2); //formula
    int strandlength = (stdev * c) + totmean;

    string Newstring = "";
    //check strandlength greater than 0 per line
      if(strandlength >= 1)
      {
        for(int j = 0; j < strandlength; j++)
        {
            float nucleop = ((float) rand()/RAND_MAX);
            if((countT+countG+countA+countC) > nucleop && nucleop > (countG+countA+countC))
            {
                Newstring += "T";
            }
            else if((countG+countA+countC) > nucleop && nucleop > (countA+countC))
            {
                Newstring += "G";
            }
            else if((countA+countC) > nucleop && nucleop > countA)
            {
                Newstring += "C";
            }
            else if(countA > nucleop)
            {
                Newstring += "A";
            }
        }
        printFile<<Newstring<< endl;
    }
    else
    {
        i--;
    }
}
*/
printFile.close();
  }


double sum(double totSum, double strSize){
  return(totSum + strSize);
}

double mean(double totSum, double numstring){
  double val = totSum / numstring;
  return(val);
}

double var(double totmean, double numstring, string textfile){
  ifstream inFile;
  inFile.open(textfile);

  double totSum = 0;
  double totvar = 0;
  string x;
  while(inFile >> x)
  {
    totSum = sum(totSum, pow(x.size() - totmean, 2));

  }
  inFile.close();
  return(totSum / numstring);

}

int main()
{
  bool newlist = true;

while(newlist == true){
  string textfile;
  cout << "Enter File name: ";
  cin >> textfile;

  ifstream inFile;
  inFile.open(textfile);
  while (!inFile)
  {
    cout << "Unable to open file textfile.txt" << endl;
    cout << "Enter new file name: ";
    cin >> textfile;
    inFile.open(textfile);
  }

  string x;
  double totSum = 0;
  double totmean = 0;
  double numstring = 0;
  double totvar = 0;
  double stdev = 0;

  while (inFile >> x)
  {
    numstring++;
    cout << "String length = " << x.size() << endl;
    totSum = sum(totSum,x.size());
    totmean = mean(totSum,numstring);
  }
  totvar = var(totmean, numstring, textfile);
  stdev = sqrt(totvar);
  probforEach(textfile, totSum);

  inFile.close();

  string myname = "jonle.out.txt"; //printing out results to jonle.out.txt
  ofstream printFile;
  printFile.open(myname);
  printFile<< "Jon Le \nStudent ID: 2295116\nAssignment 1\n" << endl;
  printFile<< "Standard Deviation is " << stdev << endl;
  printFile<< "Total variance is " << totvar << endl;
  printFile<< "Total string sum is " << totSum << endl;
  printFile<< "Mean of Strings = " << totmean << endl;
  probforEach(textfile,totSum);
  stdev = sqrt(totvar);
  totvar = var(totmean, numstring, textfile);

  printFile.close();

  string yes;
  cout << "Do you want to enter a new list? Input Y for Yes or N for No" << endl;
  cin >> yes;
    if(yes == "N"){
      newlist = false;
      cout << "Thank you, bye." << endl;
    }
    else if(yes == "Y"){
      newlist = true;
    }
}

return(0);

}
