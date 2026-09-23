function add(a, b) {
    return a + b;
}

function testAdd() {
    const result = add(2, 3);

    if (result === 5) {
        console.log("Test Passed");
    } else {
        console.log("Test Failed");
    }
}

testAdd();