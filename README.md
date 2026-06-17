# \# plataforma-devops

# 

# Projeto Final DevOps - Engenharia da Computação

# 

# \## Objetivo

# 

# Criar uma plataforma DevOps com microsserviços, Docker, Docker Compose e pipeline CI usando GitHub Actions.

# 

# \## Arquitetura

# 

# O projeto possui os seguintes serviços:

# 

# \- API Gateway

# \- Auth Service

# \- Task Service

# \- Notification Service

# 

# \## Estrutura

# 

# ```text

# plataforma/

# ├── services/

# │   ├── auth-service/

# │   ├── task-service/

# │   └── notification-service/

# ├── gateway/

# ├── infra/

# │   └── docker-compose.yml

# ├── .github/

# │   └── workflows/

# │       └── ci.yml

└── README.md

# O projeto foi implementado em linguagem C. Cada microsserviço possui main.c e Dockerfile usando GCC. O pipeline CI compila automaticamente todos os serviços com GitHub Actions.

