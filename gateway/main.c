#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 5000

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

int main() {
    int server_fd, client;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[3000];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 10);

    printf("api-gateway rodando na porta %d\n", PORT);

    while (1) {
        client = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        read(client, buffer, sizeof(buffer));

        if (strstr(buffer, "GET /health")) {
            send_response(client, "{\"status\":\"ok\"}");
        } else if (strstr(buffer, "GET /services")) {
            send_response(client, "{\"services\":[\"auth-service\",\"task-service\",\"notification-service\"]}");
        } else {
            send_response(client, "{\"service\":\"api-gateway\",\"status\":\"online\",\"message\":\"Gateway funcionando em C\"}");
        }

        close(client);
    }

    return 0;
}