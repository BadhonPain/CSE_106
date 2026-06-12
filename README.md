# CSE 106: Data Structures and Algorithms I Sessional

This repository contains the coursework, homework assignments, and lab exam solutions for the **CSE 106: Data Structures and Algorithms I Sessional** course at **Bangladesh University of Engineering and Technology (BUET)**.

---

## Course Overview

The course contents are divided into two main categories:
1. **Offline Assignments**: Comprehensive assignments completed at home, focused on implementing core data structures and algorithmic paradigms from scratch.
2. **Online Lab Exams**: Time-constrained lab exams conducted in the BUET computer laboratory to test problem-solving ability, algorithmic efficiency, and the application of offline concepts to new scenarios.

---

## Directory Structure

```text
CSE_106/
├── Offline/                  # Homework assignments (from home)
│   ├── Offline_01/           # List ADT (ArrayList & Doubly Linked List)
│   ├── Offline_02/           # Queue ADT & Stack (Syntax Checker)
│   ├── Offline_03/           # Binary Search Tree (BST) & Auction Bid Tracker
│   ├── Offline_04/           # Graph Theory (Tournament Groups & Unplayed Matches)
│   ├── Offline_05/           # Min-Heap ADT & HeapSort
│   ├── Offline_06/           # Divide & Conquer (Emergency Communication Network)
│   └── Offline_07/           # Dynamic Programming (Global Sequence Alignment / Edit Distance)
└── Online/                   # Lab exam problems (in BUET lab)
    ├── Online_01/            # Array Triplet Sum (O(N^2) time & space)
    ├── Online_02/            # List Block Reversal & Stack Duplicate Removal
    ├── Online_03/            # Lowest Common Ancestor (LCA) in BST
    ├── Online_04/            # Graph Mutual Friends & Stranger Finder
    ├── Online_05/            # Min-Heap k-Largest Elements (Descending Order)
    └── Online_06/            # Damerau-Levenshtein Distance (DP with Transposition)
```

---

## Offline Assignments

### [Offline 01: List ADT](./Offline/Offline_01)
*   **Topic**: Implementation of Sequential List Abstract Data Type.
*   **Description**: Developed integer-based List ADT from scratch using two separate approaches:
    1.  **ArrayList** (Dynamic Array representation with automatic resizing).
    2.  **Doubly Linked List** (Pointer-based node representation).
*   **Supported Operations**: Current position tracking (`|`), insertion, deletion, appending, search, traversal (`next`/`prev`), range swaps, and list reversal.

### [Offline 02: Queue ADT & Stack Application](./Offline/Offline_02)
*   **Topic**: Linear Data Structures (Queues and Stacks).
*   **Description**: 
    1.  Implemented a generic **Queue ADT** using both dynamic arrays (Circular Queue) and linked lists.
    2.  Solved a **Stack application** problem: parsed source code files to build a compiler syntax/bracket checker that detects unbalanced parentheses, braces, and brackets, identifying the exact line numbers and mismatched characters.

### [Offline 03: Binary Search Tree (BST)](./Offline/Offline_03)
*   **Topic**: Tree Data Structures.
*   **Description**: 
    1.  Implemented a template-based **Binary Search Tree** storing generic key-value pairs. Supported insertion, deletion, lookup, minimum/maximum query, successor/predecessor traversal, and nested representation formatting.
    2.  Developed an **Auction Bid Tracker** system simulating bidding events (inserting bids, updating bids, and finding the highest/lowest bids) using the BST.

### [Offline 04: Graph Algorithms](./Offline/Offline_04)
*   **Topic**: Graph Theory & Traversals (DFS/BFS).
*   **Description**: Given a list of tournament match outcomes, reconstructed group structures using Connected Components analysis. For each group, identified and listed all expected matches that had not yet been played.

### [Offline 05: Min-Heap ADT](./Offline/Offline_05)
*   **Topic**: Binary Heaps & HeapSort.
*   **Description**: Implemented an array-based **Min-Heap** supporting bottom-up $O(N)$ heapification, insertion, extract-min, decrease-key, delete-key, and an in-place **HeapSort** implementation.

### [Offline 06: Emergency Communication Network](./Offline/Offline_06)
*   **Topic**: Divide & Conquer.
*   **Description**: Solved a geometric city-connectivity problem. Given $N$ 2D coordinates (cities), built a minimum-cost connected network (Minimum Spanning Tree-style) using a Divide and Conquer approach in strictly better than $O(N^2)$ time.

