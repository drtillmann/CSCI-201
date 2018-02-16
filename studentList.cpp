//compile with gcc -c studentList.cpp

#include <cstdlib>

#include <iostream>

#include <iomanip>

#include <fstream>

#include <string>

#include "studentList.h"

using namespace std;



studentList::studentList(){// constructor

        

}



void studentList::store(std::istream& in){

        int hwCounter = 0, testCounter = 0;

        float tempHW = 0.0, tempTest = 0.0;

        Student tempStudent;

        string garbage, name;

        

                while((in >> name) || (!in.eof())){

                        tempStudent.setName(name);

                        tempStudent.setID(in);

                        while(hwCounter < tempStudent.getHWSize()){

                                in >> tempHW;

                //pass the index and homework score to store inside Student object

                                tempStudent.setHWScores(hwCounter, tempHW);

                                hwCounter++;

                        }

                        tempStudent.setParticipation(in);

                        while(testCounter < tempStudent.getTSize()){

                                in >> tempTest;

                //pass the index and test score to store inside Student object

                                tempStudent.setTestScores(testCounter, tempTest);

                                testCounter++;

                        }

                        getline(in, garbage);

                //add student to list

                        StudentsVector.push_back(tempStudent);

                        hwCounter = 0;

                        testCounter = 0;

                        

                }

}



void studentList::display(){

        int i = 0;

        while(i < StudentsVector.size()){

                StudentsVector.at(i).display();

                cout << endl;   

                i++;

        }

}



void studentList::process(){

        int i = 0;

        while(i < StudentsVector.size()){

                StudentsVector.at(i).setAggHW();

                StudentsVector.at(i).setAggTest();

                StudentsVector.at(i).setLetterGrade();

                i++;

        }

}



void studentList::generateReport(std::ostream& out){

        int i = 0;

        char star = '*';

        while(i < StudentsVector.size()){

                StudentsVector.at(i).report(out);

                i++;

        }

        for(int i = 1; i < 51; i++){

                out << star;

        }

        out << " END OF STUDENT REPORT ";

        for(int i = 1; i < 51; i++){

                out << star;

        }

        out << endl << endl;

}



int studentList::searchName(string item){

        bool found = false;

        int i = 0;

        while(i < StudentsVector.size()){

                        if(item.compare(StudentsVector.at(i).getName()) == 0){

                                cout << "Student Found!" << endl << endl;

                                StudentsVector.at(i).display();

                                found = true;

                                return i;

                        }

                i++;

        }

        if(!found){

                cout << "***** Student Not Found *****" << endl;

                return -1;

        }

}



int studentList::searchID(string item){

        bool found = false;

        int i = 0;

        while(i < StudentsVector.size()){

                        if(item.compare(StudentsVector.at(i).getID()) == 0){

                                cout << "Student Found!" << endl << endl;

                                StudentsVector.at(i).display();

                                found = true;

                                return i;

                        }

                i++;

        }

        if(!found){

                cout << "***** Student Not Found *****" << endl;

                return -1;

        }

}



void studentList::addStudent(std::istream& in){

        string name;

        Student tempStudent;

        float tempHW = 0.0;

        in >> name;

        tempStudent.setName(name);

        tempStudent.setID(in);//good to here

        

        for(int i = 0; i < tempStudent.getHWSize(); i++){

                in >> tempHW;

                tempStudent.setHWScores(i, tempHW);

        }

        tempStudent.setParticipation(in);

        for(int i = 0; i < tempStudent.getTSize(); i++){

                float tempTest;

                in >> tempTest;

                tempStudent.setTestScores(i, tempTest);

        }

        StudentsVector.push_back(tempStudent);

}



Student& studentList::getStudent(int index){

        return StudentsVector.at(index);

}



int studentList::saveStudentData(ostream& out){

        for(int i=0; i < StudentsVector.size(); i++){

                StudentsVector.at(i).save(out);

        }

        return 0;

}> 
