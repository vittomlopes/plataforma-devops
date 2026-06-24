\# Documento Arquitetural



\## Projeto



Plataforma DevOps com Microsserviços, Observabilidade e Pipeline CI/CD.



\## Objetivo



O objetivo do projeto é construir uma aplicação baseada em microsserviços, utilizando práticas de DevOps, Docker, GitHub Actions, deploy e observabilidade.



\## Arquitetura Geral



O sistema foi dividido em serviços independentes.



Cada serviço possui uma responsabilidade própria e pode ser executado em container Docker.



\## Serviços



| Serviço              | Função                                   | Porta |

| -------------------- | ---------------------------------------- | ----: |

| gateway              | Entrada principal da aplicação           |  5000 |

| auth-service         | Serviço de autenticação/login            |  5001 |

| task-service         | Serviço de tarefas/atividades acadêmicas |  5002 |

| notification-service | Serviço de notificações                  |  5003 |



\## Observação sobre os serviços esperados



No documento do projeto aparecem os serviços academic-service e assignment-service.



Neste projeto, o task-service representa a parte de assignment-service, pois trabalha com tarefas e atividades acadêmicas.



O notification-service foi implementado mesmo sendo opcional, para deixar a arquitetura mais completa.



\## Fluxo da aplicação



Usuário ou navegador acessa o gateway.



O gateway responde as rotas principais e mostra os serviços disponíveis.



Os microsserviços possuem rotas próprias e retornam respostas em JSON.



\## Diagrama simples



Usuário / Navegador

↓

API Gateway

↓

auth-service

task-service

notification-service



\## Tecnologias utilizadas



\* Linguagem C

\* GCC

\* Docker

\* Docker Compose

\* GitHub Actions

\* GitHub

\* Render



\## Justificativa da arquitetura



A arquitetura foi organizada em microsserviços para separar responsabilidades.



Essa separação facilita manutenção, testes, deploy e evolução do sistema.



Cada serviço possui seu próprio Dockerfile, permitindo execução independente em containers.



