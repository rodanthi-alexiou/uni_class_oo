#include <iostream>
#include <string>
#include <cstring>

using namespace std;


#define male 0
#define female 1

int char_to_int(const char* s);

class Student{
private:
    char* name;
    int classroom;
    int gender;
public:
    Student(const char*, int, int);
    Student(const Student&);
    ~Student(){ cout << "Destroying a Student!" << endl;}

    char* get_name(){return name;};
    
    int return_gender(){return gender;}
    int return_classroom(){return classroom;}
};


struct Point {
private:
    Student* x;
    Student* y;
public:   
    Point(Student* one, Student* two){        
        x = one;
        y= two;
        if(y!=NULL)
       cout << "Point creation of Students: " << x->get_name() << " and  " << y->get_name()<< endl;
       else
           cout << "Last Point with Student: " << x->get_name() << endl;}
    ~Point(){       
        cout << "~Point DESTORY" << endl;}

    void print() const{
        if(y!=NULL)
        cout<< "TOGETHER: " << x->get_name() << " AND " << y->get_name() << endl;
        else{
            cout << "ALONE: " << x->get_name() << endl;
        }
    }

    bool student_is_male(Student* s) const{
        if(s->return_gender() == 0) return true;
        else
            return false; 
    }
    
    Student* return_male() const{
        if(x->return_gender() == 0) return x;
        else if(y!=NULL) return y;
        else return NULL;
    }
    Student* return_female() const{
        if(x->return_gender() == 1) return x;
        else if(y!=NULL) return y;
        else return NULL;
    }
    void change_male(Student& s1) const{
        if(x->return_gender() ==0) *x = s1;
        else *y=s1;
    }
    void change_female(Student& s2) const{
        if(x->return_gender() ==1) *x = s2;
        else *y=s2;
    }
};


struct Node {
    const Point data;
    Node* next;

    Node(const Point& p, Node* n = NULL) : data(p), next(n) {
        cout << "New Node!" << endl;   }

};

class List {
private:
    Node *start;
    unsigned int size_;
public:   
    List() : start(NULL), size_(0) {
        cout << "List creation" << endl;   }

    ~List() {
        Node* t1 = start;
        while (t1 != NULL) {
            Node* t2 = t1;       
            t1 = t1->next;
            delete t2;   }   
        cout << "List destruction" << endl;}


    unsigned int size() const { 
        return size_; }

    void pushFront(const Point& p) {
        start = new Node(p, start);
        size_++;   }
    
    bool pop(unsigned int index) {
        if (index >= size_) 
            return false;
        Node* t = start;
        if (index == 0) {
            start = start->next;
            delete t;   } 
        else {
            while (--index > 0) t = t->next;
            Node* t2 = t->next;      
            t->next = t->next->next;
            delete t2;   }
        size_--;
        return true;}

    Node* return_node(int index){
        if (index >= size_) 
            return NULL;
        Node* t = start;
        if (index == 0) {
            return t;   
        } 
        else {
            while (index-- > 0) t = t->next;
    
            return t;
        }

    }
        void print() const {
        int ind = 0;
        Node* t = start;
        while (t != NULL) {
            t->data.print();    
            cout << "In Seat: " << ind << endl;
            t = t->next;   
            ind++;}
    }

    int node_index(Student* s){
    
        int ind=0;
        Node* t1 = start;
        while(t1->data.return_female() != s && t1->data.return_male() != s) {
            Node* t2 = t1;       
            t1 = t1->next;
            ind+=1;
        }
        return ind;
    }


};

class Classroom{
private:
    List students;
    int T;
public:
    Classroom(Student** s_list, int students_number);
    ~Classroom(){ cout << "CLASSROOM DESTROYED!!" << endl;}


    int duos_size(){return students.size();} //arithmos zeugarion
    void print_duos(){students.print();}
    List* return_list(){return &students;}
    void change_T(int i);
    int return_T() const{return T;}
};


class School{
private:
    Classroom** rooms;
    int classrooms_numb;
    int Tq;
    int Tm;
public:
    School(int number_classrooms, int T_quiet, int T_messy): classrooms_numb(number_classrooms), Tq(T_quiet), Tm(T_messy){
        rooms = new Classroom*[number_classrooms];
    }
    ~School(){ cout << "School destroyed!! " << endl;}

    void insert_students(Student** student_list, int classroom_number, int students_classroom){
        rooms[classroom_number] = new Classroom(student_list, students_classroom);
    }

    void switch_individual(Student* s, int current_room, int switch_room);
    void switch_students(Student** s, int number_students, int number_class);
    void print_classroom_duos();


};