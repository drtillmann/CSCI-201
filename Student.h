// specification file for Student class

#include <fstream>

#include <iomanip>

#include <iostream>

#include <cstring>

#ifndef STUDENT

#define STUDENT

using namespace std;



class Student{

                private:

                // constants for Score Array Sizes

                        const static int HW_SIZE = 10, TEST_SIZE = 4;

                // constants for calculating weighted scores    

                        const static float WTHW = 0.05, WTMIDTERMS = 0.1, WTFINAL = 0.2;

                        

                        string name;

                        string ID;

                        float hwScores[HW_SIZE];

                        float participation;

                        float testScores[TEST_SIZE];

                        float totalScore;

                        float aggHW;

                        float aggTest;

                        char lGrade;

                

                

                public:

                        Student(){

                                name = " ";

                                ID = " ";

                                participation = 0.0;

                                totalScore = 0.0;

                                aggHW = 0.0;

                                aggTest = 0.0;

                                lGrade = ' ';

                        }

                        

                //setters

                        void setName(string n){

                                name = n;

                        }

                        

                        void setID(istream& in){

                                in >> ID;

                        }

                        

                        void setHWScores(int i, float hws){

                                hwScores[i] = hws;

                        }

                        

                        void setParticipation(istream& in){

                                in >> participation;

                        }

                        

                        void setTestScores(int i, float ts){

                                testScores[i] = ts;

                        }

                        

                        void setAggHW();

                        

                        void setAggTest();

                        

                        void setLetterGrade();

                        

                //modifiers

                        int getHWSize(){

                                return HW_SIZE;

                        }

                        

                        int getTSize(){

                                return TEST_SIZE;

                        }

                        

                        string getName()const{

                                return name;

                        }

                        

                        string getID()const{

                                return ID;

                        }

                        

                        float getHW(int i)const{

                                return hwScores[i];

                        }

                        

                        float getParticipation()const{

                                return participation;

                        }

                        

                        float getTestScores(int i)const{

                                return testScores[i];

                        }

                        

                        float getAggHW()const{

                                return aggHW;

                        }

                        

                        float getAggTest()const{

                                return aggTest;

                        }

        

                        void display();

                        

                        void report(std::ostream& out);

                        

                        void save(std::ostream& out);

                        

                        

};

#endif>
