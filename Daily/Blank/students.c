/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   students.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurched <kmurched@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 08:24:59 by kmurched          #+#    #+#             */
/*   Updated: 2026/02/26 10:55:24 by kmurched         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char name[50];
	int age;
	float gpa;
	struct Student *next;
}Student;

struct Student* createStudent(char *name, int age, float gpa)
{
	
};/* Allocates memeory for a new student node, inistialises it's fields and sets "next" NULL
Returns pointer to a node.*/

void addStudent(struct Student** head, char *name, int age, float gpa){

	/* Adds new student to the end of the linked list.
		If the list is empty (*head --> NULL), sets the ehad to the new node
	*/
}

void printStudents(struct Student* head){
	
	/*	Traverses the list and prints each student's details in the format: 
		"Name: [name], Age: [age], GPA: [gpa]\n"
	*/
}

void freelist(struct Student* head){
	/*	Frees all allocated memory in the list to prevent memeory leaks. 
	*/
}


int main(){

// Intialise an empty list (head pointer set to NULL)

// Add at least 3 students using hardcoded values (via functions)

// Print the list

// Free the list before exiting. 


// Handles potential edge cases gracefully. Checking if malloc returns nULL (return error)

	return 0;
}