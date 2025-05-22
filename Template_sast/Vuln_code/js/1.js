const express = require('express');
const session = require('express-session');
const app = express();

app.use(session({
  secret: 'supersecret',
  resave: false,
  saveUninitialized: true,
  cookie: { maxAge: 365 * 24 * 60 * 60 * 1000 } // 1 year
}));

app.post('/login', (req, res) => {
  req.session.userId = 123;
  res.redirect('/dashboard');
});

app.get('/logout', (req, res) => {
  // Incorrect: Only destroys session, cookie persists
  req.session.destroy();
  res.redirect('/login');
});

app.listen(3000);