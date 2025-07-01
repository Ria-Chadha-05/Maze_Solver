# Maze_Solver

A command-line pathfinding application built using C++ and core data structures. This project demonstrates how DFS (Depth-First Search) and BFS (Breadth-First Search) algorithms can be applied to solve mazes represented as 2D matrices.


📌 Project Description

The Maze Solver allows the user to input or define a maze as a 2D matrix of walls and paths, and find a valid path from a starting point to an exit using both:

- **DFS**: Explores all possible paths using backtracking  
- **BFS**: Guarantees the shortest path using a queue-based level-order traversal  

The project provides visual feedback of the solution path in the console and is designed with flexibility for additional features like multiple exits and random maze generation.


📌 Methodology

- The maze is represented as a 2D grid:
  - `0` = path  
  - `1` = wall  
- **DFS** is implemented using recursion and backtracking, storing the path when it reaches the goal  
- **BFS** is implemented using a queue with a parent-tracking array to reconstruct the shortest path after reaching the exit  
- Input is currently hardcoded but can be extended to support:
  - File input  
  - Dynamic grid size  
  - Random maze generation  


📌 Use Cases

- Teaching pathfinding algorithms in DSA courses  
- Algorithm visualization and debugging  
- Robotics path simulation on grids  
- Foundation for game level logic (mazes, dungeons)  


📌 Skills Used

- C++ (recursion, conditionals, loops)  
- 2D arrays and grid traversal  
- STL: `queue`, `vector`, `pair`  
- DFS with backtracking  
- BFS with shortest path reconstruction  



📌 Key Features

- Input maze as a 2D array 
- Solve using:
  - **DFS**: Finds *a* path to exit  
  - **BFS**: Finds *shortest* path to exit  
- Output path as sequence of coordinates  
- Visual path tracing in console  


📌 Application Areas

- Game AI or logic engine for maze levels  
- Grid-based robot simulation (e.g., warehouse bots)  
- Any problem involving search in graphs or matrices  


📌 Scope for Improvement

- Support file-based maze input/output  
- Add visualization using SFML or ASCII animation  
- Add multiple exit detection  
- Implement A* or Dijkstra for weighted mazes  
- Generate large random mazes with more obstacles  