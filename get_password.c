#include<stdio.h>
#include<gtk/gtk.h>
#include<string.h>
print_to_file(const char *text)
{
	char c;
	int i=0;
	FILE *fp;
	fp=fopen("password.txt","w");
	int len=strlen(text);
	for(i=0;i<=c;i++)
	{
		c=text[i];
		fprintf(fp,"%c",c);
	}
	fclose(fp);
}
pass_cb(GtkWidget *button,GtkBuilder *builder)
{
	GObject *entry1;
	const char *entry_text;
	entry1=gtk_builder_get_object(builder,"entry1");
	entry_text = gtk_entry_get_text (GTK_ENTRY(entry1));
	print_to_file(entry_text);
	gtk_main_quit();
}
main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);
	GObject *button1;
	GtkBuilder *builder_password;
	builder_password=gtk_builder_new();
	gtk_builder_add_from_file(builder_password,"password.glade",NULL);
	button1=gtk_builder_get_object(builder_password,"button1");
	g_signal_connect(GTK_WIDGET(button1),"clicked",G_CALLBACK(pass_cb),builder_password);
	gtk_main();
}		
