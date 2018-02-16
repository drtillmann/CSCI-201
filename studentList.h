#include <fstream>

#include <iomanip>

#include <iostream>

#include <string>

#include <vector>

#include "Student.cpp"

#ifndef STUDENTLIST

#define STUDENTLIST

using namespace std;



class studentList{

        private:

                // use vector

                vector<Student> StudentsVector;





        public:

                studentList();//constructor



                void store(istream&);

        

                void display();

                

                void process();

                

                void generateReport(ostream&);

                

                int searchName(string);

                

                int searchID(string);

                

                void addStudent(istream&);

                

                Student& getStudent(int);

                

                int saveStudentData(ostream&);

};

#endif>
