from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return {
        "service": "api-gateway",
        "status": "online",
        "message": "Gateway funcionando"
    }

@app.route("/health")
def health():
    return {"status": "ok"}

@app.route("/services")
def services():
    return {
        "services": [
            "auth-service",
            "task-service",
            "notification-service"
        ]
    }

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)