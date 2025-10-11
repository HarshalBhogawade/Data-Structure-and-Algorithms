# Data_Structure_and_Algorithms
# Linked List Data Structure Implementation

This repository contains implementations of basic operations on **Singly Linked Lists** and **Doubly Linked Lists** in C++.

## Files Overview

- `LLbasicoperations.cpp` - Basic operations on Singly Linked List
- `DeletioninLL.cpp` - Insertion and Deletion operations on Singly Linked List  
- `DLLBasicOperations.cpp` - Insertion and Deletion operations on Doubly Linked List

## Singly Linked List Operations

### Basic Operations
- **Create Linked List** from array
- **Print** linked list elements
- **Traverse** through the list

### Deletion Operations
- Delete head node
- Delete tail node
- Delete Kth element (by position)
- Delete element by value

### Insertion Operations
- Insert at head
- Insert at tail
- Insert at Kth position
- Insert before a specific value

## Doubly Linked List Operations

### Deletion Operations
- Delete head node
- Delete tail node
- Delete Kth element (by position)
- Delete a specific node (given node reference)

### Insertion Operations
- Insert before head
- Insert after head
- Insert at tail
- Insert before tail
- Insert before Kth position
- Insert after Kth position
- Insert before a specific node

## Key Features

✅ **Memory Management** - Proper allocation and deallocation of nodes  
✅ **Edge Case Handling** - Handles empty lists, single node lists, and boundary conditions  
✅ **Bidirectional Links** - Doubly linked list maintains both forward and backward pointers  
✅ **Modular Code** - Each operation is implemented as a separate function  

## Implementation Details

### Singly Linked List Structure
- Node contains integer data and pointer to next node
- Standard singly linked list with forward traversal only

### Doubly Linked List Structure  
- Node contains integer data, pointer to next node, and pointer to previous node
- Bidirectional traversal supported with both forward and backward links

---

*This implementation covers fundamental linked list operations essential for data structures and algorithms practice.*
