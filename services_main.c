#include<stdio.h>
#include<gtk/gtk.h>
#include<string.h>
#define SYSTEM_SERVICES 46
static int no_of_services;
typedef struct file_info
{	
	
	char service_name[30];
	int runlevel[7];
	GtkWidget *button[7];
	GtkWidget *box;
	GtkWidget *label;
}service_info;
final_change(GtkWidget *window,service_info *service)
{	

	printf("%s",service[0].service_name);
	int i=no_of_services;
	FILE *fp=fopen("log.txt","w");
	int j;
	fprintf(fp,"%d \n",i);
	for(j=0;j<i;j++)
	{
		fprintf(fp,"%s %d %d %d %d %d %d %d\n",service[j].service_name,(*(service+j)).runlevel[0],(*(service+j)).runlevel[1],(*(service+j)).runlevel[2],(*(service+j)).runlevel[3],(*(service+j)).runlevel[4],(*(service+j)).runlevel[5],(*(service+j)).runlevel[6]);
	}
	fclose(fp);
	system("./update.sh");
	gtk_main_quit();
}
cb(GtkWidget *w,int *i)
{

	char *label;
	label=(char *)gtk_button_get_label(GTK_BUTTON(w));
	if(!strcmp(label,"on"))
	{
		
		*i=0;
		gtk_button_set_label(GTK_BUTTON(w),"off");
	
	}
	else
	{
	
		*i=1;
		gtk_button_set_label(GTK_BUTTON(w),"on");
	}
}
set_view(service_info *service,GObject *box)
{
	int j=0;
	(*service).label=gtk_label_new((*service).service_name);
	(*service).box=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
	gtk_box_pack_start(GTK_BOX((*service).box),GTK_WIDGET((*service).label),1,1,1);
	
	for(j=0;j<7;j++)
	{
		(*service).button[j]=gtk_button_new_with_label("NA");
		if((*service).runlevel[j]==0)
		{
			gtk_button_set_label(GTK_BUTTON((*service).button[j]),"off");
		}
		else
		{
			gtk_button_set_label(GTK_BUTTON((*service).button[j]),"on");
		}				
		g_signal_connect((*service).button[j],"clicked",G_CALLBACK(cb),&(*service).runlevel[j]);
		gtk_box_pack_start(GTK_BOX((*service).box),GTK_WIDGET((*service).button[j]),0,0,0);
	}
		gtk_box_pack_start(GTK_BOX(box),GTK_WIDGET((*service).box),0,0,0);
}
int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);
	system("./get_pass");
	system("./initial.sh");
	FILE *fp=fopen("log.txt","r");
	int i;
	fscanf(fp,"%d",&no_of_services);
	no_of_services=no_of_services-SYSTEM_SERVICES;
	service_info service[no_of_services];
	GtkBuilder *builder;
	builder=gtk_builder_new();
	gtk_builder_add_from_file(builder,"drama.glade",NULL);
	GObject *box,*window1;
	box=gtk_builder_get_object(builder,"box2");
	window1=gtk_builder_get_object(builder,"applicationwindow1");
	for(i=0;i<no_of_services;i++)
	{
		fscanf(fp,"%s %d %d %d %d %d %d %d",service[i].service_name,&service[i].runlevel[0],&service[i].runlevel[1],&service[i].runlevel[2],&service[i].runlevel[3],&service[i].runlevel[4],&service[i].runlevel[5],&service[i].runlevel[6]);
		set_view(&service[i],box);
	}
	fclose(fp);
	
	g_signal_connect (window1, "destroy", G_CALLBACK (final_change), &service[0]);
	gtk_widget_show_all(GTK_WIDGET(box));
	gtk_main();
}


