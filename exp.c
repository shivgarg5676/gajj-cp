#include<stdio.h>
#include<gtk/gtk.h>
#include<unistd.h>
#include<string.h>
#include"git_callback.c"
#include"system_callback.c"
#include"services_callback.c"
int main(int argc,char *argv[])
{

	GtkBuilder *builder;	
	GObject *window,*button1,*button2,*button3;
	gtk_init(&argc,&argv);
	builder = gtk_builder_new ();
         gtk_builder_add_from_file (builder, "main.glade", NULL);
         button1=gtk_builder_get_object(builder,"button1");
         button2=gtk_builder_get_object(builder,"button2");
         button3=gtk_builder_get_object(builder,"button3");
         window=gtk_builder_get_object(builder,"window1");
         g_signal_connect (button1, "clicked", G_CALLBACK (services_callback), NULL);
         g_signal_connect (button2, "clicked", G_CALLBACK (git_callback), NULL);
         g_signal_connect (button3, "clicked", G_CALLBACK (system_callback), NULL);
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	gtk_main();
	
}

