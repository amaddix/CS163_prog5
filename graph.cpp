//Ashley Maddix
//CS163,  spring 2018, Program 5

// main.cpp
// main - get vertex's, connection, actions
// menu

// graph.cpp
// constructor
// destructor
// insert vertex
// find location
// insert edge
// display vertex's
// display next 

#include "header.h"

// constuctor for the table class- to initialize each data members
table::table()
{
	// create an array of vertex's for SIZE SIZE
	list=new vertex[SIZE];

	// for each index of the vertex array, initialize vertex's data members
	for (int i=0; i<SIZE; ++i)
	{
		list[i].step=NULL;
		list[i].head=NULL;
	}

	list_size=SIZE; //set list_size to SIZE
}

//destructor to deallocate memory for the data members in table class
table::~table()
{
	for (int i=0; i<SIZE; ++i)
	{
		delete [] list[i].step;
		node * current=list[i].head;

		while(current)
		{
			current->adjacent=NULL;
			current=current->next;

			delete list[i].head;
			list[i].head=current;
		}
	}
	list_size=0;
	
}

// function to take a key_value sent in by client program and in list of vertex's
int table::insert_vertex(char * key_value)
{
	int i=0;

//	cout<<list_size<<endl;

	while(i<SIZE && list[i].step)
	{
		++i;
	}

	list[i].step=new char[strlen(key_value)+1];
	strcpy(list[i].step,key_value);
}

// function to take a key value sent in from client program and search through list for a match
int table::find_location(char * key_value)
{
	int i=0;

	while (i<list_size && strcmp(list[i].step, key_value) != 0 )
	{
		++i;
	}	

	return i;
}

// function to take two vertex's sent in from client program, and connect the to each other
int table::insert_edge(char * vertex1, char * vertex2)
{
	int index1=0;
	int index2=0;

	//call the function to find a certain vertex in our array of vertex's
	// passing in vertex one and saving that index in index1
	index1=find_location(vertex1);
	// passing in vertex two and saving that index in index2
	index2=find_location(vertex2);	

//	cout<<index2<<endl;


	// if the returned value for index1 and index2 are withing the array...
	if (index1 < SIZE && index2 < SIZE)
	{ 
		//create a new node temp to add to our list of connections
		node * temp= new node;

		//set temps adjacent to the address at list[index2]
		temp->adjacent=&list[index2];
		//set temps next to the head of list at index1	
		temp->next=list[index1].head;
		//set list[index1]'s head to temp
		list[index1].head=temp;

		//return 1 if we did this	
		return 1;
	}

	// if our returned values from find_location were outside with array size
	//return 0
	return 0;
}

// function to display all the vertex's in list (all index's of list array)
int table::display_vertexs(char * key_value)
{
	int i=0;

	cout<<"***List of all vertex's***"<<endl;
	// while list's index is not NULL and the index size is less then the size of array
	while(list[i].step && i< list_size)
	{
		// output the vertex
		cout<<" * "<<list[i].step<<endl;
		++i;
	}
}
// functin to take a key_value added by user and display all vertex's connected to it
int table::display_next ( char * key_value)
{
	int index=0;
	//call function to find which index the key value's at, save in index var
	index=find_location(key_value);

	// create a node = to list[index]'s head	
	node * current=list[index].head;

	//while out list[index]'s nodes are not NULL	
	while (current)
	{
		//output its connection's step name, and traverse
		cout<<" * "<<current->adjacent->step<<endl;
		current=current->next;
	}
}

/*
int table::display_depth(char * key_value)
{
	int index=0;
	int i=0;
	int worked=0;
	index=find_location(key_value);

	do
	{

		node * current=list[i].head;	

		if (depth_rec(array, index))	
		{
		










		worked+=depth_rec(list[key_value].head, array, index)
		++i;
	
		if (i==list_size)
			i=0;
	}while (worked != list_size-1);	
		
	
	
}
	
int tabe::depth_rec( node * head, node * array, int index)
{
	int count=0;
	if (!head)
		return 0;


	
	if (array[index]==SIZE-1)
		return 0;

	if(strcmp(array[index].step, 
	head=head->next;
} */
