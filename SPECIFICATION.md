# Lion Language Specification

## Complete Example
Below is a complete example showcasing all the features of Lion:
```go 
import datetime from std

let x int = 10
let y = 10 * x

func Add(a int, b int) -> a + b
Add(x, y)

type Integer = i8 | i16 | i32 | i64
type Number = Integer | float | double
type RGB = (i8, i8, i8)

func Number::+(Number a, b) -> Number {
    return a + b
} 

@autoconstruct // Automatically create a constructor for public variables
type Player = Class{
    let username string
    let age i32
}

func Player::Say(msg String) {
    println!("[{self.username] {msg}")
}

func Player::[abc]+() {
    print!("No function with that name")
}

let john = Player("John", 23)
john.say("Hello!") // [john] Hello!
john.abcabcabc() // No function with that name

```