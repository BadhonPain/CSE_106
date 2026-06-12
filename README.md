<div align="center">

# 🧪 CSE 106 — Data Structures and Algorithms I Sessional

### Bangladesh University of Engineering and Technology (BUET)

[![Language: C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Language: C](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.cppreference.com/w/c)

*Coursework, homework assignments, and lab exam solutions for CSE 106: Data Structures and Algorithms I Sessional at BUET.*

---

</div>

## 📑 Table of Contents

- [Course Overview](#-course-overview)
- [Directory Structure](#-directory-structure)
- [Offline Assignments](#-offline-assignments)
- [Online Lab Exams](#-online-lab-exams)
- [Related Repositories](#-related-repositories)
- [How to Compile and Run](#-how-to-compile-and-run)
- [Author & Maintainer](#-author--maintainer)

---

## 📖 Course Overview

This repository contains the coursework, homework assignments, and lab exam solutions for the **CSE 106: Data Structures and Algorithms I Sessional** course at **Bangladesh University of Engineering and Technology (BUET)**.

The course is structured around two main assessment components:
*   **Offline Assignments:** Comprehensive assignments completed at home, focused on implementing core data structures and algorithmic paradigms from scratch.
*   **Online Lab Exams:** Time-constrained lab exams conducted in the BUET computer laboratory to test problem-solving ability, algorithmic efficiency, and the application of offline concepts to new scenarios.

---

## 📂 Directory Structure

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

## 📝 Offline Assignments

### [Offline 01: List ADT](./Offline/Offline_01)
> **Concepts:** Sequential List, ArrayList, Doubly Linked List, ADT Design

Developed an integer-based List Abstract Data Type (ADT) from scratch using two separate approaches:
1.  **ArrayList** (Dynamic Array representation with automatic resizing).
2.  **Doubly Linked List** (Pointer-based node representation).

<details>
<summary>📄 View Details</summary>

*   **Supported Operations:** Current position tracking (`|`), insertion, deletion, appending, search, traversal (`next`/`prev`), range swaps, and list reversal.

</details>

---

### [Offline 02: Queue ADT & Stack Application](./Offline/Offline_02)
> **Concepts:** Linear Data Structures, Circular Queue, Compilers & Syntax Parsing

Implementation of basic linear data structures and their direct applications:
1.  **Queue ADT:** Implemented a generic Queue ADT using both dynamic arrays (Circular Queue) and linked lists.
2.  **Compiler Syntax Checker:** Parsed source code files to build a syntax/bracket checker using Stacks to detect unbalanced parentheses, braces, and brackets, identifying the exact line numbers and mismatched characters.

---

### [Offline 03: Binary Search Tree (BST)](./Offline/Offline_03)
> **Concepts:** Tree Data Structures, Templates, Real-time Query Systems

A dual-part project implementing tree structures and real-time transaction tracking:
1.  **BST Implementation:** Created a template-based Binary Search Tree storing generic key-value pairs. Supported insertion, deletion, lookup, minimum/maximum query, successor/predecessor traversal, and nested representation formatting.
2.  **Auction Bid Tracker:** Developed a system simulating bidding events (inserting bids, updating bids, and finding highest/lowest bids) powered by the BST.

---

### [Offline 04: Graph Algorithms](./Offline/Offline_04)
> **Concepts:** Graph Theory, Connected Components, BFS, DFS

Given a list of tournament match outcomes, reconstructed group structures using Connected Components analysis. For each group, identified and listed all expected matches that had not yet been played.

---

### [Offline 05: Min-Heap ADT](./Offline/Offline_05)
> **Concepts:** Binary Heaps, Bottom-up Heapification, HeapSort

Implemented an array-based Min-Heap supporting bottom-up $O(N)$ heapification, insertion, extract-min, decrease-key, delete-key, and an in-place HeapSort implementation.

---

### [Offline 06: Emergency Communication Network](./Offline/Offline_06)
> **Concepts:** Divide & Conquer, Geometric Connectivity, Closest Pair of Points

Solved a geometric city-connectivity problem. Given $N$ 2D coordinates (cities), built a minimum-cost connected network (Minimum Spanning Tree-style) using a Divide and Conquer approach in strictly better than $O(N^2)$ time.

---

### [Offline 07: Global Sequence Alignment](./Offline/Offline_07)
> **Concepts:** Dynamic Programming, Edit Distance, Sequence Alignment

Computed the minimum cost required to align/transform a source sequence into a target sequence using insertions, deletions, and substitutions (each with custom costs). Traced and reconstructed the exact sequence of edit operations.

---

## 💻 Online Lab Exams

### [Online 01: Array Triplet Sum](./Online/Online_01)
> **Concepts:** Array Traversals, Sorting, Two-Pointer Approach

Given an array of integers, found any triplet of unique indices $(i, j, k)$ such that $A[i] + $A[j] + $A[k] = 0$. Optimized the search to run in $O(N^2)$ time and $O(1)$ auxiliary space using sorting and the two-pointer technique.

---

### [Online 02: List Block Reversal & Stack Duplicate Removal](./Online/Online_02)
> **Concepts:** List Reversal, Stacks, Linear Time Complexity

Two separate challenges on basic data structure manipulations:
*   **Problem 1:** Added `reverse_range(int k)` to the List ADT to reverse consecutive blocks of size $k$ without allocating extra memory or auxiliary data structures.
*   **Problem 2:** Used a Stack to iteratively remove all adjacent duplicate characters from a string in a single $O(N)$ linear pass (e.g., `"abbaca"` $\rightarrow$ `"ca"`).

---

### [Online 03: Lowest Common Ancestor (LCA)](./Online/Online_03)
> **Concepts:** BST Ancestors, Time & Space Complexity Optimization

Implemented a method `find_lca(Key key1, Key key2)` to find the Lowest Common Ancestor of two existing keys in a BST in $O(\text{height})$ time complexity and $O(1)$ constant auxiliary space.

---

### [Online 04: Graph Mutual Friends](./Online/Online_04)
> **Concepts:** Social Network Analysis, Graph Traversal

Analyzed a friendship network to identify all users who are "strangers" to a person of interest $S$. For each stranger, computed the count of mutual friends shared with $S$, printing the results sorted alphabetically by the stranger's identifier.

---

### [Online 05: Min-Heap k-Largest Elements](./Online/Online_05)
> **Concepts:** Heap Traversal, Output Redirection

Added `kLargest(int k, std::ofstream &outfile)` to the Min-Heap class to find and print the $k$ largest elements in descending order. The operation was restricted to run in $O((n+k)\log n)$ time without modifying the original heap structure.

---

### [Online 06: Damerau-Levenshtein Distance](./Online/Online_06)
> **Concepts:** Dynamic Programming, Transposition Operations

Extended the classic edit distance algorithm by incorporating a fourth transposition operation (swapping two adjacent characters, e.g., `"ca"` $\rightarrow$ `"ac"` at cost 1). Computed the minimum operations using a DP-based approach.

---

## 🔗 Related Repositories

Explore other academic repositories containing coursework, implementations, and study materials:

| Repository | Description | Language / Tech |
| :--- | :--- | :--- |
| [🧬 DSA Genesis](https://github.com/BadhonPain/DSA_Genesis) | A comprehensive repository covering fundamental to advanced Data Structures and Algorithms implementations. | C++17 |
| [🎨 AlgoVista](https://github.com/BadhonPain/AlgoVista) | An interactive Data Structures and Algorithms visualizer designed to make learning algorithms intuitive and visual. | JavaScript / HTML |
| [🌌 OOPverse](https://github.com/BadhonPain/OOPverse) | A dedicated space for Object-Oriented Programming (OOP) concepts, designs, and principles. | Java / C++ |

---

## 🚀 How to Compile and Run

All implementations are in standard C++ (C++11 or higher) and C. You can compile the files using any standard compiler such as `g++` or `gcc`.

### C++ Programs
```bash
# Compile
g++ -O3 -std=c++11 solution.cpp -o solution

# Run
./solution
```

### C Programs
```bash
# Compile
gcc -O3 main.c -o main

# Run
./main
```

> **Note:** No external libraries are required. All solutions depend only on the C/C++ standard library.

---

## 👤 Author & Maintainer

**Badhon Pain**
- 🎓 Undergraduate Student of Computer Science and Engineering
- 🏛 Bangladesh University of Engineering and Technology (BUET)
- 🔗 GitHub: [@BadhonPain](https://github.com/BadhonPain)

---

<div align="center">

*Maintained as part of coursework at BUET.*

</div>
