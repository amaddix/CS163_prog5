# CS163_prog5

Programming Assignment #5 
CS 163 Data Structures 
Submit your assignment to the D2L Dropbox (sign on via d2l.pdx.edu)



Goal and Data Structures: The goal of this program is to create a SIMPLE directed  graph using an adjacency list (an array of vertices where each element has a vertex  and a head pointer to a LLL of edges for adjacent vertices). 
**TRY TO KEEP THIS SIMPLE – the goal is to get a feel for how graphs can be  created and traversed and how an adjacency list can be used but we have limited  time ** 
You have decided to create software to help automate a project that you are about  to work on. We just built a greenhouse and the next step will be to build an outdoor  shed. Before I can build the shed, I need to design the plans, decide on the overall  structure, and buy the wood. Of course before that I have to locate where I will  place it and how big I will make it. Then comes the hard labor! I hope to get the  windows from the restore and make it a cool place to work! 
Your assignment will be to take as input the steps for a project you are going to  work on this summer. It is important to first enter in all of the steps before  connecting them with edges. Each step will be a vertex. Although this is a directed  graph, it is not a weighted graph. 
With this information, your program needs to build an adjacency list. The  adjacency list will be an array of vertex objects (courses), and head pointers for  each linear linked list representing the edge list (representing the order in which  these steps need to take place).  
The adjacency list should contain:  
(1) Vertex Information (a description of a step in the project) 
(2) Head pointer (to an Edge List); the edge list just indicates all of the steps  that can be started once this step is complete  
After building the adjacency list, allow the client program to perform the following  actions:  
1. Display all other steps that can be started next after finishing a particular  step.  
2. Also implement the destructor to deallocate all dynamic memory. ***There  is NO requirement for an INDIVIDUAL DELETE function!  
3. Extra credit: Depth First Traversal – show at least one path all the way  through the data structure from start to finish. Use a combination of  iteration and recursion to implement this algorithm!
CS163 Spring 2018 Assignment #5 
Things you should know...as part of your program: 
1) Do not use statically allocated arrays in your classes or structures. All  memory must be dynamically allocated and kept to a minimum!  2) All data members in a class must be private 
3) None of your public member functions should have “node” data types as  arguments. However, you SHOULD have private RECURSIVE member  functions that do take node pointers as arguments 
4) Global variables are not allowed in CS163 – not even in your main 5) Do not use the String class – not even in your test suite! (use arrays of  characters instead!) 
6) Use modular design, separating the .h files from the .cpp files.  7) Use the iostream library for all I/O; do not use stdio.h. 
8) Make sure to define a constructor and destructor for your class. Your  destructor must deallocate all dynamically allocated memory.

---------------------------------------------------------------

EFFICIENCY WRITE UP

How well did the data structure selected perform for the assigned application?
I think using an array of linear linked lists work pretty great for this data structure. I think it organizes our information well and makes things easy to visualize. Because each index of our array is a step and each node attached to that index is a pointer to another index of the array to represent the steps that can be taken after that step (are connected to each other).
Would a different data structure work better? If so, which one and why…
I don't really think so. If we used a linear linked lists of linear linked lists, then we would not have direct access to each step (vertex). However, a pro to this is that the user could continue to add as many steps as they would like ( and the program wouldn't have to specify it for them/ have them specify at the beginning and stick to that number.)
For the same reason why a linear linked list of linear linked lists would be beneficial, an array of arrays could be annoying for the user to user. Because they would be forced to not only specify the amount of steps they will be adding, but also how many connections each step will have before hand. Unless, of course the program defined the array size for them, and in this case there could be the problem of creating too little an array for the user, and they are unable to add all the steps they would like, or adding too much space, and washing memory. 
And of course, just using a linear linked list or array would make using a graph very confusing and doesn't seem very possible.
What was efficient about your design and use of the data structure?
One thing that I think made my program efficient was that I had a find_location function that was used to find the index of the vertex array of a particular key value passed in by user. This allowed me to call it within multiple functions so I didn't have to re- write that conde multiple types.
Most of my functions were fairly short and specific to what my objective was. I think that this helped make my program more efficient since this means that hopefully many of my functions will not repeat an action.
 And in general I did my best not to traverse more than necessary. Checking if there was even a head pointer in that index of my array in the first place, then traversing through just the right amount.
What was not efficient?
I know that I probably could have made my code much more efficient by using (or better user) pointer arithmetic. This would have allowed me to have direct access to each index of my array, rather then increment through like I mostly did throughout my program. 
In general, Im sure throughout my program there were times when I could have wrote something different that involved less fetches and operations. 
What would you do differently if you had more time to solve the problem?
If I had more time to work on this program, I would have made a better attempt at implementing the recursive - iteration function to find one path by depth. I did begin to try to do this, however I decided it was more important to study for my final, so that part of my code has been commented out. 
Another thing that I would have liked to spend more time on would be implementing all my functions to use pointer arithmetic. I know that this would greatly improve my performance and efficiency of my program. 

