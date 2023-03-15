function getNavItems(images) {
    let items = [
            {"icon": images.dashboard,"label": "Dashboard"},
            {"icon": images.comicMan,"label": "Comic"},
            {"icon": images.hut,"label": "Author"},
            {"icon": images.admin,"label": "Admin"}
        ]
    return items
}

function getDashboardGeneralReview(){
    let reviews = [
            {"label": "Utilisateur(s)", "percent": 1.5, "total": 233},
            {"label": "Comic(s)", "percent": 2.7, "total": 34},
            {"label": "Author(s)", "percent": -3.5, "total": 18}
        ]
    return reviews
}
