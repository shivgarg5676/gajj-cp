recipe()
{

	
}
void* fun1(void* l)
{
	GtkBuilder *builder_spinner1;
	builder_spinner1=l;
	GObject	*spinner,*progress_bar,*window3;
	window3=gtk_builder_get_object(builder_spinner1,"applicationwindow1");
	progress_bar=gtk_builder_get_object(builder_spinner1,"progressbar1");
	spinner=gtk_builder_get_object(builder_spinner1,"spinner1");
	double fraction=0;	
	int i;
	const char *value = "failed",*value1="downloading cpomplete",*value0="processing.....";
	FILE *tp;
	
	for(;;)
	{
	tp=fopen("shiv1.txt","r");
	fscanf(tp,"%d",&i);
	fclose(tp);
	
	if(i==2)
	{
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress_bar),value0);
		g_print("shiv");
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar),fraction);
		if(fraction>0.75)
		{
			fraction=fraction/3;
		}
		else
		{
			fraction=fraction+0.02;
		}
		
	}
	else
	{	
	if(i>0)
	{
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress_bar),value);
		gtk_widget_destroy(GTK_WIDGET(spinner));	
	
	}
	else
	{
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress_bar),value1);
		fraction=1.0;
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress_bar),fraction);
		//gtk_widget_destroy(GTK_WIDGET(spinner));
		recipe(builder_spinner1);	
	
	}
	break;
	}
	sleep(5);
	}	
	

}


print_to_file(const char *text)
{
	char c;
	int i=0;
	FILE *fp;
	fp=fopen("shiv.txt","w");
	int len=strlen(text);
	for(i=0;i<=c;i++)
	{
		c=text[i];
		fprintf(fp,"%c",c);
	}
	fclose(fp);
}
int window_count[3]={};
mohit(GtkWidget *button, GtkBuilder *builder2)
{
	int return_status;
	GObject *entry1,*window1;
	const char *entry_text;
	entry1=gtk_builder_get_object(builder2,"entry1");
	window1=gtk_builder_get_object(builder2,"window1");
	entry_text = gtk_entry_get_text (GTK_ENTRY(entry1));
	printf("Entry contents: %s\n", entry_text);
	print_to_file(entry_text);
	GtkBuilder *builder_spinner;
	builder_spinner=gtk_builder_new();
	gtk_builder_add_from_file(builder_spinner,"spinner.glade",NULL);
	gtk_entry_set_text (GTK_ENTRY(entry1)," ");
	gtk_widget_destroy(GTK_WIDGET(window1));
	FILE *tpp;
	tpp=fopen("shiv1.txt","w");
	fprintf(tpp,"2");
	fclose(tpp);	
	pid_t pid=fork();
	if(!pid)
	{
		execl("git.sh","git.sh",NULL);
		
	}
	if(pid!=0)
	{
			pthread_t thread1;
			pthread_create(&thread1,NULL,fun1,builder_spinner);
		
	}
	
	
		
		
	}

void git_callback()
{
	GtkBuilder *builder1;
	GObject *entry,*button_entry;
	builder1 = gtk_builder_new ();
        gtk_builder_add_from_file (builder1, "text_entry_git.glade", NULL);
        button_entry=gtk_builder_get_object(builder1,"button1");
        g_signal_connect (button_entry, "clicked", G_CALLBACK (mohit),builder1);
}
