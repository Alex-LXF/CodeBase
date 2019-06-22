all:server client
server:TCPServer.c
	gcc TCPServer.c -o server -lpthread 
client:TCPClient.c
	gcc TCPClient.c -o client -lpthread

.PHONY:clean 
clean:
	rm -r server client
