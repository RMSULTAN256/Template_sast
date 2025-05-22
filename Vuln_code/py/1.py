from flask import Flask, session, redirect, request #type: ignore[import]

app = Flask(__name__)
app.secret_key = 'supersecretkey'

@app.route('/login', methods=['POST'])
def login():
    session['user_id'] = 123
    session.permanent = True  # Permanent session
    app.permanent_session_lifetime = 365 * 24 * 60 * 60  # 1 year
    return redirect('/dashboard')

@app.route('/logout')
def logout():
    # Incorrect: Only removes user_id, session cookie persists
    session.pop('user_id', None)
    return redirect('/login')