# String Pattern Matching Program

Welcome to the String Pattern Matching Program! This program is designed to help you search for specific string patterns in a text file. Follow the steps below to get started:

## Instructions

### Setup

**Input Text File**: Place the text file you want to search through in the folder.

### Steps

1. **Open IDE**: Open your preferred C++ Integrated Development Environment (IDE) that supports C++ programming and can compile/run code.

2. **Configure `code.cpp`**: In the `code.cpp` file located in the  folder, configure the following variables in the `main` function:
   - `inputTextFile`: Set the variable to the name of the input text file that you placed in the folder. Example: `"input.txt"`
   - `pattern`: Set the variable to the string pattern you want to search for in the text file. Example: `"search_pattern"`

3. **Compile and Run**: Compile and run the `code.cpp` code in your IDE. This will execute the program and search for the specified pattern in the input text file.

4. **Check Results**: After successful compilation and running, the program will generate an output text file named `output.txt` in the folder. This file will contain the search results.

5. **Review Output**: Open the `output.txt` file to see the search results. It will display information about where the specified pattern was found in the input text file.

**Note**: If you need to search for different patterns, make sure to clear the `output.txt` file before running the program again.

### Example

For example, let's say you have a text file named `input.txt` and you want to search for the pattern `"examplepattern"`. You would set the `inputTextFile` variable to `"input.txt"` and the `pattern` variable to `"examplepattern"`. After running the program, the `output.txt` file will show the search results.

### Searching Pattern Constraints

This program supports the following regex patterns:
- `.` (dot): Matches any single character except a newline.
- `*`: Matches zero or more occurrences of the preceding character or group.
- `+`: Matches one or more occurrences of the preceding character or group.
- `?`: Matches zero or one occurrence of the preceding character or group.

**At a time, you can use only one special regex character.**

For example, `cre*k` is valid. `c.e*k` is not valid within this program, as it contains both `.` and `*` in the same pattern.
"""
