#include <iostream>
#include <Poco/Net/Socket.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/SocketStream.h>

int main() {
  // Create a server socket
  Poco::Net::ServerSocket server(8080);

  // Wait for a client to connect
  Poco::Net::Socket client;
  server.accept(client);

  // Create a socket stream for reading and writing
  Poco::Net::SocketStream stream(client);

  // Send a byte array to the client
  const char data[] = { 0x01, 0x02, 0x03, 0x04 };
  stream.write(data, sizeof(data));

  // Receive a byte array from the client
  char buffer[1024];
  stream.read(buffer, 1024);

  // Close the socket
  client.close();
}
