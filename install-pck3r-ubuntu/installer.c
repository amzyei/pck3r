#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

static void Pck3r_installer (GtkWidget *wid, GtkWidget *win){
  GtkWidget *dialog = NULL;

  dialog = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,
  "Pck3r installer\nthis program install pck3r on your,  oprating system . (UBUNTU or debian based) !");
  gtk_window_set_position (GTK_WINDOW (dialog), GTK_WIN_POS_CENTER);
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

static void install_pck3r (GtkWidget *wid, GtkWidget *win){
  GtkWidget *dialog_after_install = NULL;
    system("sudo cp -r ../pck3r /usr/bin/");
    system("echo pck3r copied ...");
    system("sudo cp -r ../pck3r-help /usr/bin/");
    system("echo pak3r-help copied ...");
    system("echo pck3r dependences ...");
    system("sudo apt install wget");
    system("sudo apt install curl");
    system("sudo apt install libgtk-3-dev");
    system("echo pck3r intalled !!!!!");
    system("sleep 5");
    dialog_after_install = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,
    "Pck3r installed!\n");
    gtk_window_set_position (GTK_WINDOW (dialog_after_install), GTK_WIN_POS_CENTER);
    gtk_dialog_run (GTK_DIALOG (dialog_after_install));
    gtk_widget_destroy (dialog_after_install);
    gtk_main_quit();
}

int main (int argc, char *argv[]){
  GtkWidget *button = NULL;
  GtkWidget *label = NULL;
  GtkWidget *win = NULL;
  GtkWidget *vbox = NULL;

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), "pck3r installer");
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);

  /* Create a vertical box with buttons */
  vbox = gtk_vbox_new (TRUE, 6);
  gtk_container_add (GTK_CONTAINER (win), vbox);

  button = gtk_button_new_with_label("install pack3r");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (install_pck3r), (gpointer) win);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  button = gtk_button_new_from_stock (GTK_STOCK_DIALOG_INFO);
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (Pck3r_installer), (gpointer) win);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  button = gtk_button_new_from_stock (GTK_STOCK_CLOSE);
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  /* Enter the main loop */
  gtk_widget_show_all (win);
  gtk_main ();
  return 0;
}
