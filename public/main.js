window.onbeforeunload = function() {
    navigator.sendBeacon('/shutdown');
};

async function getData(callback){
    const response = await fetch("/data");
    const txt = await response.text();

    const data = txt.split('\n').map(item => item.split(';'));
    data.pop();
    callback(data);
}

getData(data => {
    for(let row of data){
        console.log(row);
    }
});