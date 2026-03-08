function Login(params) {
    let user = document.getElementById("Username").value;
    let pass = document.getElementById("Password").value;


    if (user === "Farhan" && pass === "12345") 
    {
        document.getElementById("message").innerText = "Login Successsful";
    }
    else
    {
        document.getElementById("message").innerText = "invalid Login.";
    }
}