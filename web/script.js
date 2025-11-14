    //variableName = document.getElementById("idName") means search the entire document for any elements with the id "idName"
    //variableName.classList.action("className") means the class "className" is being removed, added etc. from the class list of any elements with the id "idName"
    let yellow = document.getElementById("yellow_id");
    let red = document.getElementById("red_id");
    let green = document.getElementById("green_id");

    //click red > (green off) > yellow on > yellow off > red on
    function click_red(){
        fetch("/red")
        green.classList.remove("green_class");  //remove "green_class" from the class list of any elements with the id "green_id"
        if (!red.classList.contains("red_class")) //if red isn't already on
        {
            yellow.classList.add("yellow_class"); 
            setTimeout(remove_yellow, 1000);
            setTimeout(add_red, 1100);  
        }
    }

    //click green > (red off) > yellow on > yellow off > green on
    function click_green() {
        fetch("/green")

        red.classList.remove("red_class");
        if (!green.classList.contains("green_class")) //if green isn't already on
        {
            yellow.classList.add("yellow_class"); 
            setTimeout(remove_yellow, 1000);
            setTimeout(add_green, 1100);
        }
    }

    function remove_yellow (){yellow.classList.remove("yellow_class");}
    function add_red() {red.classList.add("red_class");}  //fetch()
    function add_green() {green.classList.add("green_class");}
  


//yellow blinking function (not completed)
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
