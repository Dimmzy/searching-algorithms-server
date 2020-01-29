# Searching Algorithms Server
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

It's safe to say A* seems like the best choice, but we've tested each algorithm on 10 more matricies of varying sizes and these are the results graphed:

*<GRAPH_GOES_HERE>*


## Usage

*<USAGE_GOES_HERE>*

## Contributors
[Dima](https://github.com/Dimmzy)   
[Haim](https://github.com/HaimIsakov)
