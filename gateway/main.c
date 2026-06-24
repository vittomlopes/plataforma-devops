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

// Função para enviar resposta HTTP em formato JSON
void send_response(int client, const char *body) {
    // Cria espaço para montar a resposta
    char response[2048];

    // Monta a resposta HTTP
    sprintf(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Content-Length: %lu\r\n"
        "\r\n"
        "%s",
        strlen(body), body);

    // Envia a resposta para o navegador/cliente
    write(client, response, strlen(response));
}

// Função principal do programa
int main() {
    // Lê a porta enviada pelo deploy, exemplo Render/Railway
    char *port_env = getenv("PORT");

    // Se tiver PORT, usa PORT. Se não tiver, usa 5000
    int port = port_env ? atoi(port_env) : DEFAULT_PORT;

    // server_fd = servidor
    // client = pessoa/navegador que acessou
    int server_fd, client;

    // Guarda informações do endereço e porta
    struct sockaddr_in address;

    // Tamanho do endereço
    int addrlen = sizeof(address);

    // Guarda o pedido recebido do navegador
    char buffer[3000];

    // Cria o socket, que é a comunicação pela rede
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Define que vai usar internet IPv4
    address.sin_family = AF_INET;

    // Aceita conexão de qualquer endereço
    address.sin_addr.s_addr = INADDR_ANY;

    // Define a porta do servidor
    address.sin_port = htons(port);

    // Liga o servidor na porta
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Deixa o servidor esperando conexões
    listen(server_fd, 10);

    // Mostra mensagem no terminal
    printf("api-gateway rodando na porta %d\n", port);

    // Loop infinito: servidor fica rodando sempre
    while (1) {
        // Aceita uma conexão de cliente
        client = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

        // Lê o pedido do cliente
        read(client, buffer, sizeof(buffer));

        // Se acessar /health, responde status ok
        if (strstr(buffer, "GET /health")) {
            send_response(client, "{\"status\":\"ok\"}");

        // Se acessar /services, mostra os serviços
        } else if (strstr(buffer, "GET /services")) {
            send_response(client, "{\"services\":[\"auth-service\",\"task-service\",\"notification-service\"]}");

        // Se acessar qualquer outra rota, mostra que o gateway está online
        } else {
            send_response(client, "{\"service\":\"api-gateway\",\"status\":\"online\",\"message\":\"Gateway funcionando em C\"}");
        }

        // Fecha a conexão com o cliente
        close(client);
    }

    // Finaliza o programa
    return 0;
}