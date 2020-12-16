#include <iostream>
#include <string>
#include <cstring>
#include "classes.h"

using namespace std;



int main(int argc, char** argv) {       //argv[1] = K

int K = char_to_int(argv[1]);
int L = char_to_int(argv[2]);
int Tquiet = char_to_int(argv[3]);
int Tmessy = char_to_int(argv[4]);





Student* list_student0[8];
Student* list_student1[8];
Student* p1 = new Student("Nic0",0,male);
Student* p2 = new Student("Sof0",0,female);
Student* p3 = new Student("Chri0",0,female);
Student* p4 = new Student("Geo0",0,male);
Student* p5 = new Student("Xen0",0,male);
Student* p6 = new Student("Maria0",0,female);
Student* p7 = new Student("Rod0",0,female);
Student* p8 = new Student("James0",0,male);


Student* p9 = new Student("Nic1",1,male);
Student* p10 = new Student("Sof1",1,female);
Student* p11 = new Student("Chri1",1,female);
Student* p12 = new Student("Geo1",1,male);
Student* p13 = new Student("Xen1",1,male);
Student* p14 = new Student("Maria1",0,female);
Student* p15 = new Student("Rod1",0,female);
Student* p16 = new Student("James1",0,male);


// Class 0
list_student0[0] = p1;
list_student0[1] = p2;
list_student0[2] = p3;
list_student0[3] = p4;
list_student0[4] = p5;
list_student0[5] = p6;
list_student0[6] = p7;
list_student0[7] = p8;

//Class 1
list_student1[0] = p9;
list_student1[1] = p10;
list_student1[2] = p11;
list_student1[3] = p12;
list_student1[4] = p13;
list_student1[5] = p14;
list_student1[6] = p15;
list_student1[7] = p16;

School sch(K,1,4);
sch.insert_students(list_student0,0,8);
sch.insert_students(list_student1,1,8);

sch.print_classroom_duos();


Student* test[3]; // students of class 0
test[0] = p1;
test[1] = p2;
//test[2] = p3;
//test[3] = p4;
test[2] = p5;
test[3] = p6;

sch.switch_students(test,4,0);

//sch.switch_students(p2);
//sch.switch_students(p3);
//sch.switch_students(p5);
//Classroom rooms(list_student,5);

//rooms.list_size();
 
return 0;
}