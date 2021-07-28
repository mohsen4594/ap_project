


ap_project : server.o client.o 

server.o : server.cpp httplib.h
	
	g++ -std=c++11 -o server server.cpp -lpthread -I.
	
client.o : client.cpp httplib.h

	g++ -std=c++11 -o client client.cpp -lpthread -I.
	
clean:
	rm server client 
 
