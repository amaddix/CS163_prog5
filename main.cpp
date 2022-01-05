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


int main()
{
	table graph; // instance of table class
//	path my_path[SIZE];

	char * key_value; //variable to save a vertex name sent in by user
	char * vertex1; // variable to save a vertex name to be connected to another vertex
	char * vertex2; // variable to save  a vertex name to connect to another vertex

	char choose; //variable to save a users choice of action
	char temp[100]; //variable to tempararly save users information
	int worked=0; // variable to save the returned value of function calls


	// continue until has added a vertex into each index of list array
	cout<<"***Please add "<<SIZE<<" steps***"<<endl;

	for (int i=0; i < SIZE; ++i)
	{
		cout<<" what is the name of a step?"<<endl;
		//save in temp
		cin.get(temp, 100, '\n');
		cin.ignore(100, '\n');	

		// allocate memory for key_value and save temp into
		key_value= new char[strlen(temp)+1];
		strcpy(key_value, temp);

		//call function to add this vertex in list array
		worked=graph.insert_vertex(key_value);
	}


	// display all the vertex's added to array
	graph.display_vertexs(key_value);


	// continue prompting and reading in action until user chooses to quit
	do
	{
		choose=menu();  // call function to display actions to user

		// if the user would like to add a connection between two 
		// vertex's...
		if (choose=='1')
		{

			//get the on to connect something to
			cout<<"what is the step to connect something to?"<<endl;
			cin.get(temp, '\n');
			cin.ignore(100, '\n');	

			vertex1= new char[strlen(temp)+1];
			strcpy(vertex1, temp);

			// get the one to be connected to the first one
			cout<<"what is the step to connect "<< vertex1<<" to?"<<endl;
			cin.get(temp, '\n');
			cin.ignore(100, '\n');	

			vertex2= new char[strlen(temp)+1];
			strcpy(vertex2, temp);

			// call function to save connect these two vertex's
			worked=graph.insert_edge(vertex1, vertex2); 
			
			// output success or failure 
			if (worked)
				cout<<"*** successfully added connection ***"<<endl;
			else
				cout<<"*** looks like one of your inputs didnt match"
				<<" any steps you've previously inputted ***"<<endl;

		}

		//display steps that can be taked after a given step
		if (choose=='2')
		{
			char temp[100];

			// get the vertex that the user would like to display all 
			// connected verticies	
			cout<<"What step would you like to display all "
			<<"the corresponding steps?"<<endl;
			cin.get(temp, '\n');
			cin.ignore(100, '\n');
		
			key_value= new char[strlen(temp)+1];
			strcpy(key_value, temp);

			// call function to display then
			worked=graph.display_next (key_value);
			if (worked)
				cout<<"*** Successfuly displayed all connection "
				<<"to "<<key_value<<"***"<<endl;
			else
				cout<<"***Looks like there was not step matching "
				<<key_value<<"***"<<endl;
		}
		//
/*
		//display depth first traversal path
		if (choose == '3')
		{}
		//
*/
	} while (choose != '3');

}

//function to display all the possible actions the user can take and return their choice
char menu()
{
	char temp;
	cout<<"*** Please choose an action ***"<<endl
		<<"1.	add a connection"<<endl
		<<"2.	display all the corresponding steps to a particular step"<<endl
		<<"3.	quit"<<endl;
	cin>>temp;
	cin.ignore(100, '\n');

	return temp;
}	

