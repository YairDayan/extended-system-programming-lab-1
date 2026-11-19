# Lab 1 — Extended System Programming Laboratory

Program memory and pointers, debugging, and simulating object-oriented programming in C.

## Tasks

| Task | Description | Source |
|------|-------------|--------|
| 0 | Fix segmentation fault in `count-words` using a debugger | `count-words.c` |
| 1 | Explore memory addresses, arrays, and pointers | `addresses.c` |
| 2 | Implement `map` and character helpers (`my_get`, `dprt`, `cxprt`, `encrypt`, `decrypt`) | `base.c` |
| 3 | Interactive menu of function descriptors (structs + function pointers) | `task3/menu_map.c` |

## Project layout

```
.
├── count-words.c      # Task 0
├── addresses.c        # Task 1
├── base.c             # Task 2
├── Makefile           # Builds count-words
└── task3/
    ├── makefile       # Builds the menu program
    └── menu_map.c     # Task 3 (includes Task 2 functions)
```

## Build and run

**Task 0 — count-words**

```bash
make
./count-words hello world
```

**Task 1 — addresses**

```bash
gcc -g -Wall -o addresses addresses.c
./addresses arg1 arg2
```

**Task 2 — base (map helpers)**

```bash
gcc -g -Wall -o base base.c
./base
```

**Task 3 — menu**

```bash
cd task3
make
./menu
```

In the menu, choose an option by number. End input with `Ctrl+D` (EOF) to exit.

## Notes

- Compiled with debugging flags (`-g -Wall`). Task 3 uses `-m32` where a 32-bit toolchain is available.
- Task 3 is the Moodle deliverable: folder `task3` with `makefile` and `menu_map.c`.
