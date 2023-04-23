#define _CRT_SECURE_NO_WARNINGS
/*
Using linked list, write a program in C that manipulates a list of air flights
in an airline company as follows. The program starts by offering the user the
following list of options:
1. Please enter 1 to insert a flight.
2. Please enter 2 to delete a flight.
3. Please enter 3 to sort the flights according to their numbers in ascending
order.
4. Please enter 4 to print the information of all flights.
5. Please enter 5 to exit the program.
Notes about the program:
1. The information about each flight is composed of the following
attributes: Source, Destination, and Number.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct flight {
  char source[50];
  char destination[50];
  int number;
  struct flight *next;
};

struct flight *head = NULL;

void insert_flight() {
  struct flight *new_flight =  (struct flight*)malloc(sizeof(struct flight));
  printf("Enter the flight's source: ");
  scanf("%s", new_flight->source);
  printf("Enter the flight's destination: ");
  scanf("%s", new_flight->destination);
  printf("Enter the flight's number: ");
  scanf("%d", &new_flight->number);
  new_flight->next = head;
  head = new_flight;
  printf("Flight inserted successfully.\n\n");
}

void delete_flight() {
  int number;
  printf("Enter the flight number to delete: ");
  scanf("%d", &number);
  struct flight *current = head;
  struct flight *previous = NULL;
  while (current != NULL) {
    if (current->number == number) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      printf("Flight deleted successfully.\n\n");
      return;
    }
    previous = current;
    current = current->next;
  }
  printf("Flight not found.\n\n");
}

void sort_flights() {
  struct flight *current = head;
  struct flight *index = NULL;
  char temp_source[50];
  char temp_dest[50];
  int temp_num;
  if (head == NULL) {
    return;
  } else {
    while (current != NULL) {
      index = current->next;
      while (index != NULL) {
        if (current->number > index->number) {
          strcpy(temp_source, current->source);
          strcpy(current->source, index->source);
          strcpy(index->source, temp_source);
          strcpy(temp_dest, current->destination);
          strcpy(current->destination, index->destination);
          strcpy(index->destination, temp_dest);
          temp_num = current->number;
          current->number = index->number;
          index->number = temp_num;
        }
        index = index->next;
      }
      current = current->next;
    }
  }
  printf("Flights sorted successfully.\n\n");
}

void print_flights() {
  struct flight *current = head;
  if (current == NULL) {
    printf("No flights to print.\n\n");
  } else {
    printf("List of flights:\n");
    while (current != NULL) {
      printf("Flight %d: %s to %s\n", current->number, current->source,
             current->destination);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  int choice;
  while (1) {
    printf("Please choose an option:\n");
    printf("1. Insert a flight\n");
    printf("2. Delete a flight\n");
    printf("3. Sort the flights according to their numbers\n");
    printf("4. Print the information of all flights\n");
    printf("5. Exit the program\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      insert_flight();
      break;
    case 2:
      delete_flight();
      break;
    case 3:
      sort_flights();
      break;
    case 4:
      print_flights();
      break;
    case 5:
      printf("Program is terminated.\n");
      break;
    default:
      printf("Please enter a proper choice.\n");
      break;
    }
  }
}