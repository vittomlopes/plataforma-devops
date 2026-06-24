\# Modelo Conceitual



\## Objetivo



O modelo conceitual representa as principais partes do sistema e como elas se relacionam.



O projeto é uma plataforma DevOps baseada em microsserviços.



\## Entidades principais



\### Usuário



Representa a pessoa que acessa o sistema.



O usuário pode acessar o gateway e utilizar os serviços disponíveis.



\### Gateway



Representa a entrada principal da aplicação.



Ele recebe as requisições e mostra os serviços disponíveis.



\### Auth Service



Representa o serviço de autenticação.



Ele simula a parte de login do sistema.



\### Task Service



Representa o serviço de tarefas e atividades acadêmicas.



No projeto, ele também representa a ideia de assignment-service, pois trabalha com atividades/tarefas.



\### Notification Service



Representa o serviço de notificações.



Ele retorna mensagens de notificação para o usuário.



\## Relação entre os serviços



O usuário acessa o gateway.



O gateway representa a porta de entrada.



Os serviços internos são separados por responsabilidade:



\* auth-service: autenticação

\* task-service: tarefas/atividades

\* notification-service: notificações



\## Diagrama conceitual simples



Usuário

↓

Gateway

↓

Auth Service

Task Service

Notification Service



\## Rotas principais



| Serviço              | Rota           | Função                     |

| -------------------- | -------------- | -------------------------- |

| gateway              | /              | Status do gateway          |

| gateway              | /health        | Verificar saúde do gateway |

| gateway              | /services      | Listar serviços            |

| gateway              | /metrics       | Métricas básicas           |

| auth-service         | /login         | Simular login              |

| task-service         | /tasks         | Listar tarefas             |

| notification-service | /notifications | Listar notificações        |



\## Conclusão



O modelo conceitual mostra que o sistema foi dividido em serviços pequenos e independentes.



Essa divisão melhora a organização, facilita manutenção e ajuda na aplicação de práticas DevOps.



