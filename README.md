# Push Swap

## Description
Push Swap is a project that involves sorting stacks of integers using two stacks and a limited set of instructions. The goal is to sort the stack in ascending order with the minimum number of operations.

## Files

- **Makefile**: Makefile for compiling the Push Swap project.
- **push.h**: Header file containing function prototypes and constants.
- **src/**: Directory containing source code files.

## Compilation

To compile the Push Swap project, navigate to the root directory and run:
```sh
make
```

This will compile the executable push_swap.

## Usage
## Running Push Swap

To sort a list of integers using Push Swap, run the following command:

```sh
./push_swap 4 67 2 8 12
```

Replace 4 67 2 8 12 with the list of integers you want to sort. Push Swap will output a series of instructions to stdout that sorts the integers.

## Checking Sorted Order

You can also use the push_swap executable with the checker utility to verify if a series of instructions correctly sorts the integers. For example:

```sh
ARG="4 67 2 8 12"; ./push_swap $ARG | ./checker $ARG
```

This will output OK if the instructions correctly sort the integers or KO if they do not.

## Example
## Compilation and Execution Example

```sh
make
./push_swap 4 67 2 8 12
```

This will output the instructions to sort the integers [4 67 2 8 12].

## Contributors
[pschemit](https://github.com/pschemit)
