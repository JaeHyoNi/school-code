function displayNEWS() {
    console.log(document.getElementById("searching").innerHTML);
    var xhr = new XMLHttpRequest();
    xhr.withCredentials = true;
    xhr.addEventListener("readystatechange", function () {
        if (this.readyState === 4) {
            console.log(this.responseText);
            let storage = JSON.parse(this.response);
            $('#news').empty();
            let tagArea = document.getElementById("news");
            for (i in storage.items) {
                let temp = document.createElement('div');
                temp.setAttribute('class', 'article');
                let title = document.createElement('h3');
                let discription = document.createElement('p');
                discription.setAttribute('title','des');
                let link = document.createElement('a');
                discription.innerHTML = storage.items[i].description;
                title.innerHTML = storage.items[i].title;
                link.setAttribute('href', storage.items[i].link);
                link.innerHTML = "기사로 바로가기 ><";
                temp.appendChild(title);
                temp.appendChild(discription);
                temp.appendChild(link);
                tagArea.appendChild(temp);
            }
        }
    });
    url = "http://localhost:3000/news/" + document.getElementById('searching').value + "/" + document.getElementById('num').value;
    xhr.open("GET", url);
    xhr.send();
}


function getcoin() {
    var xhr = new XMLHttpRequest();
    xhr.withCredentials = true;

    xhr.addEventListener("readystatechange", function () {
        if (this.readyState === 4) {
            console.log(this.responseText);
            let storage = JSON.parse(this.response);
            $('#coins').empty();
            let target = document.getElementById('coins');
            for (i in storage) {
                let temp = document.createElement('p');
                temp.innerHTML = storage[i].korean_name;
                target.appendChild(temp);
            }
        }
    });

    xhr.open("GET", "http://localhost:3000/coinmenu");
    xhr.send();
}

function set_coin() {
    coinList = document.getElementsByName('coin');
    coinList.forEach(node => {
        if (node.checked) {
            document.getElementById('choose').innerText = node.value;
        }
    });
}

function openresult() {
    var xhr = new XMLHttpRequest();
    xhr.withCredentials = true;
    xhr.addEventListener("readystatechange", function () {
        if (this.readyState === 4) {
            console.log(this.responseText);
            let storage = JSON.parse(this.response);
            $('#coinresult').empty();
            let target = document.getElementById('coinresult');
            let temp = document.createElement('h1');
            let comment = "어제 마감가격 : " + storage[0].prev_closing_price;
            comment = comment + " / 현재가격 : " + storage[0].trade_price;
            let temp2 = document.createElement('h3');
            temp2.innerHTML = comment;
            target.appendChild(temp2);
            if (storage[0].prev_closing_price < storage[0].trade_price) {
                var audio = new Audio('good.MP3');
                audio.play();
                temp.innerHTML = "축하해요! 올랐습니다!!!!";
            }
            else {
                var audio = new Audio('bad.MP3');
                audio.play();
                temp.innerHTML = "적금이나 드세요 ㅋㅋ";
            }
            target.appendChild(temp);
        }
    });
    var chose;
    coinList = document.getElementsByName('coin');
    coinList.forEach(node => {
        if (node.checked) {
            chose = node.value;
        }
    });

    xhr.open("GET", "http://localhost:3000/coinprice/" + chose);
    xhr.send();
}

function setpic() {
    document.getElementById('here').setAttribute('src', "https://apimeme.com/meme?meme=" +
        document.getElementById('meme').value + "&top=" +
        document.getElementById('top').value + "&bottom=" +
        document.getElementById('bottom').value);
}

function chkCharCode(event) {
    const regExp = /[^0-9a-zA-Z ]/g;
    const ele = event.target;
    if (regExp.test(ele.value)) {
        ele.value = ele.value.replace(regExp, '');
    }
};
function chkintCode(event) {
    const regExp = /[^0-9]/g;
    const ele = event.target;
    if (regExp.test(ele.value)) {
        ele.value = ele.value.replace(regExp, '');
    }
};

