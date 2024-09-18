# Lion Language Specification
The lion language is a statically typed, compiled language with a syntax similar to Rust and a feature set inspired by Rust, C++, and Python. 
The language is designed to be simple and easy to use while still being powerful and expressive. 
The language is designed to be compiled to machine code and run on any platform.

## Table of Contents
- [Language Concepts](#language-concepts)
  - [Comments](#comments)
  - [Variables and Constants](#variables-and-constants)
  - [Functions](#functions)
  - [If Statements](#if-statements)
  - [Loops](#loops)
  - [Structs](#structs)
  - [Enums](#enums)
- [Syntactical differences](#syntax-differences-to-similar-languages)
- [Complete Example](#complete-example)

## Language Concepts

### Comments
Comments in Lion are similar to comments in C++ and Rust.
```rust
// This is a single line comment
/* This is a multi-line comment */

/// This is a documentation comment

/**
 * This is a multi-line documentation comment
 */
```

### Variables and Constants
Variables in Lion are declared using the `let` keyword.
```rust
let x = 5 // x is an i32 (type inference)
let y: i64 = 10 // y is an i64
let z: f64 = 3.14 // z is an f64

const PI: f64 = 3.14; // PI is a constant
```

Primitive types in Lion:
- `i8`, `i16`, `i32`, `i64`: signed integers
- `u8`, `u16`, `u32`, `u64`: unsigned integers
- `f32`, `f64`: floating point numbers
- `bool`: boolean

### Functions
Functions in Lion are declared using the `func` keyword.
```rust
// Standard function
func add(x: i32, y: i32) -> i32 {
    return x + y
}

let result = add(5, 10);

// Shorthand
func sub(x, y: i32) -> i32 = x - y;
```

### If Statements
If statements in Lion are similar to if statements in C++ and Rust.
```rust
if x > 5 {
    print("x is greater than 5")
} else if x < 5 {
    print("x is less than 5")
} else {
    print("x is equal to 5")
}

// If statement as an expression
let result = if x > 5 {
    "greater"
} else {
    "less or equal"
}

// If statement shorthand 
let result = "greater" if x > 5 else "less or equal"
```

### Loops
Loops in Lion are similar to loops in C++, Rust, and Python.
```rust
// While loop
let x = 0
while x < 10 {
    print(x)
    x += 1
}

// For loop
// 0..10 is a range from 0 to 10 (exclusive)
for i in 0..10 {
    print(i)
}

// Specifying the type of i
for i: i32 in 0..10 {
    print(i)
}
```

### Structs
```rust
struct Point {
    x, y: i32
}

let p = Point { x: 5, y: 10 }

// Accessing fields
print(p.x)
print(p.y)
```

### Enums
```rust
enum Direction {
    Up, Down, Left, Right
}

let d = Direction::Up
```

## Syntax differences to similar languages
While the syntax of Lion is similar to Rust, there are some differences.
- The `let` keyword is used for mutable variables and constants.
- The `func` keyword is used for functions.
- Garbage collection is used for memory management.

## Complete Example
```rust
func main() {
    let x = 5
    let y = 10
    let z = add(x, y)
    print(z)
}

func add(x, y: i32) -> i32 = x + y
```