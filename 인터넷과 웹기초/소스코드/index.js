const express = require('express')
const req = require('express/lib/request')
const app = express()
const port = 3000

app.use(express.static('public'))


app.get('/', (req, res) => res.send('Hello world! 재현!'))


app.get('/news/:target/:num', function (req, res) {
    var request = require('request');
    var options = {
        'url': encodeURI('https://openapi.naver.com/v1/search/news.json?query='
            + req.params.target + '&display=' + req.params.num),
        'headers': {
            'X-Naver-Client-Id': 'aJ3xkRZngumFQHAxp8zF',
            'X-Naver-Client-Secret': 'f7K_TLW4w1'
        }
    };
    request(options, function (error, response) {
        if (error) throw new Error(error);
        res.send(response.body);
    });

})

app.get('/coinmenu', function (req, res) {
    var request = require('request');
    var options = {
        'method': 'GET',
        'url': 'https://api.upbit.com/v1/market/all',
        'headers': {
        }
    };
    request(options, function (error, response) {
        if (error) throw new Error(error);
        console.log(response.body);
        res.send(response.body);
    });
})

app.get('/coinprice/:what', function (req, res) {
    var request = require('request');
    var options = {
        'method': 'GET',
        'url': 'https://api.upbit.com/v1/ticker?markets=' + req.params.what,
        'headers': {
        }
    };
    request(options, function (error, response) {
        if (error) throw new Error(error);
        console.log(response.body);
        res.send(response.body)
    });

})


app.listen(port, () => console.log(`Example app listening at http://localhost:${port}`))

