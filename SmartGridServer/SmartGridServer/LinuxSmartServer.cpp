//============================================================================
// Name        : Linuxserver.cpp
// Author      : Galina Kothe
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Linuxserver in C++, Ansi-style
//============================================================================

#include <sys/types.h>
#include <sys/socket.h> // socket(), bind(), listen(), accept()
#include <netinet/in.h>
#include <stdio.h> //perror()
#include <string.h>
#include <stdlib.h> //exit()
#include <fstream> //close()
#include <arpa/inet.h>



using namespace std;



int main()
{
	
	int sock, listener;//socket fuer eine neue Verbindung, Socket fuers Hoeren
    struct sockaddr_in addr; // Info Adresse Serverseite
    struct sockaddr_in client_addr; // // Info Adresse Clientseite
    //const char *IP="192.168.21.128";
    char buf[1024]; // Buffer lesen
    int bytes_read;
    socklen_t sin_size; // Client Adresse Groeße
   // int len_buf; // Groeße der Gelesenen Nachricht, spaeter Große der Sendenachricht
    int yes = 1; // zum 2ten Starten des Servers

	
    // Erzeugen  eines Kommunikationspunktes
    listener = socket(AF_INET, SOCK_STREAM, 0);
	printf("socket()..");
    if(listener < 0)
    {// Fehler bei der Erzeugung des Sockets
        perror("socket"); 	printf("fehler socket()..");
        exit(1);
    }


    // Anbindung an die Port und IP-Adresse
    // Wenn der Port noch nicht zuruerck gegeben wurde: "Address alredy in use"
       if (setsockopt(listener,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) < 0)
          {
    	    close(listener);
          	perror("setsockopt"); printf("feh setsockopt()..");
          	    	exit(1);
          }
    
    memset(&addr, 0, sizeof(addr));//Zero
    addr.sin_family = AF_INET; // Internet Übertragung Host Byte Order
    addr.sin_port = htons(3424);// Portnummer: Host to Network Short
    addr.sin_addr.s_addr = htonl(INADDR_ANY);// meine IP adresse
    //addr.sin_addr.s_addr = inet_addr("192.168.21.130");// IP Home Linux
    //inet_aton("192.168.21.130", &( addr.sin_addr.s_addr));

    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        close(listener); //Handle wieder Schließen
        perror("bind");
        exit(2);
    }

    //Akzeptiere Verbindungsanfragen, queue limit = 1 nur für 1 Client in d
    // in der Warteschlange
    printf("listen()..");
    if(listen(listener, 10)<0)
    {
    	close(listener);
    	perror("listen");
    	exit(4);
    }

    printf("Server ist bereit: %s:%d\n", inet_ntoa(addr.sin_addr), htons(addr.sin_port));

    //============================================================
    // Verbindungsaufbau
    // ============================================================
    while(true){
    sin_size = sizeof(struct sockaddr_in);
    printf("accept()..");
    sock = accept(listener,(struct sockaddr *)&client_addr, (socklen_t*)&sin_size);
      if(sock < 0) // Fehlerkontrolle
     	 {
    	   perror("accept");
            exit(1);
         }

      	  while(1){
          bytes_read = recv(sock, buf, 1024, 0);
          // Hier kommt noch die Aufarbeitung der Nachricht
          	  if(bytes_read <= 0) break;
          send(sock, buf, bytes_read, 0);
          //len_buf = strlen(buf);//Später die Länge der nachricht
          //send(sock, buf,  len_buf, 0); //buf, was geschickt wird
      	  }

        close(sock);
     }

      return 0;
}
