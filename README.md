# Searching Algorithms Server
[Github Repository](https://github.com/Dimmzy/searching-algorithms-server)

The Searching Algorithms Server program provides a framework to handle communications between a client and a server.
The main focus of the program is to allow the client to send a structured "problem" and the server to process it and pass a solution.

In our instance, we receive weighted graphs represented as Matricies and perform path finding algorithms to find the best path between the starting node and the ending node.

#### Algorithms
The Algorithms we have implemented for pathfinding are:
* [BFS](https://en.wikipedia.org/wiki/Breadth-first_search)
* [DFS](https://en.wikipedia.org/wiki/Depth-first_search)
* [Best First Search](https://en.wikipedia.org/wiki/Best-first_search)
* [A*](https://en.wikipedia.org/wiki/A*_search_algorithm)

> BFS and DFS don't take into consideration the weights of the nodes so they've been compared for complexity by number of nodes processed.

Running all four algorithms on a 37x37 matrix with some blocked cells (denoted with -1) we have received the following results:

![alt text](https://i.imgur.com/ru1B1LZ.png)

So for cases where we're looking for the *cheapest* and *shortest* path, we'll be defaulting to use A*.


## Usage

Compile with

> g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

You can then connect to the server (port 5600 by default) or specify a port as an argument.

Send the matrix you want to use A* on, and after several calculations you'll receive the A* path as output from the server.

The matrix template you send to the server is:

> cell\[00],cell\[01],cell\[02],...,cell\[0n-1]

> cell\[10],cell\[11],cell\[12],...,cell\[1n-1]

> ...

> cell\[n-10],cell\[n-11],cell\[n-12],...,cell\[n-1n-1]

> 0,0  <-- Starting cell

> n-1,n-1  <-- Goal cell

> end

The cell locations should denote the cost for the specific cell.  *cost of -1 is blocked cell*.

For example:

> 1,2,3

> 3,-1,2

> 3,3,3

> 0,0

> 2,2

> end

## Contributors
[Dima](https://github.com/Dimmzy)   
[Haim](https://github.com/HaimIsakov)
