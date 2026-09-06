# Finzly Trainee Software Engineer (Java Full Stack & AI) - OA DSA Questions (2025-2026)

Based on recent interview experiences (2024–2025) for the **Trainee Software Engineer (Java Full Stack & AI)** role at Finzly, their Online Assessment (OA) is typically hosted on platforms like **Coderbyte**. Finzly's DSA questions strictly stick to **Easy to Medium difficulty**.

Below is the curated compilation of high-frequency Coderbyte and Fintech OA coding questions that mirror exactly what Finzly asks, structured exactly according to the categorizations in this repository.

## 00-Mathematics (Math & Bit Manipulation)
Coderbyte heavily tests basic mathematical logic wrapped in array or string formats. Bit manipulation frequently appears as the "Easy" 15-minute question.
* Questions Marks *(Exact Coderbyte - check if exactly 3 question marks exist between pairs of numbers that sum to 10)*
* Powers of Two *(Exact Coderbyte)*
* Product Digits *(Exact Coderbyte)*
* Other Products *(Exact Coderbyte)*
* Prime Mover *(Exact Coderbyte)*
* Arith Geo *(Exact Coderbyte - determine if an array is an arithmetic or geometric sequence)*
* Step Walking *(Exact Coderbyte)*
* Number Encoding *(Exact Coderbyte)*
* Sieve of Eratosthenes (Generating primes up to N)
* Single Number / Single Number II / III (Solve using XOR)
* Number of 1 Bits (Hamming Weight)
* Counting Bits
* Find the Missing Number (Using Bitwise XOR)
* Reverse Bits of a 32-bit unsigned integer
* Bitwise AND of Numbers Range

## 01-Array 
Array manipulation is the most heavily tested topic in Finzly’s coding rounds.
* Two Sum
* Best Time to Buy and Sell Stock
* Find the Missing Number in an Array
* Product of Array Except Self
* Move Zeroes to the End
* Find All Duplicates in an Array
* Subarray Sum Equals K
* Merge Overlapping Intervals / Insert Interval
* Sort Colors (Dutch National Flag Problem)
* Rotate Array by K steps
* Next Permutation
* Find First and Last Position of Element in Sorted Array
* Trapping Rain Water
* 3Sum
* Maximum Product Subarray
* Majority Element (Boyer-Moore Voting Algorithm)
* Contains Duplicate
* Squares of a Sorted Array
* Intersection of Two Arrays
* LargestFour (Find the max sum of 4 numbers in an array)

## 03-Matrix
* Valid Sudoku
* Spiral Matrix Traversal
* Set Matrix Zeroes
* Minimum Path Sum in a Grid

## 04-Recursion (Recursion & Backtracking)
Coderbyte has a very distinct way of testing Backtracking. The hidden test cases are designed to time-out brute-force loops, meaning standard recursive backtracking (maintaining a "current state" and an "index") is required.
* Bracket Combinations *(Exact Coderbyte - Highest frequency Backtracking problem. Find valid well-formed combinations using `num` pairs of parentheses)*
* Array Addition I (Subset Sum) *(Exact Coderbyte - Recursive function to see if any subset sum equals the largest array number)*
* Chessboard Traveling *(Exact Coderbyte - Given "(1,1)(2,2)", calculate distinct ways to travel up/right using recursion)*
* Eight Queens *(Exact Coderbyte - Given string array of coordinates, determine if any queens are attacking)*
* Pentagonal Number *(Exact Coderbyte - Calculate dots in a pentagonal shape around a center dot at iteration `N`)*
* Word Split *(Exact Coderbyte - Given a long word and a dictionary array, determine if the word can be split into exactly two dictionary words)*
* String Scramble *(Exact Coderbyte - Determine if portion of characters in str1 can be rearranged to exactly match str2)*
* Permutations *(Often used as a sub-routine in their Hard-level string problems)*

## 05-SlidingWindow
* Maximum Subarray (Kadane’s Algorithm)
* Minimum Window Substring
* Longest Substring Without Repeating Characters
* Longest Repeating Character Replacement
* Sliding Window Maximum (Using Deque)
* Moving Median *(Exact Coderbyte - sliding window median using Heaps)*

## 06-Binarysearch
* Search in a Rotated Sorted Array
* Find Minimum in Rotated Sorted Array
* Find Peak Element

## 07-hashMap (Hash Tables, Heaps & Strings)
Fintech OAs test Hash Maps heavily because data retrieval speed is a core concept.
* K Unique Characters *(Exact Coderbyte)*
* Codeland Username Validation *(Exact Coderbyte)*
* Top K Frequent Elements
* Find K Pairs with Smallest Sums
* Longest Consecutive Sequence (O(n) time using HashSets)
* Continuous Subarray Sum (Using HashMap for remainders)
* Design a HashMap from scratch
* Subarray Sums Divisible by K
* Task Scheduler
* Kth Largest Element in a Stream / Array
* Merge K Sorted Arrays (using Min-Heap)
* Valid Anagram / Group Anagrams
* Valid Palindrome / Longest Palindromic Substring / Palindromic Substrings
* Longest Common Prefix
* String to Integer (atoi)
* Implement strStr() / Find Index of First Occurrence
* Encode and Decode Strings
* Isomorphic Strings
* Word Pattern
* Find All Anagrams in a String
* Sort Characters By Frequency
* Reverse Words in a String
* First Unique Character in a String
* Check if Two Strings are k-Anagrams
* Roman to Integer / Integer to Roman
* Count and Say
* Find the Length of the Last Word
* Check if String is a Rotation of Another
* Reorganize String (Max-Heap frequency mapping)

