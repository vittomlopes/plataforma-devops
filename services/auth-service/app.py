from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return {"service": "auth-service", "status": "online"}

@app.route("/login")
def login():
    return {"message": "login simples funcionando"}

@app.route("/health")
def health():
    return {"status": "ok"}

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5001)