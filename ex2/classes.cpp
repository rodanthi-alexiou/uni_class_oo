#include <iostream>
#include <string>
#include <cstring>
#include "classes.h"

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


Student::Student(const char* nam, int f, int g): classroom(f), gender(g){
   name = new char[strlen(nam)+1];
   strcpy(name,nam);
   cout << "I just constructed a student " << endl;
}

Student::Student(const Student& s)
{
   name = new char[strlen(s.name)+1];
   strcpy(name,s.name);
   classroom = s.classroom;
   gender = s.gender;
   cout << "I just created a student by copying ... " << endl;
}


Classroom::Classroom(Student** s_list, int students_number) {
    T=0;
        for(int i=0; i<students_number; i++){
            if(i < students_number-1){
                Point new_point(s_list[i],s_list[i++]);
                students.pushFront(new_point);
            }
            else{
                Point last_point(s_list[i],NULL);
                students.pushFront(last_point);
            }
        }
    }

void Classroom::change_T(int i){
    T += i;
}



void School::switch_individual(Student* s, int current_room, int switch_room){
        int node_index = rooms[current_room]->return_list()->node_index(s);
        int change_node = node_index;


        if(current_room == switch_room){
        if(node_index == rooms[current_room]->return_list()->size()-1) change_node-=1;
        else change_node+=1;
        }
        else{
            change_node = change_node% rooms[switch_room]->return_list()->size(); //το καινούριο index της άλλης τάξης [0,list_size]
            if(change_node == rooms[switch_room]->return_list()->size()) change_node-=1; //για να έχει σίγουρα ένα αγόρι/κορίτσι το ζευγάρι
        }
        
        if(rooms[current_room]->return_list()->return_node(node_index)->data.student_is_male(s)){ //αν ο μαθητής για αλλαγή είναι αγόρι
            Student* to_change = new Student(*rooms[switch_room]->return_list()->return_node(change_node)->data.return_male());
            rooms[switch_room]->return_list()->return_node(change_node)->data.change_male(*s);
            rooms[current_room]->return_list()->return_node(node_index)->data.change_male(*to_change);
        }
        else{  // αν η μαθήτρια για αλλαγή είναι κορίτσι
            Student* to_change = new Student(*rooms[switch_room]->return_list()->return_node(change_node)->data.return_female()); 
            rooms[switch_room]->return_list()->return_node(change_node)->data.change_female(*s);
            rooms[current_room]->return_list()->return_node(node_index)->data.change_female(*to_change);
        }
    }

void School::switch_students(Student** s, int number_students, int number_class){
      
       int temp=0;
        int sort[rooms[number_class]->return_list()->size()];
        int duos=0;
        for(int i=0; i<rooms[number_class]->return_list()->size(); i++){
            sort[i]=0;
        }
        for(int j=0; j<number_students; j++){
            sort[rooms[number_class]->return_list()->node_index(s[j])]+=1;
            if(sort[rooms[number_class]->return_list()->node_index(s[j])] ==2) duos+=1;
        }
 

    if(duos<=2){
        for(int a=0; a<number_students; a++) {
            switch_individual(s[a],number_class,number_class);
            rooms[number_class]->change_T(1);
        }
    }
    else{
        // ελέγχω αν τα ζευγάρια είναι διαδοχικά
        int k=0;
        while(sort[k]==0){
            k++;
        }
        while(duos>0){
            if(sort[k]!=2){
                temp=1;         // τα ζευγάρια δεν ειναι διαδοχικά temp=1
                break;
            }
            else duos--;
            k++;
        }

        //τέλος ελέγχου αν temp=1 διαδοχικά αν temp=0 όχι διαδοχικά


        if(classrooms_numb == 1){
            temp = 0;
            cout << "There are no other classrooms. Students cannot be switched" << endl;
        }
else{

        if(temp==1){    // αν ΔΕΝ είναι διαδοχικά
            for(int i=0; i<number_students; i++){
                if(number_class+1 != classrooms_numb) {
                    switch_individual(s[i],number_class,number_class+1);
                    rooms[number_class]->change_T(2);}
                else cout << "This is the last classroom. The students cannot be switched with the next classroom" << endl;
            }
        }
        else{   // αν είναι διαδοχικά
            for(int i=0; i<number_students; i++){
                number_class= i%classrooms_numb;
                switch_individual(s[i],number_class,number_class);
                rooms[number_class]->change_T(2);
        }
        }
    }
}
    }


void School::print_classroom_duos(){
        for(int i=0; i<classrooms_numb; i++){
        cout << "IN CLASSROOM " << i << endl;
        rooms[i]->print_duos();
        if(rooms[i]->return_T()<Tq) cout << "What a quiet class!" << endl;
        else if(rooms[i]->return_T()>Tm) cout << "What a mess!" << endl;
        else cout << "Please be quiet!" << endl;

    }
}