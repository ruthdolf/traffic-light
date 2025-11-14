// Get the bulb elements by ID
let yellow = document.getElementById("yellow_id");
let red = document.getElementById("red_id");
let green = document.getElementById("green_id");

// Click red > (green off) > yellow on > yellow off > red on
function click_red() {
    fetch("/red");
    green.classList.remove("green_class");  // turn green off

    if (!red.classList.contains("red_class")) { // if red isn't already on
        fetch("/yellowON");

        setTimeout(() => {
            fetch("/yellowOFF");
            remove_yellow();
        }, 1000);

        setTimeout(() => {
            fetch("/red");
            add_red();
        }, 1100);
    }
}

// Click green > (red off) > yellow on > yellow off > green on
function click_green() {
    red.classList.remove("red_class"); // turn red off

    if (!green.classList.contains("green_class")) { // if green isn't already on
        yellow.classList.add("yellow_class"); 
        fetch("/yellowON");

        setTimeout(() => {
            fetch("/yellowOFF");
            remove_yellow();
        }, 1000);

        setTimeout(() => {
            fetch("/green");
            add_green();
        }, 1100);
    }
}

// Remove yellow class
function remove_yellow() {
    yellow.classList.remove("yellow_class");
}

// Add red class
function add_red() {
    red.classList.add("red_class");
}

// Add green class
function add_green() {
    green.classList.add("green_class");
}

/*
// Optional: yellow blinking function
function yellow_blinking() {
    red.classList.remove("red_class");
    green.classList.remove("green_class");

    while (true) {
        yellow.classList.add("yellow_class"); 
        fetch("/yellowON");

        setTimeout(() => {
            fetch("/yellowOFF");
            remove_yellow();
        }, 500);
    }
}
*/
