# Data Structures Practice

This project is designed to provide practice with basic data structures implemented in C. The following data structures are included:

- Linked List
- Stack
- Queue
- Tree

## Project Structure

```
datastruct-practice
├── CMakeLists.txt          # Main configuration file for CMake
├── include                  # Header files for data structures
│   └── datastruct
│       ├── linked_list.h   # LinkedList class definition
│       ├── stack.h         # Stack class definition
│       ├── queue.h         # Queue class definition
│       └── tree.h          # Tree class definition
├── src                     # Source files for data structures
│   ├── linked_list.c       # Implementation of LinkedList methods
│   ├── stack.c             # Implementation of Stack methods
│   ├── queue.c             # Implementation of Queue methods
│   └── tree.c              # Implementation of Tree methods
├── tests                   # Unit tests for data structures
│   ├── CMakeLists.txt      # Configuration file for tests
│   ├── test_linked_list.cpp # Unit tests for LinkedList
│   ├── test_stack.cpp       # Unit tests for Stack
│   ├── test_queue.cpp       # Unit tests for Queue
│   └── test_tree.cpp        # Unit tests for Tree
└── README.md               # Project documentation
```

## Setup Instructions

1. Clone the repository:
   ```
   git clone <repository-url>
   cd datastruct-practice
   ```

2. Create a build directory and navigate into it:
   ```
   mkdir build
   cd build
   ```

3. Run CMake to configure the project:
   ```
   cmake ..
   ```

4. Build the project:
   ```
   make
   ```

5. Run the tests:
   ```
   cd tests
   make
   ./run_tests
   ```

## Usage Examples

### Linked List

To use the LinkedList class, include the header file and create an instance of the class. You can then call its methods to manipulate the list.

### Stack

The Stack class can be used similarly by including its header and creating an instance. Use the provided methods to push and pop elements.

### Queue

The Queue class allows for enqueueing and dequeueing elements. Include the header and create an instance to start using it.

### Tree

For the Tree class, include the header and create an instance to insert nodes and traverse the tree.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.