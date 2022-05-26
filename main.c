// leetxi v0.0.5

/*

A project to configure and launch ffxi in linux through ashita
while utilizing reshade and dgvoodoo2

Copyright (C) 2022  Juna Rachelle

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA*/

// Headers

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

// Random Variables
    char              textlab[64];
    char              aboutlab[100];

// Widgets
    GtkWidget *image;
    GtkWidget *fpath;
    GtkWidget *window;
    GtkWidget *vertbox;
    GtkWidget *checkwin;
    GtkWidget *checkwinbox;
    GtkWidget *textstuff;
    GtkWidget *pokeme;
    GtkWidget *toolbar;
    GtkWidget *menu;
    GtkWidget *filemenu;
    GtkWidget *filesubmenu;
    GtkWidget *aboutmenu;
    GtkWidget *aboutsubmenu;
    GtkWidget *closeswitch;
    GtkWidget *aboutswitch;
    GtkWidget *dgv;
    GtkWidget *xiconf;
    GtkWidget *ashconf;
    GtkWidget *dialog;

// Events
static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
   return FALSE;
}

static void destroy( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
}

//Launch
static void launch ( GtkWidget *wid, GtkWidget *win )
{
  char *const args[] = {"/usr/bin/sh","/opt/ffxi/launchxi"};
  pid_t pid = fork() ;

  if (pid == 0)
  {
	  execv(args[0],args);
  }else{
        wait(pid);
        exit(0);
    }
}

//dgVoodoo2 config
static void dgvconfig ( GtkWidget *wid, GtkWidget *win )
{
  char *const args[] = {"/usr/bin/sh","/opt/ffxi/configdgv"};
  pid_t pid = fork() ;

  if (pid == 0)
  {
	  execv(args[0],args);
  }else{
        wait(pid);
        exit(0);
    }
}
//FFXI config
static void xiconfig ( GtkWidget *wid, GtkWidget *win )
{
  char *const args[] = {"/usr/bin/sh","/opt/ffxi/configxi"};
  pid_t pid = fork() ;

  if (pid == 0)
  {
	  execv(args[0],args);
  }else{
        wait(pid);
        exit(0);
    }
}

//Ashita config
static void ashconfig ( GtkWidget *wid, GtkWidget *win )
{
  char *const args[] = {"/usr/bin/sh","/opt/ffxi/configash"};
  pid_t pid = fork() ;

  if (pid == 0)
  {
	  execv(args[0],args);
  }else{
        wait(pid);
        exit(0);
    }
}

// About Menu Item
static void aboutit (GtkWidget *wid, GtkWidget *win)
{
  GtkWidget *dialog = NULL;
  sprintf(aboutlab,"%s", "LeetXI\n\n""Version 0.0.5\n""An Ashita Linux Launcher\n""because its about time...\n""see our githubpage:\n""https://github.com/BlackstarLuna/leetxi\n");
  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, aboutlab);
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

// Main Function
int main( int   argc, char *argv[] )
{

// Build the main window
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "LeetXI");
    g_signal_connect (G_OBJECT (window), "delete_event", G_CALLBACK (delete_event), NULL);
    g_signal_connect (G_OBJECT (window), "destroy", G_CALLBACK (destroy), NULL);
    gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width (GTK_CONTAINER (window), 2);

// Slap on a container
    vertbox = gtk_vbox_new (FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vertbox);

// Menu
    menu = gtk_menu_bar_new();
    filemenu = gtk_menu_item_new_with_label("Configs");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), filemenu);
    aboutmenu = gtk_menu_item_new_with_label("About");
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), aboutmenu);
    gtk_box_pack_start (GTK_BOX (vertbox), menu, TRUE, TRUE, 0);
    filesubmenu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(filemenu), filesubmenu);
    dgv = gtk_menu_item_new_with_label("DGVoodoo2 config");
    gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu), dgv);
    g_signal_connect(dgv, "activate", G_CALLBACK(dgvconfig), NULL);
    xiconf = gtk_menu_item_new_with_label("FFXI config");
    gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu), xiconf);
    g_signal_connect(xiconf, "activate", G_CALLBACK(xiconfig), NULL);
    ashconf = gtk_menu_item_new_with_label("Ashita config");
    gtk_menu_shell_append(GTK_MENU_SHELL(filesubmenu), ashconf);
    g_signal_connect(ashconf, "activate", G_CALLBACK(ashconfig), NULL);
    gtk_widget_realize(window);
    aboutsubmenu = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(aboutmenu), aboutsubmenu);
    aboutswitch = gtk_menu_item_new_with_label("About LeetXI");
    gtk_menu_shell_append(GTK_MENU_SHELL(aboutsubmenu), aboutswitch);
    g_signal_connect(aboutswitch, "activate", G_CALLBACK(aboutit), NULL);

// Image 
    image = gtk_image_new_from_file("/opt/ffxi/ffxi.png");
    gtk_container_add(GTK_CONTAINER (vertbox), image);

// Text
    sprintf(textlab, "%s", "\n\n<big><b>LeetXI</b></big>\n\n");
    textstuff = gtk_label_new (NULL);
    gtk_label_set_markup(GTK_LABEL (textstuff), textlab);
    gtk_label_set_justify(GTK_LABEL (textstuff),GTK_JUSTIFY_CENTER);
    gtk_misc_set_alignment (GTK_MISC (textstuff), 0.5, 0.5);
    gtk_box_pack_start (GTK_BOX (vertbox), textstuff, TRUE, TRUE, 0);

// Launch Button
    pokeme = gtk_button_new_from_stock ("Launch LeetXI");
    g_signal_connect (G_OBJECT (pokeme), "clicked", G_CALLBACK (launch), (gpointer) window);
    gtk_box_pack_start (GTK_BOX (vertbox), pokeme, TRUE, TRUE, 0);

// Quit Button
    pokeme = gtk_button_new_from_stock ("Quit LeetXI");
    g_signal_connect (G_OBJECT (pokeme), "clicked", G_CALLBACK (gtk_main_quit), (gpointer) window);
    gtk_box_pack_start (GTK_BOX (vertbox), pokeme, TRUE, TRUE, 0);

// Shove it all together and make it go weeeeeeeeeee
    gtk_container_add (GTK_CONTAINER (window), vertbox);

    gtk_widget_show_all(window);

    gtk_main ();

    return 0;
}
