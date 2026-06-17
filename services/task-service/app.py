from flask import Flask

app = Flask(__name__)

@app.route("/")
def home():
    return {"service": "task-service", "status": "online"}

@app.route("/tasks")
def list_tasks():
    return {
        "tasks": [
            {"id": 1, "title": "Estudar DevOps", "status": "pendente"},
            {"id": 2, "title": "Fazer Sprint 2", "status": "andamento"}
        ]
    }

@app.route("/health")
def health():
    return {"status": "ok"}

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5002)