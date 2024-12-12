# Lion Programming Language Specification

### Table of Contents
1. [Overview](#overview)
2. [Features](#features)
3. [Lexical Structure](#lexical-structure)
4. [Grammar Rules](#grammar-rules)
5. [Semantic Analysis](#semantic-analysis)
6. [Code Generation (LLVM)](#code-generation-llvm)
7. [Testing Strategy](#testing-strategy)
8. [Timeline](#timeline)
9. [Future Features](#future-features)

## Overview

### Language Goals
The Lion programming language is an experimental educational project designed to deepen my understanding of language design and implementation. While primarily aimed at learning, Lion seeks to achieve realistic and ambitious goals. I aspire for Lion to be highly expressive, allowing various features to be utilized as part of expressions. While simplicity is not a primary focus, I aim to explore innovative and potentially complex features that challenge conventional programming paradigms.

## Features

### Variables
``` 
// this is a comment
let x = 10
let y = x // x is copied to y

let message = "Hello, World"
```

### Data Types
``` 
// Integers
let x: u32 = 10
let y: i32 = 20

// Strings
let message: string
message = "Hello, World!"

// Booleans
let condition: bool // defaults to false
condition = true 
```

### Control Flow

#### If-statements
``` 
if condition {
    // ...
} else if x > 10 {
    // ...
} else {
    // ...
}
```

### Operations
``` 
// Arithmetic
+ - * /

// Comparison
== != > < >= <=

// Logical
&& || !
```

### Input/Output
``` 
print("Hello, World")

let message = input("I will echo: ")
print(message)
```

## Lexical Structure

### Keywords
``` 
let
if 
else 
print
input
```

### Identifiers
All identifiers must start with a letter. Identifiers are alphanumeric. There is no limit in length.

## Semantic Analysis

### Type checking rules
- Ensure variables are declared before use.
- Check that operations are valid for the given types (e.g., not adding a string to an integer).

### Scope resolution for variable access
- Maintain a symbol table to track variable declarations and their scopes.

### Validations for expressions and control flow constructs
- Ensure that condition expressions in if-statements are boolean.
- Validate that all blocks are properly defined and closed.

## Code Generation (LLVM)

### Variable declaration (example)
```asm 
%1 = alloca i32 ; Allocating space for an integer variable
store i32 10, i32* %1 ; Storing value in the allocated space
```

### If statement (example)
```asm 
%cond = load i1, i1* %condition ; Load the condition
br i1 %cond, label %then, label %else ; Conditional branch

then:
; (code for then branch)
br label %end

else:
; (code for else branch)
br label %end

end:
```

### Number guessing game (example)
Lion:
```
let target = 7
let guess: i32

print("Guess the number between 1 and 10:")
guess = input("Your guess: ")

if guess == target {
    print("Congratulations! You guessed correctly.")
} else {
    print("Try again!")
}

```
LLVM IR:
```asm 
; Define the entry point for the program
define i32 @main() {
entry:
    ; Allocate space for variables
    %target = alloca i32
    %guess = alloca i32
    %str1 = call i8* @strdup(i8* getelementptr([31 x i8], [31 x i8]* @.str.1, i32 0, i32 0)) ; "Guess the number between 1 and 10:"
    %str2 = call i8* @strdup(i8* getelementptr([25 x i8], [25 x i8]* @.str.2, i32 0, i32 0)) ; "Your guess: "
    %str3 = call i8* @strdup(i8* getelementptr([38 x i8], [38 x i8]* @.str.3, i32 0, i32 0)) ; "Congratulations! You guessed correctly."
    %str4 = call i8* @strdup(i8* getelementptr([16 x i8], [16 x i8]* @.str.4, i32 0, i32 0)) ; "Try again!"

    ; Initialize target variable
    store i32 7, i32* %target

    ; Print the prompt for the user
    call void @print(i8* %str1)

    ; Read user input and store it in guess
    %input_value = call i32 @input(i8* %str2)
    store i32 %input_value, i32* %guess

    ; Load the values for comparison
    %guess_value = load i32, i32* %guess
    %target_value = load i32, i32* %target

    ; Compare guess and target
    %cmp = icmp eq i32 %guess_value, %target_value
    br i1 %cmp, label %correct, label %incorrect

correct:
    ; Print the correct guess message
    call void @print(i8* %str3)
    br label %end

incorrect:
    ; Print the incorrect guess message
    call void @print(i8* %str4)
    br label %end

end:
    ret i32 0 ; Return from the main function
}

; External functions for I/O operations
declare void @print(i8*)
declare i32 @input(i8*)

; String constants
@.str.1 = private unnamed_addr constant [31 x i8] c"Guess the number between 1 and 10:\00"
@.str.2 = private unnamed_addr constant [25 x i8] c"Your guess: \00"
@.str.3 = private unnamed_addr constant [38 x i8] c"Congratulations! You guessed correctly.\00"
@.str.4 = private unnamed_addr constant [16 x i8] c"Try again!\00"

```

## Testing Strategy
- Develop unit tests for each feature, focusing on the lexer, parser, semantic analysis, and code generation.
- Create integration tests that cover the full compilation process from source code to LLVM IR.

## Timeline
- [ ] Complete Lexer and Parser
- [ ] Complete Semantic Analysis
- [ ] Complete LLVM Code Generation

## Future Features
- Functions
- Lists
- Error handling
- Structs
- Enums