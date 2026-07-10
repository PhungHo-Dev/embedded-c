# Chapter 01 - Memory Layout
```
+----------------------+
|      Text Segment    |  Program instructions
+----------------------+
|      Data Segment    |  Initialized global/static variables
+----------------------+
|        BSS           |  Uninitialized global/static variables
+----------------------+
|       Heap           |  Dynamic memory (malloc/free)
|          ↑           |
|                      |
|                      |
|          ↓           |
|       Stack          |  Local variables, function calls
+----------------------+
```
## Objectives

- Understand Stack
- Understand Heap
- Understand Data Section
- Understand BSS
- Learn static variables
- Learn memory addresses

## Exercises

- exercise1.c
global_init    : 0000000000403010
global_uninit  : 0000000000407970
local          : 000000000061FDE4
counter        : 0000000000407030
heap           : 0000000000AE1420
- exercise2.c
- exercise3.c