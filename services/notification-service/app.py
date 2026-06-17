from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return {"service": "notification-service", "status": "online"}

@app.route("/notifications")
def list_notifications():
    return {
        "notifications": [
            {"id": 1, "message": "Nova atividade criada"},
            {"id": 2, "message": "Prazo de entrega próximo"}
        ]
    }

@app.route("/health")
def health():
    return {"status": "ok"}

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5003)