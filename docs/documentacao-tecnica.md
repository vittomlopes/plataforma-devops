\# Documentação Técnica



\## Projeto



Plataforma DevOps com Microsserviços, Observabilidade e Pipeline CI/CD.



\## Objetivo



Construir uma aplicação baseada em microsserviços utilizando práticas DevOps, conteinerização, integração contínua, deploy e observabilidade.



\## Linguagem utilizada



O projeto foi implementado em linguagem C.



Cada serviço possui um arquivo main.c.



Os serviços utilizam sockets HTTP simples para responder requisições REST em formato JSON.



\## Estrutura do projeto



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

│   ├── sprint3.md

│   └── documentacao-tecnica.md

└── README.md

```



\## Serviços implementados



| Serviço              | Porta | Função                         |

| -------------------- | ----: | ------------------------------ |

| gateway              |  5000 | Entrada principal da aplicação |

| auth-service         |  5001 | Serviço de autenticação        |

| task-service         |  5002 | Serviço de tarefas/atividades  |

| notification-service |  5003 | Serviço de notificações        |



\## Rotas



\### Gateway



\* GET /

\* GET /health

\* GET /services

\* GET /metrics



\### Auth Service



\* GET /

\* GET /login

\* GET /health



\### Task Service



\* GET /

\* GET /tasks

\* GET /health



\### Notification Service



\* GET /

\* GET /notifications

\* GET /health



\## Docker



Cada serviço possui um Dockerfile próprio.



O Dockerfile usa a imagem gcc:13, copia o arquivo main.c, compila o código C e executa o programa.



Exemplo:



```dockerfile

FROM gcc:13



WORKDIR /app



COPY main.c .



RUN gcc main.c -o app



EXPOSE 5000



CMD \["./app"]

```



\## Docker Compose



O arquivo docker-compose.yml organiza todos os containers.



Ele define:



\* gateway

\* auth-service

\* task-service

\* notification-service



Cada serviço possui sua porta própria.



\## Pipeline CI



O pipeline CI foi configurado com GitHub Actions.



Arquivo:



```text

.github/workflows/ci.yml

```



O pipeline executa quando ocorre push ou Pull Request na branch main.



Etapas do pipeline:



1\. Baixa o código do repositório.

2\. Verifica o GCC.

3\. Compila auth-service.

4\. Compila task-service.

5\. Compila notification-service.

6\. Compila gateway.



Se todos os serviços compilarem corretamente, o GitHub Actions mostra check verde.



\## Deploy



O deploy foi realizado no Render.



O gateway foi publicado como Web Service usando Docker.



Link do deploy:



```text

https://plataforma-devops.onrender.com

```



\## Observabilidade



A observabilidade foi implementada com:



\* logs no Render

\* health check

\* métricas básicas



\## Health Check



Rota:



```text

/health

```



Resposta esperada:



```json

{"status":"ok"}

```



\## Métricas básicas



Rota:



```text

/metrics

```



Exemplo de resposta:



```text

app\_status 1

app\_requests\_total 43

```



Significado:



\* app\_status 1: serviço online

\* app\_requests\_total: total de requisições recebidas



\## GitHub



O projeto utiliza GitHub para versionamento.



Foram usados:



\* commits

\* branches

\* Pull Request

\* issues

\* milestone

\* GitHub Actions



\## Conclusão



O projeto implementa uma infraestrutura DevOps com microsserviços em C, containers Docker, pipeline CI, deploy no Render, logs, health checks, métricas básicas e documentação técnica.



