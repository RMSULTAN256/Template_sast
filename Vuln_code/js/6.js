const express = require('express');
const app = express();

let user_id = null;

app.get('/set-user', (req, res) => {
    user_id = req.query.user_id;
    res.send(`Set user_id to ${user_id}`);
});

app.get('/get-user', (req, res) => {
    res.send(`Current user_id: ${user_id}`);
});

app.listen(3000, () => console.log('Server running on port 3000'));