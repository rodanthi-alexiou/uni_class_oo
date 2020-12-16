#include <iostream>
#include <string>
#include <cstring>
#include "classes1.h"
using namespace std;


int main(int argc, char** argv){
    Student** list_student0;
    list_student0 = new Student*[17];
    list_student0[0] = new Student("Rod",1,1);
    list_student0[1] = new Student("Sof",1,1);
list_student0[2] = new Student("Sof0",0,0);
list_student0[3] = new Student("Chri0",0,0);
list_student0[4] = new Student("Geo0",0,0);
list_student0[5] = new Student("Xen0",0,0);
list_student0[6] = new Student("Maria0",0,0);
list_student0[7] = new Student("Rod0",0,0);
list_student0[8] = new Student("James0",0,0);

Teacher* teacher1 = new Teacher("Anna",0,0);

list_student0[9] = new Student("Nic1",1,0);
list_student0[10] = new Student("Sof1",1,0);
list_student0[11] = new Student("Chri1",1,0);
list_student0[12] = new Student("Geo1",1,0);
list_student0[13] = new Student("Xen1",1,0);
list_student0[14] = new Student("Maria1",2,2);
list_student0[15] = new Student("Rod1",2,1);
list_student0[16] = new Student("James1",1,5);


    School sch(list_student0,17,char_to_int(argv[1]),char_to_int(argv[2]),char_to_int(argv[3]),char_to_int(argv[4]));
    sch.place(teacher1);

    sch.path();
    sch.print_school();

}