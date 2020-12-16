#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define yard_location 0
#define stairs_location 1
#define corridor_location 2
#define classroom_location 3

int char_to_int(const char*);


class Teacher{
private:
    char* name;
    int floor_number;
    int class_number;
public:
    Teacher(const char*, int,int);
    ~Teacher(){ cout << "Destoying Teacher" << endl;}

    char* get_name(){ return name;}
    int get_floor_numb(){return floor_number;}
    int get_classroom_numb(){return class_number;}

};

class Student {
private:
        char* name;
        int floor_number;  // 0, 1, 2
        int class_number;  // 0, 1, 2, 3, 4, 5
        int location;
public:
    Student(const char*, int, int);
    ~Student(){ cout << "Destroying a Student!" << endl;}

    int get_floor_numb(){return floor_number;}
    int get_classroom_numb(){return class_number;}
    char* get_name() const{return name;}
    void set_location(int i){location=i;}
};

class Schoolyard{
private:
    Student** yard_array;
    int capacity;
    int index;  //σε ποιά θέση βρίσκεται το τελευταίο στοιχείο του array
 
public:
    Schoolyard(){ cout << "YARD created"<< endl;
    index=0;}
    ~Schoolyard(){ cout << "YARD destroyed"<< endl;}

    void set_capacity(int i);
    void enter_yard(Student* s_element);
    Student* exit_yard();
    bool size_yard();
    bool yard_enough_space();
    void get_student_name();

};

class Stairs{
private:
    Student** stairs_array;
    int capacity;
    int index;
public:
    Stairs(){ cout << "Stairs created"<< endl;
    index=0;}
    ~Stairs(){ cout << "Stairs destroyed"<< endl;}

    void set_capacity(int i);
    void enter_stairs(Student* s);
    Student* exit_stairs();
    bool stairs_enough_space();
    void get_student_name();

};

class Classroom{
private:
    Student** classroom_array;
    Teacher* teacher;
    int capacity;
    int index;
public:
    Classroom(){ 
        teacher = NULL;
        cout << "Classroom created"<< endl; index=0;}
    ~Classroom(){ cout << "Classroom destroyed"<< endl;}

    void set_capacity(int i);
    void enter_classroom(Student* s);
    Student* exit_classroom();
    void teacher_enters(Teacher* t);
    bool teacher_in_class();
    bool classroom_enough_space();
    void get_student_name();

};


class Floor{
private:
    Student** corridor_array;
    Classroom room[6];   // 0,1,2,3,4,5
    int capacity;
    int index;
public:
    Floor(){ cout << "Floor created"<< endl;index =0;}
    ~Floor(){ cout << "Floor destroyed"<< endl;}
    
    void set_capacity(int i);
    void enter_floor_corridor(Student* s);
    Student* exit_corridor();
    Classroom& class_return(int class_number);
    bool corridor_enough_space();
    void get_student_name();
};


class School{
private:
    Schoolyard yard;
    Stairs stairs;
    Floor floor[3]; //0,1,2
public:
    School(Student** student_list, int student_number, int c_yard, int c_stairs, int c_floor, int c_rooms);
    
    // enas enas mathitis (while) mexri na ftasei oso pio makria mporei

    //1) elegxv an yparxei xvrow sto EPOMENO dvmatio
    //2) pairnoume ton teleytaio mathiti apo to array toy xvroy poy eimaste
    //3) enter_(*EPOMENO_room*)
    void path();
    void print_school();
    void place(Teacher* t);
};