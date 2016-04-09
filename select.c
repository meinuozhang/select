#include<stdio.h>
#include<string.h>
#include<sys/select.h>
#include<errno.h>
int main()
{
	int read_fd=0;
	int write_fd=1;
	int max_fd=0;
	fd_set read_set;
	fd_set write_set;
	while(1)
	{
	struct timeval timeout={5,0};
	FD_ZERO(&read_set);
	FD_SET(read_fd,&read_set);
	FD_ZERO(&write_set);
	FD_SET(write_fd,&write_set);
	switch(select(max_fd+1,&read_set,&write_set,NULL,&timeout))
	{
		case 0://timeout
        printf("select timeout\n");
		  break;
		case -1://error
		printf("select error\n");
		  break;
		default://data ready
		 // printf("select\n");
		  if(FD_ISSET(read_fd,&read_set))
		  {
			  char buf[1024];
			  memset(buf,'\0',sizeof(buf));
			  ssize_t _size=read(0,buf,sizeof(buf)-1);
			  if(_size>0)
			  {
				  printf("echo:%s",buf);
			  }
		  }
		  break;
    }
	}
	return 0;
}
