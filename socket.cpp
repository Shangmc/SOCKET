#include<iostream>
#include<windows.h>
#include<Winsock2.h>
#pragma comment(lib,"Ws2_32.lib")
#include<stdio.h>
#include<memory.h>
#define QUEUE_SIZE 5
#define BUF_SIZE 100
using namespace std;
int main()
{
	WSAData wsd;
	WSAStartup(MAKEWORD(2,0),&wsd);
	SOCKET s=NULL;
    s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    struct sockaddr_in ch;
    memset (&ch,0,sizeof(ch));
    ch.sin_family=AF_INET;
    ch.sin_addr.s_addr=INADDR_ANY;
    ch.sin_port=htons(59152);
    int b=bind(s,(struct sockaddr*)&ch,sizeof(ch));
    int l=listen(s,QUEUE_SIZE);
    cout<<"���ڼ��������Ķ˿ڣ�"<<endl;
    SOCKET sc=accept(s,0,0);
    cout<<"�ͻ����Ѿ����ӵ������Ķ˿�"<<endl;
    int receByt=0;
    char buf1[64]="HELLOMYWORLDAB";
    //buf1[5]='A';
    //buf1[6]='B';
    while(1)
    {
    	char buf[BUF_SIZE];
    	receByt=recv(sc,buf,BUF_SIZE,0);

    	int nsend=send(sc,buf1,10,0);
    	//Sleep(10000);
    	buf[receByt]='\0';
    	if(receByt>0)
    		printf("���յ���Ϣ��:%s\n",buf);
    	else
    	{
    		printf("���յ���Ϣ������");
    		break;
    	}

    }
    int ic=closesocket(sc);
    int is=closesocket(s);

	}
