# Web Browser History Manager using Stack

## Problem Statement
Write a C program that simulates the Back-button behavior of a web browser using a stack implemented with an array. The browser remembers at most 5 visited pages (MAX = 5). Each page is identified by an integer webpage ID. The program provides a menu-driven interface with the following operations:

1. **Visit New Page (Push):** Accepts a webpage ID and pushes it onto the history stack. If the stack already holds 5 pages, a stack overflow error is displayed.
2. **Click Back Button (Pop):** Removes the most recently visited page and shows which page the user is now on. If the stack is empty, a stack underflow error is displayed. If the last page is removed, the history is reported as empty.
3. **Show History Stack:** Displays all stored pages from the most recent (top) to the oldest (bottom). If the stack is empty, an appropriate message is displayed.
4. **Exit:** Terminates the program.

Any other menu choice produces an "Invalid choice" message, and the menu repeats until the user chooses Exit.

## Description
This program models how a web browser's Back button works using the **stack** data structure. Since the most recently visited page is the first one you return to when you press Back, a stack's Last-In-First-Out (LIFO) behavior is a natural fit.

**How it works:**

- **Storage:** An integer array `history[MAX]` holds the webpage IDs, and a global variable `top` tracks the position of the most recent page. `top = -1` means the stack is empty.
- **Visit page (push):** Checks for overflow (`top == MAX - 1`). If there is room, it increments `top` and stores the new page ID at that position.
- **Back button (pop):** Checks for underflow (`top == -1`). If history exists, it reports the page being left, decrements `top`, and shows the page the user lands on, or says history is empty if none remain.
- **Display history:** A loop runs from `top` down to `0`, printing pages from newest to oldest.
- **Menu loop:** `main()` uses a `do-while` loop with a `switch` statement to call the right function until the user enters 4. Invalid choices are caught by the `default` case.

**Key points:**

- Popping does not erase the data in the array; it only moves `top` down, and the old value is overwritten by the next push.
- All operations run in O(1) time, except display, which is O(n).
- Limitations: fixed stack size of 5, no forward-button support, and no input validation for non-numeric entries.

## How to Compile and Run
```
gcc browser_history.c -o browser_history
./browser_history
```

## Sample Output
```
=== WEB BROWSER HISTORY MENU ===
1. Visit New Page (Push)
2. Click Back Button (Pop)
3. Show History Stack
4. Exit
Enter your choice: 1
Enter webpage ID (e.g., 101, 102): 101
Successfully visited Page 101

Enter your choice: 1
Enter webpage ID (e.g., 101, 102): 102
Successfully visited Page 102

Enter your choice: 1
Enter webpage ID (e.g., 101, 102): 103
Successfully visited Page 103

Enter your choice: 3

--- Browser History (Top to Bottom) ---
-> Page 103
-> Page 102
-> Page 101
---------------------------------------

Enter your choice: 2

Going back from Page 103
Current page is now: Page 102

Enter your choice: 2

Going back from Page 102
Current page is now: Page 101

Enter your choice: 2

Going back from Page 101
History is now empty.

Enter your choice: 2

[Error] No previous history! You are at the start.

Enter your choice: 4

Closing browser...
```


