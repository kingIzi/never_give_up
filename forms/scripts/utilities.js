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

function getComicFilters(icons){
    let filters = [
            { "model": ["Tout(s)","Romance","Tragedy","Comedy"],"icon":  icons.columnsGap},
            { "model": ["Tout(s)","Disponible","Non-Disponible"],"icon":  icons.bookshelf},
            { "model": ["Plus-Recent","Plus-Ancien"],"icon":  icons.funnel}
        ]
    return filters
}

function calculateListViewTotalHeight(listView,count){
//    var root = listView.visibleChildren[0]
//    var listViewHeight = 0
//    var listViewWidth = 0

//    // iterate over each delegate item to get their sizes
//    for (var i = 0; i < root.visibleChildren.length; i++) {
//        listViewHeight += root.visibleChildren[i].height
//        listViewWidth  = Math.max(listViewWidth, root.visibleChildren[i].width)
//    }

//    listView.height = listViewHeight
//    listView.width = listViewWidth
    console.log(count)
}
