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

	message.msg_type = 1;
	printf("Write some data: ");
	fgets(message.msg_text, 100, stdin);

	msgsnd(msgid, &message, sizeof(message), 0);

	printf("Message written in the message queue!!!\n");
	return 0;
}
