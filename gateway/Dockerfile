FROM gcc:13

WORKDIR /app

COPY main.c .

RUN gcc main.c -o app

EXPOSE 5000

CMD ["./app"]