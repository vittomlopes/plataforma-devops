
#include <stdio.h>
// Biblioteca para trabalhar com textos
#include <string.h>

// Biblioteca para usar read, write e close no Linux
#include <unistd.h>

// Biblioteca para criar servidor de rede/socket
#include <netinet/in.h>

// Porta do auth-service
#define PORT 5001

// Função para enviar resposta HTTP em JSON
void send_response(int client, const char *body) {
    // Guarda a resposta que será enviada
    char response[1024];

    // Monta a resposta HTTP
    sprintf(response,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: application/json\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Content-Length: %lu\r\n"
        "\r\n"
        "%s",
        strlen(body), body);

    // Envia a resposta para o cliente/navegador
    write(client, response, strlen(response));
}

// Função principal
int main() {
    // server_fd = servidor
    // client = navegador/cliente que acessa
    int server_fd, client;

    // Guarda endereço e porta do servidor
    struct sockaddr_in address;

    // Tamanho do endereço
    int addrlen = sizeof(address);

    // Guarda o pedido recebido do navegador
    char buffer[3000];

    // Cria o socket do servidor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Usa internet IPv4
    address.sin_family = AF_INET;

    // Aceita conexão de qualquer endereço
    address.sin_addr.s_addr = INADDR_ANY;

    // Define a porta 5001
    address.sin_port = htons(PORT);

    // Liga o servidor na porta 5001
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Deixa o servidor esperando conexões
    listen(server_fd, 10);

    // Mostra mensagem no terminal
    printf("auth-service rodando na porta %d\n", PORT);

    // Loop infinito para o servidor continuar rodando
    while (1) {
        // Aceita conexão de um cliente
        client = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

        // Lê o pedido do cliente
        read(client, buffer, sizeof(buffer));

        // Se acessar /login, responde login funcionando
        if (strstr(buffer, "GET /login")) {
            send_response(client, "{\"message\":\"login simples funcionando\"}");

        // Se acessar /health, responde status ok
        } else if (strstr(buffer, "GET /health")) {
            send_response(client, "{\"status\":\"ok\"}");

        // Se acessar outra rota, responde que o serviço está online
        } else {
            send_response(client, "{\"service\":\"auth-service\",\"status\":\"online\"}");
        }

        // Fecha a conexão com o cliente
        close(client);
    }

    // Finaliza o programa
    return 0;
}

