services_callback()
{
	pid_t pid_ser=fork();
	if(pid_ser==0)
	{	
		execl("/home/shiv/Desktop/gajj-cp/hello","/home/shiv/Desktop/gajj-cp/hello",NULL);
	}
			
}
