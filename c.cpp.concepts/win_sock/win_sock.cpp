// win_sock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "win_sock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

extern SOCKET hisr;
extern sockaddr_in local;

CWinApp theApp;

using namespace std;

NU_MEMORY_POOL  system_mem;

#define SERVER

#ifdef  SERVER
int _tmain(INT argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	/* Initialize MFC and print and error on failure. */
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
        /* Initialize CANopen. */
        CO_Initialize_Canopen(&system_mem);

		cout << "Press ESCAPE to terminate program\r\n";
		AfxBeginThread(ServerThread,THREAD_PRIORITY_NORMAL, 0, 0,NULL);
		while(_getch()!=27);

        /* Shutdown CANopen. */
        CAN_Close_Driver();

	}

	return nRetCode;

}


UINT  ServerThread(LPVOID pParam)
{

    /* Variable declarations for holding client information. */
    SOCKET        server, client=0;
    sockaddr_in   client_info;
    int           clietn_info_len = sizeof(client_info);
	
    /* Save the global socket for communication in local one. */
    server = hisr;

    printf("\nwaiting for some client.\n");

    /* Keep on running the server. */
    while(true)
    {
        char message[512];

        /* Accept an incoming client connection. */
        client=accept(server, (struct sockaddr*)&client_info, &clietn_info_len);

        if (client != 0 ) 
        {
            printf("client accepted.\n ");
        }
        else
        {
            printf("Connection not established.\n");
        }

        /* Write message for sending to the client. */
//        sprintf(message, "Welcome. May I help you?");
        sprintf(message,"Your IP is %s\r\n",inet_ntoa(client_info.sin_addr));
        send(client,message,strlen(message),0);

        printf("Hello user: should I close the connection with the client now?\n");
        char option;
        scanf("%c", &option);
        if (option == 'y')
        {
            sprintf(message,"Sending command to close the connection now.\n");
            send(client,message,strlen(message),0);

            /* Close the connection with this client. */
            closesocket(client);

            /* Waiting for some client. */
            printf("\nwaiting for some client.\n");

        }
		
    }

}

#else

int _tmain(INT argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		cout << "Press ESCAPE to terminate program\r\n";
        CO_Initialize_Canopen(&system_mem);
//		AfxBeginThread(ServerThread,THREAD_PRIORITY_NORMAL, 0, 0,NULL);
//		while(_getch()!=27);

        unsigned char data_msg[8];
//        char data_msg[8];
        data_msg[0] = 'A';
        data_msg[0] = 'B';
        data_msg[0] = 'C';
        data_msg[0] = 'D';
        data_msg[0] = 'E';

        //ServerThread(data_msg);
        while (_getch()!='a') 
        {
            CQM_Data_Request(0, 0x123, 8, data_msg);
        }

		while(_getch()!=27);

        CAN_Close_Driver();

	}

	return nRetCode;
}

#endif //server

//UINT  ServerThread(LPVOID pParam)
//UINT  ServerThread(CString data)
UINT  ServerThread(char data[8])
{	
#if 0
    cout << "Starting up TCP server\r\n";
	
    /* Declare a server socket. */
    SOCKET server;
	
    /* WSADATA is a struct that is filled up by the call to WSAStartup */
    WSADATA wsaData;
	
    /* The sockaddr_in specifies the address of the socket for TCP/IP sockets. */
    sockaddr_in local;
	
    /* Initialize the program for calling WinSock. */
    int status=WSAStartup(0x101,&wsaData);

    /* Exit if startup was un-successful. */
    if(status!=0)
    {
        return 0;
    }
	
    /* Fill in the sockaddr_in structure. */
    local.sin_family=AF_INET;                   /* Address family */
    local.sin_addr.s_addr=INADDR_ANY;           /* Wild card IP address */
    local.sin_port=htons((u_short)HISR_ADDR); /* port to use */
	
    /* Create the server socket with specified attributes. */
    server=socket(AF_INET,SOCK_STREAM,0);
	
    /* Exit the function if socket creation was unsucessful. */
    if(server==INVALID_SOCKET)
    {
        return 0;
    }
	
    /* Link the server socket with sockaddr_in structure so that 
       it recognises the addressa and port. */
    status = bind(server,(sockaddr*)&local,sizeof(local));

    /* Exit if socket linking was not successful. */
    if(status != 0)
    {
        return 0;
    }
	
        /* Configure the socket for listen mode. The server socket thus shall
       listen for the client messages. */
    status = listen(server, 10);

    /* Exit if socket mode configuration was not successful. */
    if(status != 0)
    {
        return 0;
    }
	
    /* Variable declarations for holding client information. */
    SOCKET        client;
    sockaddr_in   from;
    int fromlen = sizeof(from);
	
    /* Keep on running the server. */
//    while(true)
    {
        char message[512];
		
        /* Accept an incoming client connection. */
        client=accept(server, (struct sockaddr*)&from, &fromlen);

        /* Write message for sending to the client. */
//        sprintf(temp,"Your IP is %s\r\n",inet_ntoa(from.sin_addr));
        sprintf(message, "Welcome. May I help you?");
        send(client,message,strlen(message),0);

        /* Send the message to the client. */
//        send(client,data,strlen(data),0);

//        send(client, data, sizeof(data),0);
//        cout << "Connection from " << inet_ntoa(from.sin_addr) <<"\r\n";
		
        /* Close the connection with this client. */
        closesocket(client);
		
    }
	
    /* Close the server socket. */
    closesocket(server);
	
    /* Yerminate use of WS2_32.DLL */
    WSACleanup();
#endif //0	
    return 0;
    
}

UNSIGNED8 DisplayNodeState(VOID)
{
    UNSIGNED8 node_state;

    /* Find and display the local node state. */
    node_state = CO_Get_Local_Node_State();
    printf("The state of the local node is");

    switch(node_state)
    {
    case NM_PRE_OPERATIONAL:
        /* Set state to Pre-Operational */
        printf("PRE_OPERATIONAL\n");
        break;
        
    case NM_OPERATIONAL:
        /* Set state to Operational */
        printf("OPERATIONAL\n");
        break;
        
    case NM_STOPPED:
        /* Set state to Stopped */
        printf("STOPPED\n");
        break;

    default:
        /* None. */
        break;
        
    }

    return node_state;

}
