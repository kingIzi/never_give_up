function loginUser(email,password){
    const login = {
        "email": email,
        "password": password,
        "returnSecureToken": true
    };
    return login
}

function availableUsersList(){
    const users = {
        "status": "ON",
        "role": "ADMIN"
    };
    return users;
}
