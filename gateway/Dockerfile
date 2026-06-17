# Usa uma imagem pronta com compilador GCC para C
FROM gcc:13

# Cria/entra na pasta de trabalho dentro do container
WORKDIR /app

# Copia o arquivo main.c do seu projeto para dentro do container
COPY main.c .

# Compila o código C e cria o programa chamado app
RUN gcc main.c -o app

# Informa que o serviço usa a porta 5000
EXPOSE 5000

# Comando que inicia o programa quando o container rodar
CMD ["./app"]
```
