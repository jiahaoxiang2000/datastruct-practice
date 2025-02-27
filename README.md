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
│   ├── test_tree.cpp        # Unit tests for Tree
│   └── test_main.cpp       # Main test runner
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
   ctest
   ```

   Or run the test executable directly:

   ```
   ./tests/run_tests
   ```

## Testing Framework

The project uses Google Test for unit testing. Each data structure has its own test file:

- `test_linked_list.cpp`: Tests for linked list operations (insert, delete, search)
- `test_stack.cpp`: Tests for stack operations (push, pop, peek)
- `test_queue.cpp`: Tests for queue operations (enqueue, dequeue, peek)
- `test_tree.cpp`: Tests for tree operations (insert, delete, traversal)

To run specific tests:

```
./tests/run_tests --gtest_filter=LinkedListTest.*
```

## Building Your Own Tests

You can add your own test cases by:

1. Creating a new test file in the `tests` directory
2. Adding your test cases using the Google Test framework
3. Updating the `CMakeLists.txt` in the `tests` directory to include your new test file

Example:

```cpp
// tests/my_custom_test.cpp
#include <gtest/gtest.h>
#include <datastruct/linked_list.h>

TEST(CustomTest, MyTestCase) {
    LinkedList* list = linked_list_create();
    linked_list_append(list, 10);
    EXPECT_EQ(linked_list_size(list), 1);
    linked_list_destroy(list);
}
```

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.
