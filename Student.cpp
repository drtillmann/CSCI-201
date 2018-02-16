//compile with gcc -c Student.cpp



#include "Student.h"

#include <fstream>

#include <iomanip>

#include <iostream>

#include <cstdlib>

using namespace std;



                        void Student::setAggHW(){

                                bool badGrade = false;

                                float min = hwScores[0], totalHwScore = 0.0;

                                for(int i=0; i < HW_SIZE; i++){

                                        if((hwScores[i] < 0) || (hwScores[i] > 100)){

                                                badGrade = true;

                                        }

                                        if(hwScores[i] < min){

                                                min = hwScores[i];

                                        }

                                        totalHwScore += hwScores[i];

                                }

                                if((participation < 0) || (participation > 100)){

                                        badGrade = true;

                                }

                                if(badGrade){

                                        aggHW = -1;

                                }else{

                                        aggHW = ((totalHwScore - min) + participation) * WTHW;

                                        totalScore += totalHwScore - min;

                                }       

                        }



                        void Student::setAggTest(){

                                bool badGrade = false;

                                float totalMidSum = 0.0, finalExam = 0.0;

                        // add up the three midterm exams

                                for(int i = 0; i < TEST_SIZE - 1; i++){

                                        if((testScores[i] >= 0) && (testScores[i] <= 100)){

                                                totalMidSum += testScores[i];

                                        }else{

                                                badGrade = true;

                                        }

                                }

                                if((testScores[3] >= 0) && (testScores[3] <= 100)){

                                        finalExam = testScores[3];

                                }else{

                                        badGrade = true;

                                }

                                if(badGrade){

                                        aggTest = -1;

                                }else{

                                        aggTest = ((totalMidSum * WTMIDTERMS) + (finalExam * WTFINAL));

                                        totalScore += (totalMidSum + finalExam);

                                }

                        }

                        

                        void Student::setLetterGrade(){

                                totalScore = totalScore / 14;

                                const int A=90, B=80, C=70, D=60;

                                if((aggHW == -1) || (aggTest == -1)){

                                        totalScore = -1;

                                }

                                if(totalScore == -1){

                                        lGrade = 'Z';

                                }else{

                                        if(totalScore < C){

                                                if(totalScore < D){

                                                        lGrade = 'F';

                                                }else{

                                                        lGrade = 'D';

                                                }

                                        }else{

                                                if(totalScore < B){

                                                        lGrade = 'C';

                                                }else{

                                                        if(totalScore < A){

                                                                lGrade = 'B';

                                                        }else{

                                                                lGrade = 'A';

                                                        }

                                                }

                                        }

                                }

                        }



                        void Student::display(){

                                string space = " ";

                                cout << name << space << ID << space;

                                for(int i=0; i < HW_SIZE; i++){

                                        cout << hwScores[i] << space;

                                }

                                cout << participation << space;

                                for(int j=0; j < TEST_SIZE; j++){

                                        cout << testScores[j] << space;

                                }

                                cout << aggHW << space << aggTest << space << lGrade;

                                cout << endl;

                        }

                        

                        void Student::report(ostream& out){

                                string space = " "; 

                                out << left << setw(20) << name;

                                out << right << setw(10) << ID << setw(4); 

                                for(int i=0; i < HW_SIZE; i++){

                                        out << setw(4) << hwScores[i] << space;

                                }

                                out << setw(4) << participation << space;

                                for(int j=0; j < TEST_SIZE; j++){

                                        out << setw(4) << testScores[j] << space;

                                }

                                out << setw(6) << aggHW << setw(6) << aggTest << setw(6) << lGrade << endl;

                        }

                        

                        void Student::save(ostream& out){

                                string space = " ";

                                out << name << space << ID << space;

                                for(int i=0; i < HW_SIZE; i++){

                                        out << hwScores[i] << space;

                                }

                                out << participation << space;

                                for(int j=0; j < TEST_SIZE; j++){

                                        out << testScores[j] << space;

                                }

                                //cout << aggHW << space << aggTest << space << lGrade;

                                out << endl;

                        }> 
