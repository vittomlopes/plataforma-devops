\# Sprint 3 - Deploy e Observabilidade



\## Objetivo



Melhorar a parte DevOps do projeto com documentação, health checks, logs simples e preparação para deploy com Docker.



\## O que foi feito



\- Projeto implementado em linguagem C.

\- Microsserviços separados.

\- Dockerfile em cada serviço.

\- docker-compose.yml para organizar os containers.

\- GitHub Actions configurado.

\- Pipeline CI compilando todos os serviços com GCC.

\- Rotas de health check criadas.



\## Serviços



| Serviço | Porta | Função |

|---|---:|---|

| gateway | 5000 | Entrada principal |

| auth-service | 5001 | Login/autenticação |

| task-service | 5002 | Tarefas |

| notification-service | 5003 | Notificações |



\## Rotas



\### Gateway

\- GET /

\- GET /health

\- GET /services



\### Auth Service

\- GET /

\- GET /login

\- GET /health



\### Task Service

\- GET /

\- GET /tasks

\- GET /health



\### Notification Service

\- GET /

\- GET /notifications

\- GET /health



\## Observabilidade



A observabilidade foi feita com health checks e logs simples no terminal.



Cada serviço mostra uma mensagem quando inicia.



Exemplo:



```text

auth-service rodando na porta 5001

task-service rodando na porta 5002

notification-service rodando na porta 5003

api-gateway rodando na porta 5000

