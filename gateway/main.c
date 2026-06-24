// Biblioteca para usar printf
#include <stdio.h>

// Biblioteca para trabalhar com texto/string
#include <string.h>

// Biblioteca para usar read, write e close no Linux
#include <unistd.h>

// Biblioteca para criar servidor de rede/socket
#include <netinet/in.h>

// Biblioteca para ler variável de ambiente PORT
#include <stdlib.h>

// Porta padrão quando não tiver PORT do deploy
#define DEFAULT_PORT 5000

// Contador simples de requisições
int total_requests = 0;

// Função para enviar resposta HTTP em formato JSON
void send_response(int client, const char *body) {
    char response[2048];

    sprintf(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Content-Length: %lu\r\n"
        "\r\n"
        "%s",
        strlen(body), body);

    write(client, response, strlen(response));
}

// Função para enviar métricas em texto
void send_metrics(int client) {
    char body[512];
    char response[1024];

    sprintf(body,
        "app_status 1\n"
        "app_requests_total %d\n",
        total_requests);

    sprintf(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: %lu\r\n"
        "\r\n"
        "%s",
        strlen(body), body);

    write(client, response, strlen(response));
}

int main() {
    char *port_env = getenv("PORT");
    int port = port_env ? atoi(port_env) : DEFAULT_PORT;

    int server_fd, client;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[3000];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 10);

    printf("api-gateway rodando na porta %d\n", port);

    while (1) {
        client = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        read(client, buffer, sizeof(buffer));

        total_requests++;

        if (strstr(buffer, "GET /health")) {
            send_response(client, "{\"status\":\"ok\"}");

        } else if (strstr(buffer, "GET /services")) {
            send_response(client, "{\"services\":[\"auth-service\",\"task-service\",\"notification-service\"]}");

        } else if (strstr(buffer, "GET /metrics")) {
            send_metrics(client);

        } else {
            send_response(client, "{\"service\":\"api-gateway\",\"status\":\"online\",\"message\":\"Gateway funcionando em C\"}");
        }

        close(client);
    }

    return 0;
}