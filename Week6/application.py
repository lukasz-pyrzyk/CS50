from flask import Flask
from datetime import datetime
from pytz import timezone

app = Flask(__name__)

@app.route("/")
def index():
    return "Home page!"

@app.route("/sample")
def sample():
    return "Sample page!"

@app.route("/time")
def time():
    now = datetime.now(timezone('America/New_York'))
    return f"The current date and time in Cabridge is {now}"

@app.route("/show/<number>")
def show(number):
    return f"You passed {number}"

@app.route("/login", methods=['GET', "POST"])
def login():
    if not request.form.get("username"):
        return "not allowed!"