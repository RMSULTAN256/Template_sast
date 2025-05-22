const express = require('express');
const session = require('express-session');
const app = express();

app.use(express.urlencoded({ extended: true }));
app.use(session({
  secret: 'supersecret',
  resave: false,
  saveUninitialized: true,
}));

// ❌ Insecure: Global object to store session-specific data
const userData = {};

app.post('/login', (req, res) => {
  const username = req.body.username;
  req.session.user = username;
  userData[username] = {
    profile: `Secret info for ${username}`
  };
  res.send('Logged in');
});

app.get('/profile', (req, res) => {
  // ❌ Always returns the first user’s data, not the current session’s user
  for (const user in userData) {
    return res.json(userData[user]);
  }
});

app.listen(3000, () => {
  console.log('Server running at http://localhost:3000');
});
