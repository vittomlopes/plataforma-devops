
# Usa imagem pronta com GCC para compilar código C
FROM gcc:13

# Define a pasta de trabalho dentro do container
WORKDIR /app

# Copia o arquivo main.c para dentro do container
COPY main.c .

# Compila o main.c e cria o programa chamado app
RUN gcc main.c -o app

# Informa que o auth-service usa a porta 5001
EXPOSE 5001

# Inicia o programa app quando o container rodar
CMD ["./app"]
```
