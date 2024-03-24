#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define DATABASE_SIZE 100 

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
} Person;

Person database[DATABASE_SIZE];
int next_id = 0;

// adds a person and their info to the data base
void add_person(const char* name, int age) {
    if (next_id < DATABASE_SIZE) {
        database[next_id].id = next_id;
        strncpy(database[next_id].name, name, MAX_NAME_LEN);
        database[next_id].age = age;
        next_id++;
    }
}

// finds specific person
Person* find_person(int id) {
    for (int i = 0; i < DATABASE_SIZE; i++) {
        if (database[i].id == id) {
            return &database[i];
        }
    }
    return NULL;
}

// updates person
void update_person(int id, const char* name, int age) {
    Person* person = find_person(id);
    if (person != NULL) {
        strncpy(person->name, name, MAX_NAME_LEN);
        person->age = age;
    }
}

// removes the person from the data base and their information
void delete_person(int id) {
    Person* person = find_person(id);
    if (person != NULL) {
        person->id = -1; 
    }
}

// testing the db
int main() {
    printf("This is my database program\n");

    printf("Adding persons to the database...\n");
    add_person("Alice", 30);
    add_person("Bob", 25);

    printf("Finding a person with ID 0\n");
    Person* person = find_person(0);
    if (person != NULL) {
        printf("Found person: %s, Age: %d\n", person->name, person->age);
    } else {
        printf("Person not found.\n");
    }

    printf("Updating person with ID 1\n");
    update_person(1, "Bobby", 26);

    printf("Deleting person with ID 0\n");
    delete_person(0);

    return 0; // success!
}