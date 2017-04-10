README:

Objective: 
	Create a Graph ADT with an adjacency list to represent the neighbors of the vertices with BFS functionality. 
	Then use an in file to read in vertices and perform BFS on certain vertice pairs.

Files:
List.h:
	Header file for List ADT contains function headers for List.c.
List.c:
	Contains all the function for List ADT. Used in the adj list and in bfs to replace the queue in BFS.
Graph.h:
	Header file for Graph ADT contains function headers for Graph.c.
Graph.c:
	Contains all the functions for the Graph ADT. Contains the BFS algorithim, and the adj list.
GraphTest.c:
	Tests the Graph ADT and all the fuctions for the correct output.
FindPath.c:
	Reads an in file and uses the data to create a Graph and run BFS on select vertices, checks the path, and the prints the path.
MakeFile:
	Creates a FindPath exacutable that takes two file arguments.
	
