


ap_project : server.o client.o client2.o client3.o client4.o 

server.o : server.cpp httplib.h
	
	g++ -std=c++11 -o server server.cpp -lpthread -I.
	
client.o : client.cpp httplib.h

	g++ -std=c++11 -o client client.cpp -lpthread -I.
	
client2.o : client2.cpp httplib.h

	g++ -std=c++11 -o client2 client2.cpp -lpthread -I.
		
client3.o : client3.cpp httplib.h

	g++ -std=c++11 -o client3 client3.cpp -lpthread -I.
	
client4.o : client4.cpp httplib.h

	g++ -std=c++11 -o client4 client4.cpp -lpthread -I.
	
clean:
	rm server client client2 client3 client4  
 