### [Offline 07: Global Sequence Alignment](./Offline/Offline_07)
*   **Topic**: Dynamic Programming (Edit Distance).
*   **Description**: Computed the minimum cost required to align/transform a source sequence into a target sequence using insertions, deletions, and substitutions (each with custom costs). Traced and reconstructed the exact sequence of edit operations.

---

## Online Lab Exams

### [Online 01: Array Triplet Sum](./Online/Online_01)
*   **Topic**: Array Traversals & Two-Pointer Approach.
*   **Description**: Given an array of integers, found any triplet of unique indices $(i, j, k)$ such that $A[i] + A[j] + A[k] = 0$. Optimized the search to run in $O(N^2)$ time and $O(1)$ auxiliary space using sorting and the two-pointer technique.

### [Online 02: List Block Reversal & Stack Duplicate Removal](./Online/Online_02)
*   **Topic**: Basic Data Structures (Lists & Stacks).
*   **Description**:
    *   **Problem 1**: Added `reverse_range(int k)` to the List ADT to reverse consecutive blocks of size $k$ without allocating extra memory or auxiliary data structures.
    *   **Problem 2**: Used a Stack to iteratively remove all adjacent duplicate characters from a string in a single $O(N)$ linear pass (e.g., `"abbaca"` $\rightarrow$ `"ca"`).

### [Online 03: Lowest Common Ancestor (LCA)](./Online/Online_03)
*   **Topic**: Binary Search Tree.
*   **Description**: Implemented a method `find_lca(Key key1, Key key2)` to find the Lowest Common Ancestor of two existing keys in a BST in $O(\text{height})$ time complexity and $O(1)$ constant auxiliary space.

### [Online 04: Graph Mutual Friends](./Online/Online_04)
*   **Topic**: Graph Connections.
*   **Description**: Analyzed a friendship network to identify all users who are "strangers" to a person of interest $S$. For each stranger, computed the count of mutual friends shared with $S$, printing the results sorted alphabetically by the stranger's identifier.

### [Online 05: Min-Heap k-Largest Elements](./Online/Online_05)
*   **Topic**: Heap Operations.
*   **Description**: Added `kLargest(int k, std::ofstream &outfile)` to the Min-Heap class to find and print the $k$ largest elements in descending order. The operation was restricted to run in $O((n+k)\log n)$ time without modifying the original heap structure.

### [Online 06: Damerau-Levenshtein Distance](./Online/Online_06)
*   **Topic**: Dynamic Programming.
*   **Description**: Extended the classic edit distance algorithm by incorporating a fourth transposition operation (swapping two adjacent characters, e.g., `"ca"` $\rightarrow$ `"ac"` at cost 1). Computed the minimum operations using a DP-based approach.

---

## How to Compile and Run

All implementations are in standard C++ (C++11 or higher) and C. You can compile the files using any standard compiler such as `g++` or `gcc`.

### Example Compilation (C++):
```bash
# Compile
g++ -O3 -std=c++11 solution.cpp -o solution

# Run
./solution
```

### Example Compilation (C):
```bash
# Compile
gcc -O3 main.c -o main

# Run
./main
```

> **Note:** No external libraries are required. All solutions depend only on the C/C++ standard library.
---

## Related Repositories

If you are interested in more Data Structures, Algorithms, or Object-Oriented Programming resources, feel free to check out these related projects:

*   **[DSA_Genesis](https://github.com/BadhonPain/DSA_Genesis)**: A comprehensive repository covering fundamental to advanced Data Structures and Algorithms implementations.
*   **[AlgoVista](https://github.com/BadhonPain/AlgoVista)**: An interactive Data Structures and Algorithms visualizer designed to make learning algorithms intuitive and visual.
*   **[OOPverse](https://github.com/BadhonPain/OOPverse)**: A dedicated space for Object-Oriented Programming (OOP) concepts, designs, and principles.

---

## Author & Maintainer

*   **[Badhon Pain](https://github.com/BadhonPain)**
    *   *Current Undergraduate Student of Computer Science and Engineering*
    *   *Bangladesh University of Engineering and Technology (BUET)*

>*Maintained as part of coursework at BUET.*