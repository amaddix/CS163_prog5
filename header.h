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

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//const int for the amount of vertex's
const int SIZE=5;

/*
struct path
{
	char * step;
};
*/

//struct for the vertex's, each vertex has a step and and node pointer to
// a list of connections (edges)
struct vertex
{
	char * step;
	struct node * head;
};

//struct for the connection (edges), each edge has a pointer to a vertex and a pointer to 
// another node
struct node
{
	vertex * adjacent;
	node * next;
};

//class to implement the graph data type 
class table
{
	public:
		table(); // constructor to implement the data members of class
		~table(); // destructor to deallocate memory for data members of class
		int insert_vertex(char * key_value);
		// function to take a key_value sent in by client program and in list of
		//vertex's
		int find_location(char * key_value);              
		// function to take a key value sent in from client program and search 
		// through list for a match
		int insert_edge(char * vertex1, char * vertex2); 
		// function to take two vertex's sent in from client program, and connect them
		// to each other
		int display_vertexs(char * key_value);           
		// function to display all the vertex's in list (all index's of list array)

		int display_next ( char * key_value); 
		// functin to take a key_value added by user and display all vertex's connected 
		//to it

	//	int display_depth(char * key_value);
       private:
               vertex * list; // an array of vertex's
               int list_size; // int to save size of list
}; 

char menu(); // function to display all the possible actions the user can take, to the user
