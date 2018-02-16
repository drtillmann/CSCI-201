#include <iostream>

#include <iomanip>

#include <fstream>

#include <string>

#include "studentList.cpp"

using namespace std;



void printMenu(){

        const int SIZE = 9;

        //Array that stores the menu option strings

        string menu[] = {"1. Load a data file containing information about the students and the scores.", 

                                                 "2. Display the stored data(raw data).", 

                                                 "3. Process the records currently loaded.",

                                                 "4. Print the processed grades to a file.",

                                                 "5. Search for a particular student, specified by name or ID.",

                                                 "6. Add a student to the classlist.",

                                                 "7. Change a students test scores.",

                                                 "8. Save and exit.",

                                                 "0. Exit."};

                                                 

        for(int i=0; i<SIZE;i++){

                        cout << menu[i] << endl;

                }

}



void isEmptyOrStore(studentList& sl, istream& in){

        in.seekg(0, ios::end);

        if(in.tellg() == 0){

                cout << "<********** The file is empty **********>" << endl;

        }else{

        in.seekg(0, ios::beg);

        sl.store(in);

        cout << "File read successfully!" << endl;

        }

}



void processStudent(studentList& sL){

        sL.process();

        cout << "Student grades processed." << endl;

}



void printReport(studentList& sL, ostream& out){

        sL.generateReport(out);

        cout << "Student report generated." << endl;

} 



void add(studentList& sL, istream& in){

        sL.addStudent(in);

}



void modifyTests(studentList& sL){

        int modifyAtIndex = 0;

        float testScore = 0.0;

        string searchItem;

        cout << "Enter an ID to change test scores: ";

        cin >> searchItem;

        modifyAtIndex = sL.searchID(searchItem);

        if(modifyAtIndex != -1){        

                cout << "Enter 4 test scores:";

                for(int i = 0; i < 4; i++){

                        cin >> testScore;

                        (sL.getStudent(modifyAtIndex)).setTestScores(i, testScore);

                }

        }else{

                cout << "Sorry, no ID on record." << endl;

        }

}



int saveStudents(studentList sL){

        int closingVal;

        string outFile;

        ofstream out;

        cout << "Enter a file name to save student data: ";

        cin >> outFile;

        out.open(outFile.c_str());

        if(!out){

                cout << "Could not open file" << endl;

        }

        closingVal = sL.saveStudentData(out);

        out.close();

        return closingVal;

}

/******************************************************************************************************************************************************************/

/********************* Start Main ***********************************/



int main(){

        int selection = 0, searchOption = 0;

        string infile = "", outfile = "", searchItem = "";

        bool goodOption = false;

        ifstream in_file;

        ofstream out_file;

        studentList StudentsList;



        do{

                cout << endl;

                

                //print the menu here

                printMenu();

                

                do{

                        cout << "Enter a menu option here: ";

                        cin >> selection;

                }while((selection < 0) || (selection > 8));

                

                cout << endl;

                switch(selection){

                        case 1:

                        // put code to load data here

                        

                        //input validation

                                do{

                                        cout << "Enter a file name to open: ";

                                        cin >> infile;

                                        in_file.open(infile.c_str());

                                }while(!in_file);

                                

                        //check to see if the file is empty and if it is not, store the data

                                isEmptyOrStore(StudentsList, in_file);

                                break;

                        case 2:

                        // display data here

                                StudentsList.display();

                                break;

                        case 3:

                        // process student grades here

                                processStudent(StudentsList);

                                break;

                        case 4:

                        // generate report here

                        

                        //input validation

                                do{

                                        cout << "Enter a file name to generate Student Report: ";

                                        cin >> outfile;

                                        out_file.open(outfile.c_str(), ios::app);

                                }while(!out_file);

                        //generate student report here

                                printReport(StudentsList, out_file);

                                break;

                        case 5:

                        // search for a record here

                        

                        //input validation

                                do{

                                        cout << "Do you wish to search for a name(1) or ID(2)? Enter a number: ";

                                        cin >> searchOption;

                                }while((searchOption < 1) || (searchOption > 2));

                                

                                if(searchOption == 1){

                                        cout << "You are searching for a Name: ";

                                        cin >> searchItem;

                                        StudentsList.searchName(searchItem);

                                }else if(searchOption == 2){

                                        cout << "You are searching for an ID: ";

                                        cin >> searchItem;

                                        StudentsList.searchID(searchItem);

                                }

                                break;

                        case 6:

                        // add a student here

                                cout << "Enter Student Name, ID, 10 Homework scores, Participation score, 3 Midterm Exam scores, Final Exam score: " << endl;

                                add(StudentsList, cin);

                                break;

                        case 7:

                        // modify student test scores here

                                modifyTests(StudentsList);

                                break;

                        case 8:

                        // save student data to a file here and exit program

                                selection = saveStudents(StudentsList);

                                break;

                        default:

                                cout << "Exiting the program." << endl;

                                break;

                }

                in_file.close();

                in_file.clear();

                out_file.close();

                out_file.clear();

        }while(selection != 0);

        cout << endl;

        return 0;

}
