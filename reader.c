#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>


typedef struct msg_buffer {
	long msg_type;
	char msg_text[100];
} buffer;

int main()
{
	int msgid = msgget(137, IPC_CREAT | 0666);
	buffer message;

	printf("Messsage receiving from message queue..\n");
	msgrcv(msgid, &message, sizeof(message), 1, 0);

	printf("Message recieved: %s\n", message.msg_text);
	return 0;
}
