> **Note / Not:** This repository is a fork of [Tekin-TEZCAN/push_swap](https://github.com/Tekin-TEZCAN/push_swap), used as the **joint 42 push_swap project** of Berkay Çelik and Tekin Tezcan. The final working version was developed together (branch `berkay4`).
>
> **Work split (per *Team Contributions* below):** Berkay Çelik — medium O(n·√n) chunk sort, simple O(n²) and complex O(n log n) radix sort algorithms, Makefile configuration · Tekin Tezcan — core stack data structures, disorder metric, rules and allowed moves.
>
> My own working branch (parsing/validation, stack operations, error handling, first version of the medium algorithm) is archived in [BerkayCelk/push_swap](https://github.com/BerkayCelk/push_swap).

*This project has been created as part of the 42 curriculum by ttezcan, berkceli*

# Push Swap: Because Swap_push doesn't feel as natural

## Description
The `push_swap` project is an algorithmic exercise designed to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. The core objective is to discover and practically apply algorithmic complexity (Big-O notation) by implementing multiple sorting strategies. 

The program utilizes two stacks (`Stack A` and `Stack B`) and a specific set of operations (`sa`, `pb`, `ra`, `rrr`, etc.) to sort a random list of integers. Instead of relying on a single approach, this implementation features four distinct algorithmic regimes that are dynamically selected based on the calculated "disorder" of the input stack, optimizing for the lowest operation count in the Push_swap constraint model.

## Rules and Allowed Moves

| Command | Description |
| :--- | :--- |
| **`sa`** | **Swap a:**  It swaps the top two elemants of `Stack A` |
| **`sb`** | **Swap b:** It swaps the top two elemants of `Stack B`. |
| **`ss`** | It runs the `sa` and `sb` at the same time. |
| **`pa`** | **Push a:** Takes the topmost element of the `Stack B`and put top of the `Stack A`. |
| **`pb`** | **Push b:** Takes the topmost element of the `Stack A`and put top of the `Stack B`. |
| **`ra`** | **Rotate a:** This moves all elements of `Stack A` one position up. The first element becomes the last element. |
| **`rb`** | **Rotate b:** This moves all elements of `Stack B` one position up. The first element becomes the last element. |
| **`rr`** | It runs `ra` and `rb` at the same time |
| **`rra`**| **Reverse rotate a:** This moves all elements of `Stack A` one position down. The last element becomes the first element. |
| **`rrb`**| **Reverse rotate b:** This moves all elements of `Stack B` one position down. The last element becomes the first element. |
| **`rrr`**| It runs `rra` and `rrb` at the same time. |

### Team Contributions
* **Tekin TEZCAN:** Implementation of the core stack data structures, the Disorder Metric calculator, rules and allowed moves
* **Berkay ÇELİK:** Implementation of the Medium $O(n\sqrt{n})$ Chunk Sort algorithm, the Simple $O(n^2)$ Bubble Sort algorithm, the Complex $O(nlogn)$ Radix Sort algorithm, Makefile configurations.

## Instructions

### Compilation
The project includes a `Makefile` that compiles the source files without unnecessary relinking.
To compile the project, simply run:

```bash
make
````

or 

```bash
make all
````

To clean object files

```bash
make clean
````

To clean object files and push_swap

```bash
make fclean
````

To clean everything and recompile everything

```bash
make re
```

## Execution

Run the program by passing a list of integers as arguments. You can also specify an optional strategy selector flag. If no flag is provided, --adaptive is used by default.

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <list_of_integers>
```

## Resources

- https://www.geeksforgeeks.org/dsa/doubly-linked-list/

- https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s&pp=ygUKcHVzaCBzd2FwIA%3D%3D

- https://visualgo.net/en/sorting

- https://visualgo.net/en/bitmask

- https://visualgo.net/en/list