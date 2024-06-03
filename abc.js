function calc() {
    let a = parseFloat(prompt("Enter first number: "));
    let b = parseFloat(prompt("Enter second number: "));
    let s = prompt("Enter the operation you want to perform: (+, -, *, /, **): ");

    console.log(`First number: ${a}`);
    console.log(`Second number: ${b}`);
    console.log(`Operation: ${s}`);

    switch (s) {
        case '+':
            console.log(`The addition of ${a} and ${b} is ${a + b}`);
            alert(`The addition of ${a} and ${b} is ${a + b}`);
            break;
        case '-':
            console.log(`The subtraction of ${b} from ${a} is ${a - b}`);
            alert(`The subtraction of ${b} from ${a} is ${a - b}`);
            break;
        case '*':
            console.log(`The multiplication of ${a} and ${b} is ${a * b}`);
            alert(`The multiplication of ${a} and ${b} is ${a * b}`);
            break;
        case '/':
            if (b !== 0) {
                console.log(`The division of ${a} by ${b} is ${a / b}`);
                alert(`The division of ${a} by ${b} is ${a / b}`);
            } else {
                console.log("Error: Division by zero is not allowed.");
                alert("Error: Division by zero is not allowed.");
            }
            break;
        case '**':
            console.log(`The exponentiation of ${a} to the power of ${b} is ${a ** b}`);
            alert(`The exponentiation of ${a} to the power of ${b} is ${a ** b}`);
            break;
        default:
            console.log("Invalid operation. Please enter one of the following: +, -, *, /, **.");
            alert("Invalid operation. Please enter one of the following: +, -, *, /, **.");
            break;
    }
}
