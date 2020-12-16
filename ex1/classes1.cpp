#include <iostream>
#include <string>
#include <cstring>
#include "classes1.h"
using namespace std;

int char_to_int(const char* s){
    cout << s << endl;
    int num=0;
    while(*s){
        num=((*s)-'0') + num*10;
        s++;
    }
return num;
}

Student::Student(const char* nam, int f, int c):floor_number(f), class_number(c){
   name = new char[strlen(nam)+1];
   strcpy(name,nam);
   cout << "I just constructed a student " << endl;
}

Teacher::Teacher(const char* nam, int f, int c):floor_number(f), class_number(c){
   name = new char[strlen(nam)+1];
   strcpy(name,nam);
   cout << "I just constructed a teacher " << endl;
}


//SCHOOLYARD

void Schoolyard::set_capacity(int i){
        yard_array = new Student*[i];   // αρχικοποιώ το Student**
        capacity=i;
    }
    
void Schoolyard::enter_yard(Student* s_element){
            yard_array[index] = s_element;
            cout << yard_array[index]->get_name() << " enters the Schoolyard!" << endl;
            s_element->set_location(0);
            index++;
        
    }
Student* Schoolyard::exit_yard(){
        cout << yard_array[--index]->get_name() << " exits the Schoolyard!" << endl;
        return yard_array[index];
    }

bool Schoolyard::size_yard(){
        if(index == 0){
            return false;
        }
    }

bool Schoolyard::yard_enough_space(){
        if(index==capacity){
            return false;
        }
        else{
            return true;
        }
    }

void Schoolyard::get_student_name(){
        cout << "Schoolyard has ";
        for(int i=0; i<index;i++){
            cout << yard_array[i]->get_name() << ", ";
        }
        if(index==0) cout << " no students" << endl;
        else cout << endl;
    }


// STAIRS

void Stairs::set_capacity(int i){
        stairs_array = new Student*[i];
        capacity=i;
    }
    
void Stairs::enter_stairs(Student* s){
            stairs_array[index] = s;
            cout << stairs_array[index]->get_name() << " enters Stairs!" << endl;
            s->set_location(1);
            index++;}


Student* Stairs::exit_stairs(){
        cout << stairs_array[--index]->get_name() << " exits Stairs!" << endl;
        return stairs_array[index];}

bool Stairs::stairs_enough_space(){
        if(index==capacity){
            return false;
        }
        else{
            return true;
        }
    }

void Stairs::get_student_name(){
        cout << "Stairs has ";
        for(int i=0; i<index;i++){
            cout << stairs_array[i]->get_name() << ", ";
        }
        if(index==0) cout << " no students" << endl;
        else cout << endl;
    }


// CLASSROOM


void Classroom::set_capacity(int i){
        classroom_array = new Student*[i];
        capacity=i;
    }
    
void Classroom::enter_classroom(Student* s){
            classroom_array[index] = s;
            cout << classroom_array[index]->get_name() << " enters Classroom!" << endl;
            s->set_location(3);
            index++;
        
    }
Student* Classroom::exit_classroom(){
        cout << classroom_array[--index]->get_name() << " exits Classroom!" << endl;
        return classroom_array[index];
    }

void Classroom::teacher_enters(Teacher* t){
        teacher = t;
    }

bool Classroom::teacher_in_class(){
        if(teacher != NULL) return true;
        else false;
    }

bool Classroom::classroom_enough_space(){
        if(index==capacity){
            return false;
        }
        else{
            return true;
        }
    }

void Classroom::get_student_name(){
        for(int i=0; i<index;i++){
            cout << classroom_array[i]->get_name() << ", ";
        }
        if(index==0) cout << " no students" << endl;
        else cout << endl;
    }



// FLOOR

void Floor::set_capacity(int i){
        corridor_array = new Student*[i];
        capacity=i;
    }

void Floor::enter_floor_corridor(Student* s){

            corridor_array[index] = s;
            cout << corridor_array[index]->get_name() << " enters Corridor!" << endl;
            s->set_location(2);
            index++;
    }

Student* Floor::exit_corridor(){
        cout << corridor_array[--index]->get_name() << " exits Corridor!" << endl;
        return corridor_array[index];
    }

Classroom& Floor::class_return(int class_number){
        return room[class_number];
    }

bool Floor::corridor_enough_space(){
        if(index==capacity){
            return false;
        }
        else{
            return true;
        }
    }
    
void Floor::get_student_name(){
        for(int i=0; i<index;i++){
            cout << corridor_array[i]->get_name() << ", ";
        }
        if(index==0) cout << " no students" << endl;
    }



// SCHOOL

School::School(Student** student_list, int student_number, int c_yard, int c_stairs, int c_floor, int c_rooms){ 

        // capacity kathe xvrou
        yard.set_capacity(c_yard);
        stairs.set_capacity(c_stairs);
        for(int i=0; i<3; i++){
        floor[i].set_capacity(c_floor);
        for(int j=0; j<6; j++) floor[i].class_return(j).set_capacity(c_rooms);
        }

        for(int i=0; i<student_number; i++){
           if(yard.yard_enough_space())
            yard.enter_yard(student_list[i]);
        }
        }
    
    // enas enas mathitis (while) mexri na ftasei oso pio makria mporei

    //1) elegxv an yparxei xvrow sto EPOMENO dvmatio
    //2) pairnoume ton teleytaio mathiti apo to array toy xvroy poy eimaste
    //3) enter_(*EPOMENO_room*)


void School::path(){
        while(yard.size_yard()!= false && stairs.stairs_enough_space()!= false){    //efoson uparxoun mathites sto yard KAI uparxei eletheros xvros sto stairs
            if(stairs.stairs_enough_space()){           //stairs
                Student* temp = yard.exit_yard();     
                stairs.enter_stairs(temp);             
                if(floor[temp->get_floor_numb()].corridor_enough_space()){  //corridor
                    temp = stairs.exit_stairs();
                    floor[temp->get_floor_numb()].enter_floor_corridor(temp);
                    if(floor[temp->get_floor_numb()].class_return(temp->get_classroom_numb()).classroom_enough_space()
                    && !floor[temp->get_floor_numb()].class_return(temp->get_classroom_numb()).teacher_in_class()){  //classroom
                        temp = floor[temp->get_floor_numb()].exit_corridor();
                        floor[temp->get_floor_numb()].class_return(temp->get_classroom_numb()).enter_classroom(temp);
                    }
            } 
            }
        }
    }


void School::print_school(){
        cout << "School life consists of: " << endl;
        yard.get_student_name();
        stairs.get_student_name();
        for(int i=0; i<3; i++){
            cout << "Floor-Corridor " << i << " has ";
            floor[i].get_student_name();
            for(int j=0; j<6; j++){
                cout << "Classroom " << j << " has ";
                floor[i].class_return(j).get_student_name();
            }
        }
    }

void School::place(Teacher* t){
    floor[t->get_floor_numb()].class_return(t->get_classroom_numb()).teacher_enters(t);
}