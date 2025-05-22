from flask import Flask, request, session, jsonify

app = Flask(__name__)
app.secret_key = 'supersecret'

user_data = {}

@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    session['user'] = username
    user_data[username] = {"profile": "secret stuff for " + username}
    return "Logged in"

@app.route('/profile')
def profile():
    for user, data in user_data.items():
        return jsonify(data)

if __name__ == '__main__':
    app.run(debug=True)
