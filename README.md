# 🚀 Plataforma DevOps com Microsserviços

<img src="https://img.shields.io/badge/Linguagem-C-blue">
<img src="https://img.shields.io/badge/Docker-Container-blue">
<img src="https://img.shields.io/badge/GitHub%20Actions-CI-green">
<img src="https://img.shields.io/badge/Deploy-Render-purple">
<img src="https://img.shields.io/badge/Status-Online-success">

---

## 📌 Projeto Final DevOps — Engenharia da Computação

Este projeto tem como objetivo construir uma **plataforma DevOps com microsserviços**, utilizando:

* Linguagem C
* Docker
* Docker Compose
* GitHub Actions
* Deploy no Render
* Health Checks
* Métricas básicas
* Documentação técnica



## 🎯 Objetivo



Criar uma aplicação baseada em microsserviços, aplicando práticas de DevOps, conteinerização, integração contínua, deploy e observabilidade.



---



## 🧱 Arquitetura



O projeto possui os seguintes serviços:



| Serviço              | Porta | Função                         |

| -------------------- | ----: | ------------------------------ |

| API Gateway          |  5000 | Entrada principal da aplicação |

| Auth Service         |  5001 | Serviço de autenticação/login  |

| Task Service         |  5002 | Serviço de tarefas/atividades  |

| Notification Service |  5003 | Serviço de notificações        |



---



## 🔗 Deploy



O gateway foi publicado no Render usando Docker.



🌐 Link do deploy:



```text

https://plataforma-devops.onrender.com

```



Rotas para teste:



```text

https://plataforma-devops.onrender.com

https://plataforma-devops.onrender.com/health

https://plataforma-devops.onrender.com/services

https://plataforma-devops.onrender.com/metrics

```



---



## 📡 Rotas da API



### API Gateway



| Método | Rota      | Descrição         |

| ------ | --------- | ----------------- |

| GET    | /         | Status do gateway |

| GET    | /health   | Health check      |

| GET    | /services | Lista os serviços |

| GET    | /metrics  | Métricas básicas  |



### Auth Service



| Método | Rota    | Descrição          |

| ------ | ------- | ------------------ |

| GET    | /       | Status do serviço  |

| GET    | /login  | Simulação de login |

| GET    | /health | Health check       |



### Task Service



| Método | Rota    | Descrição         |

| ------ | ------- | ----------------- |

| GET    | /       | Status do serviço |

| GET    | /tasks  | Lista de tarefas  |

| GET    | /health | Health check      |



### Notification Service



| Método | Rota           | Descrição             |

| ------ | -------------- | --------------------- |

| GET    | /              | Status do serviço     |

| GET    | /notifications | Lista de notificações |

| GET    | /health        | Health check          |



---



## 📊 Métricas básicas



A rota `/metrics` exibe métricas simples do gateway.



Exemplo:



```text

app\_status 1

app\_requests\_total 43

```



Significado:



| Métrica            | Descrição                      |

| ------------------ | ------------------------------ |

| app\_status 1       | Serviço online                 |

| app\_requests\_total | Total de requisições recebidas |



---



## 🐳 Docker



Cada microsserviço possui um `Dockerfile`.



Exemplo:



```dockerfile

FROM gcc:13



WORKDIR /app



COPY main.c .



RUN gcc main.c -o app



EXPOSE 5000



CMD \["./app"]

```



---



## 🧩 Docker Compose



O arquivo `docker-compose.yml` organiza todos os containers do projeto.



Serviços configurados:



* gateway

* auth-service

* task-service

* notification-service



Para executar com Docker:



```bash

cd infra

docker compose up --build

```



---



## ⚙️ Pipeline CI/CD



O pipeline foi configurado com \*\*GitHub Actions\*\*.



Arquivo:



```text

.github/workflows/ci.yml

```



O pipeline executa automaticamente quando acontece:



* push na branch `main`

* pull request para a branch `main`



Etapas do CI:



1\. Baixar o código do repositório

2\. Verificar o GCC

3\. Compilar auth-service

4\. Compilar task-service

5\. Compilar notification-service

6\. Compilar gateway



Quando tudo compila corretamente, o GitHub Actions mostra check verde.



---



## 📁 Estrutura do Projeto



```text

plataforma-devops/

├── gateway/

│   ├── main.c

│   └── Dockerfile

├── services/

│   ├── auth-service/

│   │   ├── main.c

│   │   └── Dockerfile

│   ├── task-service/

│   │   ├── main.c

│   │   └── Dockerfile

│   └── notification-service/

│       ├── main.c

│       └── Dockerfile

├── infra/

│   └── docker-compose.yml

├── .github/

│   └── workflows/

│       └── ci.yml

├── docs/

│   ├── arquitetura.md

│   ├── modelo-conceitual.md

│   ├── documentacao-tecnica.md

│   └── sprint3.md

└── README.md

```



---



## 📚 Documentação



A documentação técnica está na pasta `docs`.



| Arquivo                 | Descrição                |

| ----------------------- | ------------------------ |

| arquitetura.md          | Documento arquitetural   |

| modelo-conceitual.md    | Modelo conceitual        |

| documentacao-tecnica.md | Documentação técnica     |

| sprint3.md              | Documentação da Sprint 3 |



---



## 🛠️ Tecnologias utilizadas



\* C

\* GCC

\* Docker

\* Docker Compose

\* GitHub

\* GitHub Actions

\* Render



\---



## ✅ Status das Sprints



| Sprint                                          | Status      |

| ----------------------------------------------- | ----------- |

| Sprint 1 — Arquitetura e infraestrutura inicial | ✅ Concluída |

| Sprint 2 — CI e comunicação entre serviços      | ✅ Concluída |

| Sprint 3 — Deploy e observabilidade             | ✅ Concluída |



---



## 👨‍💻 Autor



\*\*João Vitor\*\*



Projeto desenvolvido para a disciplina de Engenharia da Computação.



---



## ✅ Conclusão



O projeto implementa uma infraestrutura DevOps com microsserviços em C, containers Docker, pipeline CI, deploy no Render, logs, health checks, métricas básicas e documentação técnica.



