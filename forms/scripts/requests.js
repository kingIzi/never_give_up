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

function availableComics(){
    const users = {
        "status": "ON",
    };
    return users;
}

function createAddComicForm(form){
    const comic = {
        "name": form.name,
        "categories": form.categories,
        "authorId": form.authorId,
        "dateReleased": form.dateReleased,
        "thumbnailFile": form.thumbnailFile,
        "data": form.comicFile,
        "description": form.description
    };
    return comic
}

function availableCategories(){
    const categories = {
        "status": "ON",
    };
    return categories;
}


function availableAuthors(){
    const authors = {
        "status": "ON",
    };
    return authors;
}