## 09-Linkedlists
Coderbyte often frames Linked List problems as conceptual questions or requires you to manipulate them in chunks.
* Implement a Queue using a Linked List *(Exact Coderbyte)*
* Reverse a Linked List / Reverse Nodes in k-Group
* Merge Two Sorted Lists / Merge k Sorted Lists
* Linked List Cycle Detection (Floyd’s Algorithm) / Linked List Cycle II
* Find the Middle of the Linked List
* Remove Nth Node From End of List
* Intersection of Two Linked Lists
* Palindrome Linked List
* Add Two Numbers Represented by Linked Lists
* Copy List with Random Pointer
* Flatten a Multilevel Doubly Linked List
* Rotate a Linked List
* Sort a Linked List
* Remove Duplicates from a Sorted/Unsorted Linked List
* Partition List around a Value x
* Odd Even Linked List
* Swap Nodes in Pairs
* Delete Node in a Linked List (when you are only given access to that specific node)

## 10-Stack
Coderbyte loves using Stacks to parse strings. If you get a String question that isn't a sliding window, it is almost certainly a Stack problem.
* Bracket Matcher *(Exact Coderbyte Classic)*
* String Reduction *(Exact Coderbyte)*
* Bracket Combinations *(Exact Coderbyte)*
* Remove Brackets *(Exact Coderbyte)*
* Implement Queue using Two Stacks *(Exact Coderbyte)*
* Evaluate Reverse Polish Notation (Evaluate mathematical strings)
* Next Greater Element
* Minimum Add to Make Parentheses Valid
* Valid Parentheses / Validate Stack Sequences
* Sort a Stack using another Stack
* Simplify Path (Unix-style file paths)
* Decode String (e.g., parsing `3[a2[c]]`)
* Asteroid Collision
* Daily Temperatures (Monotonic Stack)
* Min Stack (Design a stack that supports getMin in O(1))

## 11-Queue
* Implement Stack using Queues
* Implement Queue using Two Stacks

## 12-Trees & 13-BST
Coderbyte has a specific way of testing Trees—often passing the tree into your function as an array of strings.
* Tree Constructor *(Exact Coderbyte - You are given a string array of `(child, parent)` pairs and must determine if it forms a valid binary tree)*
* Maximum Depth of Binary Tree / Minimum Depth of Binary Tree
* Symmetric Tree / Invert/Mirror a Binary Tree
* Binary Tree Level Order Traversal (BFS) / Binary Tree Zigzag Level Order Traversal
* Binary Tree Right Side View
* Path Sum II (Find all root-to-leaf paths that equal a target)
* Flatten Binary Tree to Linked List
* Lowest Common Ancestor of a Binary Tree / BST
* Serialize and Deserialize Binary Tree
* Diameter of Binary Tree
* Kth Smallest Element in a BST
* Validate Binary Search Tree

## 14-Graph
* Number of Islands (Grid BFS/DFS)
* Max Area of Island
* Word Search (Grid DFS)
* Rotting Oranges (Grid BFS)
* Clone a Graph
* Course Schedule (Topological Sort)
* Find the Town Judge (Graph node degrees)

## Dynamic Programming & Greedy (General)
* Climbing Stairs / Minimum Cost Climbing Stairs
* Coin Change
* Longest Increasing Subsequence
* Word Break
* House Robber
* Decode Ways
* Jump Game
* Maximum Length of Pair Chain
* Partition Equal Subset Sum

---

### 💡 Crucial "Full Stack & AI" Specifics for Finzly
1. **Java & OOP Focus:** Because Finzly's core architecture relies on Java, expect heavy MCQs on Java 8/11 features (Streams, Lambdas), Garbage Collection, and deep Object-Oriented principles (Polymorphism, Abstraction).
2. **Spring Boot & REST APIs:** You will likely be asked to write or debug a Spring Boot REST API. Know your HTTP Status Codes intimately (e.g., the exact difference between `401 Unauthorized` and `403 Forbidden`).
3. **Database & SQL:** The OA includes SQL queries. Be prepared to write queries involving `JOINs`, `GROUP BY`, and `HAVING`. You will also be asked conceptual questions comparing SQL vs. NoSQL (PostgreSQL vs. MongoDB) and Database Indexing.
4. **Security:** Understand how JWT (JSON Web Tokens) authentication flows work, as this is a standard Finzly interview question for Full Stack roles.

**Strategy for the Coderbyte OA:**
* **Standard Input/Output:** Practice reading multi-line string inputs into arrays using Java's `Scanner` or `BufferedReader` (Coderbyte doesn't always provide clean function stubs like LeetCode).
* **Stringified Trees:** Practice parsing string arrays into actual Graph/Tree nodes.
* You will usually have ~60-90 minutes. Solve the easy question first (usually Array/String or Bit Manipulation) to secure partial marks, then move to the Medium question. Do not get stuck on edge cases for the Medium problem until the brute-force logic is passing the base test cases.

